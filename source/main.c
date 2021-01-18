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
    DDRA = 0x00; PINA = 0xFF;
    DDRB = 0x00; PINB = 0xFF;
    DDRC = 0xFF; PORTC = 0x00;

    unsigned char tmpC = 0x00;

    while (1) {	 

	for(int i = 0; i < 8; ++i){
		tmpC = tmpC + ((PINA & (0x01 << i)) > 0);
		tmpC = tmpC + ((PINB & (0x01 << i)) > 0);

	}

	PORTC = tmpC;

    }
    return 1;
}
