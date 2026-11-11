/*
 * File:   sensor.c
 * Author: chandeesh
 *
 * Created on 29 October, 2026, 11:04 AM
 */

#include "header.h"

uint16_t get_speed()
{
    // Implement the speed function
    
    // Read the value from adc through channel 4
    uint16_t value=read_adc(CHANNEL4);
    
    // Convert the ADC value into speed between (0 - 99)
    value = (value/10.33);
    
    unsigned char speed[3];
    
    
    return value;
}

unsigned char get_gear_pos()
{
    // Implement the gear function
    static unsigned char gear=0;
    
    // Get the key from switch
    unsigned char key=readkey(STATE_CHANGE);
    
    if(gear==8)
    {
        return gear;
    }
    
    if(key==1)
    {
        // If key is 1 increment the gear untill to max_gear
        gear++;
        if(gear>6)
        {
            gear=7;
        }
    }
    else if(key==2)
    {
        // If key is 2 decrement the gear untill to 0
        if(gear<1)
        {
            gear=0;
        }
        else
        {
            gear--;
        }
    }
    else if(key==3)
    {
        // If key is 3 collison happen
        gear=8;
    }
    return gear;
}

void one_event(unsigned char* time,unsigned char *speed,unsigned char* gear,unsigned char *array)
{
    array[0]=time[0];
    array[1]=time[1];
    array[2]=time[3];
    array[3]=time[4];
    array[4]=time[6];
    array[5]=time[7];
    array[6]=speed[0];
    array[7]=speed[1];
    array[8]=gear[0];
    array[9]=gear[1];
    array[10]='\0';
}