
#include"downloader.h"


//��ʼ��һ��conn_t����
int conn_init(conn_t * conn)
{
	return 0;
}

//����URL������һ��conn_t�ṹ��
int conn_set(conn_t * conn, char * set_url)
{
	return 0;
}
//����URL������URL�ַ���
char * conn_url(conn_t * conn)
{
	return nullptr;
}

void conn_disconnect(conn_t * conn)
{
	http_disconnect(conn->http);
	conn->fd = -1;
}


int conn_setup(conn_t * conn)
{
	return 0;
}
//�����ļ�
int conn_exec(conn_t * conn)
{
	return 0;
}
//��ȡ�ļ���С��������Ϣ������http�����루404 . 300 �ȣ�1.�����ض��� 2.��ȡ�ļ���С���Ƿ�֧�ֶ�����
int conn_info(conn_t * conn)
{
	return 0;
}
