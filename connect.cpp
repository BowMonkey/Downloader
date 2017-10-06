
#include"downloader.h"


//初始化一个conn_t变量
int conn_init(conn_t * conn)
{
	return 0;
}

//解析URL，配置一个conn_t结构体
int conn_set(conn_t * conn, char * set_url)
{
	return 0;
}
//解析URL，生成URL字符串
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
//接收文件
int conn_exec(conn_t * conn)
{
	return 0;
}
//获取文件大小和其他信息，根据http返回码（404 . 300 等）1.处理重定向 2.获取文件大小和是否支持多链接
int conn_info(conn_t * conn)
{
	return 0;
}
