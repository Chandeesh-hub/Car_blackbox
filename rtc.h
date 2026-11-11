
#ifndef RTC_H
#define	RTC_H

#include <xc.h> 

#define RTC_READ 0xD1
#define RTC_WRITE 0xD0

#define SEC_ADDR 0x00
#define MIN_ADDR 0x01
#define HOUR_ADDR 0x02
#define DAY_ADDR 0x03
#define DATE_ADDR 0x04
#define MONTH_ADDR 0x05
#define YEAR_ADDR 0x06
#define CNTL_ADDR 0x07

void init_rtc();
unsigned char read_rtc(unsigned char address);
void write_rtc(unsigned char address,unsigned char data);
void get_time(unsigned char*);
void get_date(unsigned char*);
void write_rtc_time(unsigned char hour, unsigned char min, unsigned char sec);
void display_set_time(unsigned char hour, unsigned char min, unsigned char sec, unsigned char field);

#endif