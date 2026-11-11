/*
 * File:   black_box.c
 * Author: chandeesh
 *
 * Created on 29 October, 2026, 10:17 AM
 */


#include "header.h"

unsigned char gear=0;
unsigned char gear_array[9][4]={"ON ","NE ","G1 ","G2 ","G3 ","G4 ","G5 ","R ","CO "};
unsigned char time[10];
unsigned char check_gear=0;
extern unsigned char count,size_flag,view_count;

unsigned char menu_array[4][16]={"1. VIEW LOG      ","2. DOWNLOAD LOG  ","3. SET TIME    ","4. CLEAR LOG   "};
extern unsigned char menu;

void view_dashboard(void)
{
    unsigned char time[10];
    unsigned char speed[3];
    
    clcd_print(" TIME     SPD EV",LINE1(0));
    
    get_time(time);
    
    uint16_t value=get_speed();
    // Update the speed into the char array
    speed[0]=(value/10) + '0';
    speed[1]=(value%10) + '0';
    speed[2]='\0';
    
    gear=get_gear_pos();
    
    clcd_putch(' ',LINE2(0));
    clcd_print(time,LINE2(1));
    clcd_putch(' ',LINE2(9));
    clcd_print(speed,LINE2(10));
    clcd_print("  ",LINE2(12));
    clcd_print(gear_array[gear],LINE2(14));
    
    if(gear!=check_gear)
    {
        check_gear=gear;
        unsigned char one_array[11];
        one_event(time,speed,gear_array[gear],one_array);
        write_event(one_array);
    }
}
void event_store(void)
{
    
}
void password(void)
{
    
}
void display_main_menu(void)
{
    clcd_putch('>',LINE1(0));
    clcd_print(menu_array[menu],LINE1(1));
    clcd_putch(' ',LINE2(0));
    if(menu==3)
    {
        clcd_print("                ",LINE2(0));
    }
    else
    {
        clcd_print(menu_array[menu+1],LINE2(1));
    }
}
void view_log(void)
{
    clcd_print("  LOG DETAILS    ",LINE1(0));
    event_reader();
}
void event_reader(void)
{
    unsigned char log[16];
    unsigned char limit=0;
    if(size_flag==1)
    {
        limit=10;
    }
    else
    {
        limit=count;
    }
    
    if(count==0)
    {
        clcd_print("NO LOG AVAILABLE  ",LINE2(0));
        return;
    }
    log[0]=read_eeprom((view_count-1)*10+3);
    log[1]=read_eeprom((view_count-1)*10+4);
    log[2]=':';
    log[3]=read_eeprom((view_count-1)*10+5);
    log[4]=read_eeprom((view_count-1)*10+6);
    log[5]=':';
    log[6]=read_eeprom((view_count-1)*10+7);
    log[7]=read_eeprom((view_count-1)*10+8);
    log[8]=' ';
    log[9]=read_eeprom((view_count-1)*10+9);
    log[10]=read_eeprom((view_count-1)*10+10);
    log[11]=' ';
    log[12]=' ';
    log[13]=read_eeprom((view_count-1)*10+11);
    log[14]=read_eeprom((view_count-1)*10+12);
    log[15]='\0';
    clcd_putch(' ',LINE2(0));
    clcd_print(log,LINE2(1));
}

void change_password(void)
{
    
}
unsigned char field=0;
unsigned char hour=0,min=0,sec=0;

unsigned char flag=0;
void set_time(void)
{
    if(flag==0)
    {   
        hour = read_rtc(HOUR_ADDR);
        min = read_rtc(MIN_ADDR);
        sec = read_rtc(SEC_ADDR);
        flag=1;
    }
    
    unsigned char key=readkey(STATE_CHANGE);
    if(key==4)
    {
        field=(field+1)%3;
    }
    
    else if(key==5)
    {
        if(field==0)
        {
            hour=(hour + 1)%24;
        }
        else if(field==1)
        {
            min=(min + 1)%60;
        }
        else if (field == 2)
        {
            sec=(sec + 1)%60;  
        }

    }
    else if(key==6) 
    {
        flag=0;
        write_rtc_time(hour, min, sec);
        field = 0;
        state = e_main_menu; 
    }
    
    display_set_time(hour, min, sec, field);
}
void download_log(void)
{   
   
   static unsigned char flag=0;
   if(count==0 && size_flag==0)
   {
       if(flag==0)
       {
           puts("  TIME     SPEED    GEAR\n\n\r");
            puts("    NO LOG AVAILABLE  \n\n\r");
            flag=1;
       }
   }
   else
   {
       puts("  TIME     SPEED    GEAR\n\n\r");
       flag=0;
       print_uart();
   }
       state=e_main_menu;

}
void clear_log(void)
{
    size_flag=0;
    count=0;
    view_count=0;
    clcd_print("  LOG CLEARED   ",LINE1(0));
    clcd_print("                ",LINE2(0));
}

void print_uart()
{
    unsigned char limit=0;
    
    if(size_flag==1)
    {
        limit=10;
    }
    else
    {
        limit=count;
    }
    for(int i=0;i<limit;i++)
    {
        unsigned char address=(i*10)+3;
        
        for(int j=0;j<10;j++)
        {
            putch(read_eeprom(address+j));
            if(j==1)
            {
                putch(':');
            }
            if(j==3)
            {
                putch(':');
            }
            if(j==5)
            {
                puts("   ");
            }
            if(j==7)
            {
                puts("       ");
            }
        }
        puts("\n\r");
    }    
    puts("\n\r");
}