#include "downloader.h"

int http_connect(http_t * conn, char * host, int port, char * user, char * pass)
{

	return 0;
}
//断开连接
void http_disconnect(http_t * conn)
{
	if(conn->filefd > 0)
	{
		close(conn->filefd);
	}
	conn->filefd = -1;
}

//把GET命令加到conn->request，同时加上其他的设定，譬如权限认证、传输起点和终点。
void http_get(http_t * conn, char * lurl)
{
	memset(conn->request, 0, sizeof(conn->request));
	http_addheader(conn, "GET %s HTTP/1.0", lurl);
	http_addheader(conn, "Host: %s", conn->host);
	http_addheader(conn, "User-Agent: %s", "Mozilla/5.0 (Windows NT 10.0; Win64; x64) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/61.0.3163.100 Safari/537.36");
	if(*conn->auth)
		http_addheader(conn, "Authorization: Basic %s", conn->auth);
	if(conn->firstbyte)
	{
		if(conn->lastbyte)
			http_addheader(conn, "Range: bytes=%i-%i", conn->firstbyte, conn->lastbyte);
		else
			http_addheader(conn, "Range: bytes=%i-", conn->firstbyte);
	}
}

//把相应的命令对应的格式加到conn->request上，等下将会发送出去。
void http_addheader(http_t * conn, char * para, ...)
{
	char s[MAX_STRING];
	va_list params;

	va_start(params, format);
	vsnprintf(s, MAX_STRING - 3, format, params);
	strcat(s, "\r\n");
	va_end(params);

	strncat(conn->request, s, MAX_QUERY);
}
//把conn->request发送出去
int http_exec(http_t * conn)
{
	int i = 0;
	char str[2] = " ";
	char *str2;

	http_addheader(conn, "");
	write(conn->filefd, conn->request, strlen(conn->request));

	*conn->headers = 0;

	/* Read the headers byte by byte to make sure we don't touch the
	actual data							*/
	while(1)
	{
		if(read(conn->filefd, str, 1) <= 0)
		{
			sprintf(conn->request, ("Connection gone.\n"));
			return(0);
		}
		if(*str == '\r')
		{
			continue;
		}
		else if(*str == '\n')
		{
			if(i == 0)
				break;
			i = 0;
		}
		else
		{
			i++;
		}
		strncat(conn->headers, str, MAX_QUERY);
	}

	sscanf(conn->headers, "%*s %3i", &conn->status);
	str2 = strchr(conn->headers, '\n'); *str2 = 0;
	strcpy(conn->request, conn->headers);
	*str2 = '\n';

	return(1);
	return 0;
}

char * http_header(http_t * conn, char * header)
{
	char s[32];
	int i;

	for(i = 1; conn->headers[i]; i++)
		if(conn->headers[i - 1] == '\n')
		{
			sscanf(&conn->headers[i], "%31s", s);
			if(strcasecmp(s, header) == 0)
				return(&conn->headers[i + strlen(header)]);
		}

	return(NULL);
}

int http_size(http_t * conn)
{
	char *i;
	int j;

	if((i = http_header(conn, "Content-Length:")) == NULL)
		return(-2);

	sscanf(i, "%i", &j);
	return(j);
}

/* Decode%20a%20file%20name						*/
void http_decode(char *s)
{
	char t[MAX_STRING];
	int i, j, k;

	for(i = j = 0; s[i]; i++, j++)
	{
		t[j] = s[i];
		if(s[i] == '%')
			if(sscanf(s + i + 1, "%2x", &k))
			{
				t[j] = k;
				i += 2;
			}
	}
	t[j] = 0;

	strcpy(s, t);
}

void http_encode(char *s)
{
	char t[MAX_STRING];
	int i, j;

	for(i = j = 0; s[i]; i++, j++)
	{
		t[j] = s[i];
		if(s[i] == ' ')
		{
			strcpy(t + j, "%20");
			j += 2;
		}
	}
	t[j] = 0;

	strcpy(s, t);
}