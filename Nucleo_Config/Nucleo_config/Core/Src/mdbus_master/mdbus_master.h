#ifndef SRC_MDBUS_MASTER_MDBUS_MASTER_H_
#define SRC_MDBUS_MASTER_MDBUS_MASTER_H_

#include <stdint.h>

#define PACKETSIZE 64

typedef enum
{
	IDLE = 0,
	EMISSION_START,
	EMISSION,
	EMISSION_END,
	RECEPTION,
	WAIT_END_OF_FRAME

}mdbus_State;

typedef struct
{
	//packet info
	uint8_t id;
	uint16_t adress;
	uint16_t function;
	//
	uint16_t data;

	uint16_t local_start_adress;

	//modbus information counters
	uint8_t requests;
	uint8_t successful_requests;
	uint8_t failed_requests;
	uint8_t exception_errors;
	uint8_t retries;

	//connection status
	uint8_t connections;
} mdbus_Packet;

void mdbus_master_configure();
void mdbus_make_packet(mdbus_Packet *packet,
					uint8_t id,
					uint8_t function,
					uint8_t adress,
					uint8_t data,
					uint8_t local_start_adress);
void mdbus_master_run();

//need to define how to send and receive packages
void mdbus_send_packet(uint8_t *data);
void mdbus_read_packet(uint8_t *data);

#endif /* SRC_MDBUS_MASTER_MDBUS_MASTER_H_ */