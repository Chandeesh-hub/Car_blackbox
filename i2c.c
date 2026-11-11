/*
 * File:   i2c.c
 * Author: chandeesh
 *
 * Created on 29 October, 2026, 11:37 AM
 */
#include "i2c.h"

void init_i2c()
{
    TRISC3=1;
    TRISC4=1;
    
    SSPCON1=0x28;
    
    SSPCON2=0x00;
    
    SMP=1;
    CKE=0;
    
    SSPADD=0x31;
    SSPIF=0;
    BCLIF=0;
}

void i2c_idle()
{
    while(!SSPIF);
    SSPIF=0;
}

void i2c_start()
{
    SSPIF=0;
    SEN=1;
    i2c_idle();
}

void i2c_stop()
{
    SSPIF=0;
    PEN=1;
    i2c_idle();
}

void i2c_repstart()
{
    SSPIF=0;
    RSEN=1;
    i2c_idle();
}

void i2c_write(unsigned char data)
{
    SSPIF=0;
    SSPBUF=data;
    i2c_idle();
}

void i2c_rx_mode()
{
    SSPIF=0;
    RCEN=1;
    i2c_idle();
}

unsigned char i2c_read()
{
    i2c_rx_mode();
    return SSPBUF;
}

void i2c_ack()
{
    SSPIF=0;
    ACKDT=0;
    ACKEN=1;
    i2c_idle();
}
void i2c_nack()
{
    SSPIF=0;
    ACKDT=1;
    ACKEN=1;
    i2c_idle();
}

unsigned char i2c_is_nack()
{
    return ACKSTAT;
}