#pragma once

#ifndef HTTP_H
#define HTTP_H

/*
http.h������http������Ҫ�õ���һЩ����
*/

#include "downloader.h"

//����ṹ�嶨����һ��http���ض���
typedef struct 
{
	char host[MAX_STRING];        //���ط��������������������� ���� ���������˿�ֵ��
	char auth[MAX_STRING];        //Ϊhttp��֤��Ϣ,��������httpͷ�е���֤��Ϣ,����user��pass���Ǹ��������URL��ַ��������
	char request[MAX_QUERY];      //http��������󻺳���
	char headers[MAX_QUERY];      //�洢http��Ӧ��Ϣ�Ļ�����
	int firstbyte;                //���ص���ʼƫ��
	int lastbyte;                 //���صĽ���ƫ��
	int status;                   //http����ķ�����
	int filefd;                   //��http��Ӧ�����ӵ�д�ļ����ļ�������
	char *local_if;               //�󶨵ı���ip
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


