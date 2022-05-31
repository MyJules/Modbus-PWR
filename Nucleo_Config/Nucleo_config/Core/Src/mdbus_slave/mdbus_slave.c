#include "mdbus_slave.h"

#include <string.h>

void idle();
void emision_start();
void emision();
void emision_end();
void reception();
void wait_end_of_frame();
void bad_mdbus_state();

mdbus_Packet* currentPacket;
mdbus_State mdbus_state = IDLE;

void mdbus_on_packet_send()
{
	static uint16_t cnt = 0;
	uint8_t Data[50];
	++cnt;

	uint16_t size = sprintf(Data, "Liczba wyslanych wiadomosci: %d.\n\r", cnt);
	//mdbus_send_packet_it(Data, size);
}

void mdbus_on_packet_receive(uint8_t *data, uint16_t size)
{
	uint8_t Data[PACKETSIZE+100];
	uint16_t size1 = 0;

	size1 = sprintf(Data, "Odebrana wiadomosc: %s\n\r", data);

	mdbus_send_packet_it(Data, size1);
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
