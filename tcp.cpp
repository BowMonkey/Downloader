
#include"downloader.h"


int tcp_connect(char * hostname, int port, char *local_if)
{
	assert(hostname == nullptr);

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

	if(local_if && *local_if)
	{
		local.sin_family = AF_INET;
		local.sin_port = 0;
		local.sin_addr.s_addr = inet_addr(local_if);
		if(bind(fd, (struct sockaddr *) &local, sizeof(struct sockaddr_in)) < 0)
		{
			close(fd);
			return(-1);
		}
	}


	bzero(servaddr, sizeof(servaddr));
	servaddr.sin_family = AF_INET;
	servaddr.sin_port = htons(port);
	servaddr.sin_addr = *((struct in_addr *) host->h_addr_list);

	if(connect(sockfd, (struct sockaddr *)&servaddr, sizeof(servaddr)) < 0)
	{
		close(sockfd);
		return -1;
	}

	return sockfd;
}

int get_if_ip(char * iface, char * ip)
{
	struct ifreq ifr;
	int sockfd = socket(AF_INET, SOCK_DGRAM, IPPROTO_IP);

	memset(&ifr, 0, sizeof(ifr));

	strcpy(ifr.ifr_name, iface);
	ifr.ifr_addr.sa_family = AF_INET;
	if(ioctl(sockfd, SIOCGIFADDR, &ifr) == 0)
	{
		struct sockaddr_in *x = (struct sockaddr_in *) &ifr.ifr_addr;
		strcpy(ip, inet_ntoa(x->sin_addr));
		return(1);
	}
	else
	{
		return(0);
	}
}