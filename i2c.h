
/* 
 * File:   i2c.h
 * Author:  chandeesh
 * Comments:
 * Revision history: 
 */

#ifndef I2C_H
#define	I2C_H

#include <xc.h> 

void init_i2c();
void i2c_idle();
void i2c_start();
void i2c_stop();
void i2c_repstart();
void i2c_write(unsigned char);
void i2c_rx_mode();
unsigned char i2c_read();
void i2c_ack();
void i2c_nack();
unsigned char i2c_is_nack();



#endif	/* XC_HEADER_TEMPLATE_H */

