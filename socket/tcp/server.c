/*
 * Copyright (c) 2014.  lin_jie_long@126.com, Sat 14 Mar 2015 11:18:16 AM CST,  All rights reserved.
 */
/*
 * File Name:  server.c
 * Author:     Vanqusier(lin_jie_long@126.com)
 * EMail:      lin_jie_long@126.com
 */

#include <stdio.h>
#include <>

int main(int argc, char *argv[])
{
	int sockfd, new_fd;
	struct sockaddr_in server_addr;
	struct sockaddr_in client_addr;
	
	socket();
	bind();
	connect();

	send();
	receive();
}
