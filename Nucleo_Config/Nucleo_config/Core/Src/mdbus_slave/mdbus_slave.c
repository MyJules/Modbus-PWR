#include "mdbus_slave.h"

#include <string.h>

void idle();
void emision_start();
void emision();
void emision_end();
void reception();
void wait_end_of_frame();
void bad_mdbus_state();

uint32_t timeout;
mdbus_Packet* currentPacket;
mdbus_State mdbus_state = IDLE;

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
