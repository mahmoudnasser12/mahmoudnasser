/*
 * Led_blinking.c
 *
 * Created: 30/08/2024 07:02:53 م
 * Author : Dell
 */ 

#include <avr/io.h>
#include  <avr/delay.h>


#define F_CPU 16000000


int main(void)
{
	DDRD = 0xFF;
	PORTD = 0x00;
	

    while (1) 
    {
		PORTD |= (1<< PIND5);
		_delay_ms(500);
		PORTD &= ~(1<< PIND5);
		
		
    }
}

