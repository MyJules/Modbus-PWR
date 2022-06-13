#include "mdbus_slave.h"

#include "circular_buffer.h"

#include <string.h>
#include <stdbool.h>

typedef enum
{
	IDLE = 0,
	WAIT,
	FUNC_ADRESS,
	ERROR_UNKNOWN,
	OK,
	FAIL,
	CHECK_FRAME,
	FUNC1,
	FUNC2
} mdbus_State;

void idle();
void wait();
void func_adress();
void error_unknown();
void ok();
void fail();
void check_frame();
void func1();
void func2();

bool isEof();

ring_buffer_t m_message_queue_send;
ring_buffer_t m_message_queue_receive;
mdbus_State m_mdbus_state = IDLE;
uint8_t m_adress = '0';

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

	case WAIT:
		wait();
		break;

	case FUNC_ADRESS:
		func_adress();
		break;

	case ERROR_UNKNOWN:
		error_unknown();
		break;

	case OK:
		ok();
		break;

	case FAIL:
		fail();
		break;

	case CHECK_FRAME:
		check_frame();
		break;

	case FUNC1:
		func1();
		break;

	case FUNC2:
		func2();
		break;

	default:
		break;
	}
}

void mdbus_slave_configure(uint8_t adress)
{
	m_mdbus_state = IDLE;
	ring_buffer_init(&m_message_queue_send);
	ring_buffer_init(&m_message_queue_receive);
	m_adress = adress;
}

void idle()
{
	if(ring_buffer_is_empty(&m_message_queue_receive)) return;

	uint8_t data[PACKETSIZE];
	ring_buffer_dequeue_arr(&m_message_queue_receive, data, PACKETSIZE);

	//if the first bite is the adress of our mashine, if not, wait for end of package
	if(m_adress == data[0])
	{
		m_mdbus_state = FUNC_ADRESS;
	}else
	{
		m_mdbus_state = WAIT;
	}

}

void wait()
{
	uint8_t data[PACKETSIZE];
	m_mdbus_state = IDLE;
	*data = 'w';
	ring_buffer_queue_arr(&m_message_queue_send, data, PACKETSIZE);
}

void func_adress()
{
	uint8_t data[PACKETSIZE];
	m_mdbus_state = IDLE;
	*data = 'f';
	ring_buffer_queue_arr(&m_message_queue_send, data, PACKETSIZE);
}

void error_unknown()
{

}

void ok()
{

}

void fail()
{

}

void check_frame()
{

}

void func1()
{

}

void func2()
{

}

bool isEof()
{
	return true;
}

