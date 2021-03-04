#include "SocketProcess.h"
#include <sys/socket.h>
#include <netinet/in.h>
#include <string.h>
#include <arpa/inet.h>
#include <stdlib.h>

uint16_t conn_soc_serv_via_tcp(uint16_t *sock, uint8_t *add, uint16_t port){
    struct sockaddr_in serv_addr;

    //Create socket
    if ((*sock = socket(AF_INET, SOCK_STREAM, 0)) < 0)
    {
        printf("Socket network creation error\n");
        return -1;
    }
    memset(&serv_addr, '0', sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_port = htons(port);

    // Convert IPv4 and IPv6 address from text to binary form
    if(inet_pton(AF_INET, add, &serv_addr.sin_addr) <= 0)
    {
        printf("Invalid address/Address not supported\n");
        return -1;
    }

    //Connect to socket server
    if (connect(*sock, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) < 0)
    {
        printf("Connection to server failed\n");
        return -1;
    }
    return 0;
}


uint16_t conn_soc_serv_via_udp(uint16_t *sock, uint8_t *add, uint16_t port){
    struct sockaddr_in serv_addr;

    //Create socket
    if ((*sock = socket(AF_INET, SOCK_DGRAM, IPPROTO_UDP)) < 0)
    {
        printf("Socket network creation error\n");
        return -1;
    }
    memset(&serv_addr, '0', sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_port = htons(port);

    // Convert IPv4 and IPv6 address from text to binary form
    if(inet_pton(AF_INET, add, &serv_addr.sin_addr) <= 0)
    {
        printf("Invalid address/Address not supported\n");
        return -1;
    }

    return 0;
}

uint16_t create_soc_serv_via_tcp(uint16_t *sock, uint16_t port){
	struct sockaddr_in serv_addr;

	//Create socket
	if ((*sock = socket(AF_INET, SOCK_STREAM, 0)) < 0)
	{
		printf("Socket network creation error\n");
		return -1;
	}
	memset(&serv_addr, '0', sizeof(serv_addr));
	serv_addr.sin_family = AF_INET;
	serv_addr.sin_port = htons(port);
	serv_addr.sin_addr.s_addr = htonl(INADDR_ANY);

	//bind socket to port
	if (bind(*sock, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) < 0)
	{
		printf("Create Socket TCP server failed \n");
		return -1;
	}
	return 0;
}

uint16_t create_soc_serv_via_udp(uint16_t *sock, uint16_t port){
	struct sockaddr_in serv_addr;

	//Create socket
	if ((*sock = socket(AF_INET, SOCK_DGRAM, IPPROTO_UDP)) < 0)
	{
		printf("Socket creation error\n");
		return -1;
	}
	memset(&serv_addr, '0', sizeof(serv_addr));
	serv_addr.sin_family = AF_INET;
	serv_addr.sin_port = htons(port);
	serv_addr.sin_addr.s_addr = htonl(INADDR_ANY);

	//bind socket to port
	if (bind(*sock, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) < 0)
	{
		printf("Create Socket UDP server failed\n");
		return -1;
	}
	return 0;
}

void close_socket_net(uint16_t *sock){
    close(*sock);
}

uint16_t send_buff_to_serv(uint16_t *sock, uint8_t *sendBuff){
	uint16_t ok = send(*sock, sendBuff, strlen(sendBuff), 0);
	if(ok <= 0) return -1;
	return 0;
}

uint16_t send_file_to_serv(uint16_t *sock, FILE*file, uint16_t len){
	uint8_t *sendBuff = (uint8_t*)malloc(1);
	fread(sendBuff, len, 1, file);
	uint16_t ok = send(*sock, sendBuff, strlen(sendBuff), 0);
	if(ok <= 0){
		return -1;
	}
	free(sendBuff);
	return 0;
}

uint16_t recv_to_buff(uint16_t *sock, uint8_t *recBuff, uint16_t len){
    uint16_t ok = recv(*sock , recBuff, len, 0);
    if(ok <= 0) return -1;
    return 0;
}

uint16_t recv_to_file(uint16_t *sock, FILE* file, uint16_t len){
	uint8_t *recBuff = (uint8_t*)malloc(1);
	uint16_t ok = recv(*sock , recBuff, len, 0);
	if(ok <= 0){
		return -1;
	}
    fwrite(recBuff, strlen(recBuff), 1, file);
    free(recBuff);
    return 0;

}

uint16_t socket_service_init(){
	uint16_t sock;
	if (SERV){
		if (PROTOCOL_USE == PROTOCOL_TCP){
			uint16_t ok = create_soc_serv_via_tcp(&sock, PORT);
			if(ok < 0) return -1;
			return sock;
		}else if(PROTOCOL_USE == PROTOCOL_UDP){
			uint16_t ok = create_soc_serv_via_udp(&sock, PORT);
			if(ok < 0) return -1;
			return sock;
		}
	}else{
		if (PROTOCOL_USE == PROTOCOL_TCP){
			uint16_t ok = conn_soc_serv_via_tcp(&sock, ADDR_TO_CONN, PORT);
			if(ok < 0) return -1;
			return sock;
		}else if(PROTOCOL_USE == PROTOCOL_UDP){
			uint16_t ok = conn_soc_serv_via_udp(&sock, ADDR_TO_CONN, PORT);
			if(ok < 0) return -1;
			return sock;
		}
	}
}

uint16_t socket_wrt_recv_data_to_file(uint16_t *sock, uint8_t *fileName, uint8_t *rw, uint16_t len){
	FILE *f = fopen(fileName, rw);
	uint16_t ok = recv_to_file(sock, f, len);
	if(ok < 0){
		return -1;
	}
	fclose(f);
	return 0;
};

void* Socket_Thread(void* arvg){
    return NULL;
}