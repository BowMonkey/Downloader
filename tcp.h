#pragma once
#ifndef TCP_H
#define TCP_H


/*
tcp.h �����˽���tcp������Ҫ�õ��ĺ���
*/

//����tcp����, �󶨱��ص�ַΪlocal_if
int tcp_connect(char *hostname, int port, char *local_if);
//��ȡiface�ĵ�ַ
int get_if_ip(char *iface, char *ip);




#endif // !TCP_H

