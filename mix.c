#include<avr/io.h>
#include<stdio.h>
#include<util/delay.h>
#define F_CPU 14745600
void Buzz(void)
{
	PORTC=PORTC|0x08;
	_delay_ms(2000);
	PORTC=PORTC&0xF7;
	_delay_ms(2000);
}
void motion_pin_config(void)
{
	DDRA=0x0F;
	PORTA=0x00;
	DDRL=0x18;
	PORTL=0x18;
}
void forward(void)
{
	PORTA=0x06;
}
void reverse(void)
{
	PORTA=0x09;
}
void left(void)
{
	PORTA=0x05;
}
void right(void)
{
	PORTA=0x0A;
}
void s_left(void)
{
	PORTA=0x04;
}
void s_right(void)
{
	PORTA=0x02;
}
void stop(void)
{
	PORTA=0x00;
}
int main()
{
	DDRJ=0xFF;
	DDRC=DDRC|0x08;
	motion_pin_config();
	while(1)
	{
		Buzz();
		PORTJ=0x80;
		_delay_ms(5000);
		forward();
		_delay_ms(6000);
		
		Buzz();
		PORTJ=0x40;
		_delay_ms(5000);
		left();
		_delay_ms(6000);
		forward();
		_delay_ms(8000);
		
		Buzz();
		PORTJ=0x20;
		_delay_ms(5000);
		right();
		_delay_ms(6000);
		forward();
		_delay_ms(8000);
		
		Buzz();
		PORTJ=0x10;
		_delay_ms(5000);
		s_left();
		_delay_ms(6000);
		forward();
		_delay_ms(8000);
		
		Buzz();
		PORTJ=0x08;
		_delay_ms(5000);
		s_right();
		_delay_ms(6000);
		forward();
		_delay_ms(8000);
		
		Buzz();
		PORTJ=0x04;
		_delay_ms(5000);
		reverse();
		_delay_ms(6000);
		
		Buzz();
		PORTJ=0x02;
		_delay_ms(5000);
		stop();
		_delay_ms(8000);
	}
}
