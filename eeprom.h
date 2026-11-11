
/* 
 * File:   eeprom.h
 * Author:  chandeesh
 * Comments:
 * Revision history: 
 */


#ifndef EEPROM_H
#define	EEPROM_H

#include <xc.h> 

#define EEPROM_WRITE 0xA0
#define EEPROM_READ 0xA1

unsigned char read_eeprom(unsigned char);
void write_eeprom(unsigned char,unsigned char);
void write_event(unsigned char*);

#endif	/* XC_HEADER_TEMPLATE_H */
