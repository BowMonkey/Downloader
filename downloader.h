#pragma once
#ifndef DOWNLOADER_H
#define DOWNLOADER_H

#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<unistd.h>
#include<arpa/inet.h>
#include<sys/socket.h>
#include<netdb.h>
#include<assert.h>
#include<stdarg.h>
#include<regex>


#define MAX_QUERY	    2048		//���������
#define MAX_STRING		256         //����������Դ����



#include"connect.h"
#include"http.h"
#include"tcp.h"


#endif // !DOWNLOADER_H

