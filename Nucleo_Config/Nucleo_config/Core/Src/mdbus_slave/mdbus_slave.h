#ifndef SRC_MDBUS_SLAVE_MDBUS_SLAVE_H_
#define SRC_MDBUS_SLAVE_MDBUS_SLAVE_H_

#include <stdint.h>

#define PACKETSIZE 1

void mdbus_slave_configure(uint8_t adress);
void mdbus_slave_run();

//need to define how to send and receive packages
//user defined functions
void mdbus_send_packet_it(uint8_t *data, uint16_t size);
void mdbus_read_packet_it(uint8_t *data, uint16_t size);
void mdbus_on_packet_send();
void mdbus_on_packet_receive(uint8_t *data, uint16_t size);

#endif /* SRC_MDBUS_SLAVE_MDBUS_SLAVE_H_ */
