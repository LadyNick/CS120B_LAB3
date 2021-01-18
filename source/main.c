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

unsigned char GetBit(unsigned char x, unsigned k){
	return ((x & (0x01 << k)) != 0);
}

int main(void) {
    DDRA = 0x00; PINA = 0xFF;
    DDRB = 0x00; PINB = 0xFF;
    DDRC = 0xFF; PORTC = 0x00;

    unsigned char tmpC = 0x00;
    unsigned char tmpA = 0x00;
    unsigned char tmpB = 0x00;


    while (1) {

	tmpA = PINA;
	tmpB = PINB;
	 

	for(int i = 0; i < 8; ++i){
		tmpC = tmpC + GetBit(tmpA, i);
		tmpC = tmpC + GetBit(tmpB, i);
	}

	PORTC = tmpC;

    }
    return 1;
}
