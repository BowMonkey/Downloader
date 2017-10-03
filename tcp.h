#pragma once
#ifndef TCP_H
#define TCP_H


/*
tcp.h 定义了建立tcp连接需要用到的函数
*/

//建立tcp连接, 绑定本地地址为local_if
int tcp_connect(char *hostname, int port, char *local_if);
//获取iface的地址
int get_if_ip(char *iface, char *ip);




#endif // !TCP_H

