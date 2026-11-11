/*
 * File:   main.c
 * Author: chandeesh
 *
 * Created on 29 October, 2026, 10:12 AM
 */

#include "header.h"
State_t state;

void init_config()
{
    init_i2c();
    init_matrix();
    init_adc();
    init_clcd();
    init_uart();
    state = e_dashboard;
    init_rtc();
}


unsigned char menu=0,eeprom_flag=0,count=0,size_flag=0,view_flag=0;
unsigned char view_count=1;
void main(void) 
{
    init_config();
    
    eeprom_flag=read_eeprom(0x00);
    if(eeprom_flag==1)
    {
        count=read_eeprom(0x01);
        size_flag=read_eeprom(0x02);
    }
    else
    {
        count=0;
    }
    
    unsigned char key;
    unsigned int delay1=0,delay2=0;
    unsigned char menu_flag=0,long_press=0;
    
    while(1)
    {
        // Detect key press
        key=readkey(LEVEL);
        if(key==4)
        {
            delay1++;
            if(delay1>200)
            {
                delay1=0;
                long_press=1;
                if(menu_flag==0)
                {
                    menu=0;
                    menu_flag=1;
                    state=e_main_menu;
                }
                else if(menu_flag==1)
                {
                    if(menu==0)
                    {
                        state=e_view_log;
                        view_flag=1;
                    }
                    else if(menu==1)
                    {
                        state=e_download_log;
                    }
                    else if(menu==2)
                    {
                        state=e_set_time;
                    }
                    else if(menu==3)
                    {
                        state=e_clear_log;
                    }
                    menu_flag=2;
                }
            }
            
        }
        
        // short press
        else if(delay1>0 && delay1<200)
        {
            long_press=0;
            if(menu_flag==1 && menu<3)
            {
                menu++;
            }
            if(menu==0 && view_flag==1)
            {
                if(view_count<10)
                {
                    view_count++;
                }
            }
            delay1=0;
        }
        else 
        {
            delay1=0;
        }
        
        
        if(key==5)
        {
            delay2++;
            if(delay2>200)
            {
                if(menu_flag==2)
                {
                    menu_flag=1;
                    state=e_main_menu;
                }
                else if(menu_flag==1)
                {
                    menu_flag=0;
                    state=e_dashboard;
                }
                delay2=0;
            }
        }
        
        // short press
        else if(delay2>0 && delay2<200)
        {           
            if(menu_flag==1 && menu>0)
            {
                menu--;
            }
            if(menu==0 && view_flag==1)
            {
                if(view_count>1)
                {
                    view_count--;
                }
            }
            delay2=0;
        }
        else 
        {
            delay2=0;
        }
        
        switch(state)
        {
            case e_dashboard:
                // Display dashboard
                view_dashboard();
                break;
            
            case e_main_menu:
                // Display dashboard
                display_main_menu();
                break;
            
            case e_view_log:
                // Display dashboard
                view_log();
                break;
                 
            case e_download_log:
                download_log();
                
                break;
                
            case e_clear_log:
                clear_log();
                break;
                
                      
            case e_set_time:
                set_time();
                break;
                
        }
    }   
}
