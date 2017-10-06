#pragma once

#ifndef HTTP_H
#define HTTP_H

/*
http.h定义了http连接需要用到的一些函数
*/

#include "downloader.h"

//这个结构体定义了一个http下载对象
typedef struct 
{
	char host[MAX_STRING];        //下载服务器的主机名（主机名 或者 主机名：端口值）
	char auth[MAX_STRING];        //为http验证信息,用来生成http头中的验证信息,其中user和pass都是根据输入的URL地址来解析的
	char request[MAX_QUERY];      //http请求的请求缓冲区
	char headers[MAX_QUERY];      //存储http响应消息的缓冲区
	int firstbyte;                //下载的起始偏移
	int lastbyte;                 //下载的结束偏移
	int status;                   //http请求的返回码
	int filefd;                   //该http对应的连接的写文件的文件描述符
	char *local_if;               //绑定的本地ip
} http_t;

int http_connect(http_t * conn, char * host, int port, char * user, char * pass);
void http_disconnect(http_t *conn);
void http_get(http_t *conn, char *lurl);
void http_addheader(http_t *conn, char *para,...);
int http_exec(http_t *conn);
char *http_header(http_t *conn, char *header);
int http_size(http_t *conn);
void http_encode(char *s);
void http_decode(char *s);


#endif // !HTTP_H


