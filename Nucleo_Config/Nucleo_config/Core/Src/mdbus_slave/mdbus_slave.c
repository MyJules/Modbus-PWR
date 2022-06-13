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

ring_buffer_t m_message_queue_send;
ring_buffer_t m_message_queue_receive;
mdbus_State m_mdbus_state = IDLE;

void mdbus_on_packet_send()
{
	if(ring_buffer_is_empty(&m_message_queue_send)) return;

	uint8_t data[PACKETSIZE];
	//read data from buffer
	ring_buffer_dequeue_arr(&m_message_queue_send, data, PACKETSIZE);
	//send queued package
	mdbus_send_packet_it(data, PACKETSIZE);

}

void mdbus_on_packet_receive(uint8_t *data, uint16_t size)
{
	ring_buffer_queue_arr(&m_message_queue_receive, data, PACKETSIZE);
	mdbus_read_packet_it(data, size);
}

void mdbus_slave_run()
{
	switch(m_mdbus_state)
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
	m_mdbus_state = IDLE;
	ring_buffer_init(&m_message_queue_send);
	ring_buffer_init(&m_message_queue_receive);
}

void idle()
{
	if(ring_buffer_is_empty(&m_message_queue_receive)) return;

	uint8_t data[PACKETSIZE];
	ring_buffer_dequeue_arr(&m_message_queue_receive, data, PACKETSIZE);
	ring_buffer_queue_arr(&m_message_queue_send, data, PACKETSIZE);
}

