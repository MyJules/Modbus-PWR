#include "mdbus_slave.h"

#include "circular_buffer.h"
#include <string.h>

void idle();
void emision_start();
void emision();
void emision_end();
void reception();
void wait_end_of_frame();
void bad_mdbus_state();

ring_buffer_t message_queue;
mdbus_State mdbus_state = IDLE;

void mdbus_on_packet_send()
{
	if(ring_buffer_is_empty(&message_queue)) return;

	uint8_t data[PACKETSIZE];
	//read data from buffer
	ring_buffer_dequeue_arr(&message_queue, data, PACKETSIZE);
	//send queued package
	mdbus_send_packet_it(data, PACKETSIZE);

}

void mdbus_on_packet_receive(uint8_t *data, uint16_t size)
{
	ring_buffer_queue_arr(&message_queue, data, PACKETSIZE);
	mdbus_read_packet_it(data, size);
}

void mdbus_slave_run()
{
	switch(mdbus_state)
	{
	case IDLE:
		idle();
		break;
	default:
		break;
	}
}

void mdbus_slave_configure()
{
	mdbus_state = IDLE;
	ring_buffer_init(&message_queue);
}

void idle()
{
}

