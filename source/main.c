/*	Author: lab
 *  Partner(s) Name: N/A
 *	Lab Section:
 *	Assignment: Lab #  Exercise #
 *	Exercise Description: [optional - include for your own benefit]
 *
 *	I acknowledge all content contained herein, excluding template or example
 *	code, is my own original work.
 */
#include <avr/io.h>
#ifdef _SIMULATE_
#include "simAVRHeader.h"
#endif


int main(void) {

    DDRB = 0xFE; PORTB = 0x00;
    DDRD = 0x00; PIND = 0xFF;

    unsigned char weight = 0x00;
 
    while (1) {
	    
	    weight = (PIND << 1) + (PORTB & 0x01);
	    
	    if(weight <= 0x05){
		//do nothing, dont set PB1 OR PB0
	    }
	    else{
	    if(weight >= 0x46){
		PORTB = PORTB | 0x02;
	    }
	    else{
		PORTB = PORTB & ~(0x02);
	    }
	    if((weight > 0x05) && (weight < 0x46)){
		PORTB = PORTB | 0x04;
	    }
	    else{
		PORTB = PORTB & ~(0x04);
	    }
	    }


    }
    return 1;
}
