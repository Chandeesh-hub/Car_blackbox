
#include "header.h"

void init_rtc()
{
    unsigned char ch;
    
    ch=read_rtc(SEC_ADDR);
    write_rtc(SEC_ADDR,ch | 0x80);
    
    ch=read_rtc(HOUR_ADDR);
    write_rtc(HOUR_ADDR,ch & 0x3F);
    
    write_rtc(CNTL_ADDR,0x93);
    
    ch=read_rtc(SEC_ADDR);
    write_rtc(SEC_ADDR,ch & 0x7F);
}

unsigned char read_rtc(unsigned char address)
{
    i2c_start();
    i2c_write(RTC_WRITE);
    
    i2c_write(address);
    
    i2c_repstart();
    i2c_write(RTC_READ);
    
    unsigned char data;
    data=i2c_read();
    i2c_stop();
    
    return data;
}

void write_rtc(unsigned char address,unsigned char data)
{
    i2c_start();
    i2c_write(RTC_WRITE);
    
    i2c_write(address);
    
    i2c_write(data);
    
    i2c_stop();
}

void get_time(unsigned char * time)
{
    unsigned char ch;
    
    ch=read_rtc(HOUR_ADDR);
    
    if(ch & 0x40)
    {
        time[0]=((ch>>4)&0x01) + '0';
        time[1]=(ch & 0x0F) + '0';
    }
    else
    {
        time[0]=((ch>>4)&0x03) + '0';
        time[1]=(ch & 0x0F) + '0';
    }
    time[2]=':';
    
    ch=read_rtc(MIN_ADDR);
    time[3]=((ch>>4) & 0x0F) +'0';
    time[4]=(ch&0x0F) + '0';
    time[5]=':';
    
    ch=read_rtc(SEC_ADDR);
    time[6]=((ch>>4) & 0x0F) +'0';
    time[7]=(ch&0x0F) + '0';
    time[8]='\0';
    
}
void write_rtc_time(unsigned char hr, unsigned char min, unsigned char sec)
{
    unsigned char bcd_sec = (((sec / 10) << 4) | (sec % 10));
    unsigned char bcd_min = (((min / 10) << 4) | (min % 10));;
    unsigned char bcd_hour = (((hr / 10) << 4) | (hr % 10));

    write_rtc(SEC_ADDR,bcd_sec);
    write_rtc(MIN_ADDR,bcd_min);
    write_rtc(HOUR_ADDR,bcd_hour);
}

void display_set_time(unsigned char hour, unsigned char min, unsigned char sec, unsigned char field)
{
    clcd_print(" SET TIME        ", LINE1(0));

    static unsigned int blink_cnt = 0;
    static unsigned char blink_flag = 0;

    blink_cnt++;
    if (blink_cnt > 200) 
    {
        blink_flag = !blink_flag;
        blink_cnt = 0;
    }

    unsigned char time_str[15];

 
    if (field == 0 && blink_flag) 
    {
        time_str[0] = ' ';
        time_str[1] = ' ';
    } 
    else 
    {
        time_str[0] = (hour / 10) + '0';
        time_str[1] = (hour % 10) + '0';
    }
    
    time_str[2] = ':';

    if (field == 1 && blink_flag) 
    {
        time_str[3] = ' ';
        time_str[4] = ' ';
    } 
    else 
    {
        time_str[3] = (min / 10) + '0';
        time_str[4] = (min % 10) + '0';
    }
    
    time_str[5] = ':';

    if (field == 2 && blink_flag) 
    {
        time_str[6] = ' ';
        time_str[7] = ' ';
    } 
    else 
    {
        time_str[6] = (sec / 10) + '0';
        time_str[7] = (sec % 10) + '0';
    }
    
    time_str[8]=' ';
    time_str[9]=' ';
    time_str[10]=' ';
    time_str[11]=' ';
    time_str[12]=' ';
    time_str[13]=' ';
    time_str[14]=' ';
    time_str[15]='\0';
    clcd_print(time_str, LINE2(1));
}