/*
 * File:   eeprom.c
 * Author: chandeesh
 *
 * Created on 30 October, 2026, 12:50 PM
 */



#include "header.h"
extern unsigned char count,size_flag;

unsigned char read_eeprom(unsigned char address)
{
    
	unsigned char data;

	i2c_start();
	i2c_write(EEPROM_WRITE);
	i2c_write(address);
	i2c_repstart();
	i2c_write(EEPROM_READ);
	data = i2c_read();
    i2c_nack();
	i2c_stop();

	return data;
}

void write_eeprom(unsigned char address,unsigned char data)
{
    i2c_start();
	i2c_write(EEPROM_WRITE);
	i2c_write(address);
	i2c_write(data);
	i2c_stop(); 
    
    __delay_ms(5);
}

void write_event(unsigned char *array)
{
    write_eeprom(0x00,1);
    ++count;
    if(count==11)
    {
        count=1;
        size_flag=1;
        write_eeprom(0x02,size_flag);
    }
    write_eeprom(0x01,count);
    
    unsigned char address=((count-1)*10)+3;

    while(*array)
    {
        write_eeprom(address++,*array++);
    }
}

