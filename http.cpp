#include "http.h"

int http_connect(http_t * conn, int proto, char * proxy, char * host, int port, char * user, char * pass)
{
	return 0;
}

void http_disconnect(http_t * conn)
{
	if(conn->filefd > 0)
	{
		close(conn->filefd);
	}
	conn->filefd = -1;
}

void http_get(http_t * conn, char * lurl)
{

}

void http_addheader(http_t * conn, char * format, ...)
{
}

int http_exec(http_t * conn)
{
	return 0;
}

char * http_header(http_t * conn, char * header)
{
	return nullptr;
}

int http_size(http_t * conn)
{
	return 0;
}

void http_encode(char * s)
{
}

void http_decode(char * s)
{
}
