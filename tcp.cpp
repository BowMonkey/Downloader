
#include"downloader.h"

//建立tcp连接
int tcp_connect(char * hostname, int port)
{
	assert(hostname != nullptr);

	int sockfd;
	struct hostent *host = NULL;
	struct sockaddr_in servaddr;

	if((host = gethostbyname(hostname)) == NULL)
	{
		return -1;
	}


	if((sockfd = socket(AF_INET, SOCK_STREAM, 0)) < 0)
	{
		return -1;
	}

	bzero(servaddr, sizeof(servaddr));
	servaddr.sin_family = AF_INET;
	servaddr.sin_port = htons(port);
	servaddr.sin_addr = *((struct in_addr *) host->h_addr_list);

	if(connect(sockfd, (SA *)&servaddr, sizeof(servaddr)) < 0)
	{
		close(sockfd);
		return -1;
	}

	return sockfd;
}