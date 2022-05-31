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
	ring_buffer_queue_arr(&message_queue, data, size);
	mdbus_read_packet_it(data, size);
}

void mdbus_slave_run()
{
	switch(mdbus_state)
	{
	case IDLE:
		idle();
		break;
	case EMISSION_START:
		emision_start();
		break;
	case EMISSION:
		emision();
		break;
	case EMISSION_END:
		emision_end();
		break;
	case RECEPTION:
		reception();
		break;
	case WAIT_END_OF_FRAME:
		wait_end_of_frame();
		break;
	default:
		bad_mdbus_state();
		break;
	}
}

void mdbus_make_packet(mdbus_Packet *packet,
					uint8_t id,
					uint8_t function,
					uint8_t adress,
					uint8_t data,
					uint8_t local_start_adress)
{
	packet->id = id;
	packet->function = function;
	packet->adress = adress;
	packet->data = data;
	packet->local_start_adress = local_start_adress;
}

void mdbus_slave_configure()
{
	mdbus_state = IDLE;
	ring_buffer_init(&message_queue);
}

void idle()
{
}

void emision_start()
{
}

void emision()
{
}

void emision_end()
{
}

void reception()
{
}

void wait_end_of_frame()
{
}

void bad_mdbus_state()
{
}
