#ifndef __SOCKETPROCESS_H__
#define __SOCKETPROCESS_H__
#include <stdint.h>
#include <stdio.h>

//-------------socket-----------//
#define PORT    					3333
#define ADDR_TO_CONN     			"192.168.93.171"

#define SERV   						0
#define CLNT   						!SERV

#define PROTOCOL_UDP				0
#define PROTOCOL_TCP				1
#define PROTOCOL_USE				PROTOCOL_TCP

#define RECV_DATA_MAXLEN 			1024
#define SEND_DATA_MAXLEN            1024

extern uint16_t send_buff_to_serv(uint16_t *sock, uint8_t *sendBuff);
extern uint16_t send_file_to_serv(uint16_t *sock, FILE*file, uint16_t len);
extern uint16_t recv_to_buff(uint16_t *sock, uint8_t *recBuff, uint16_t len);
extern uint16_t recv_to_file(uint16_t *sock, FILE* file, uint16_t len);
extern uint16_t socket_service_init();
extern uint16_t socket_wrt_recv_data_to_file(uint16_t *sock, uint8_t *fileName, uint8_t *rw, uint16_t len);
extern void* Socket_Thread(void* arvg);



#endif