
/* 
 * File:   black_box.h
 * Author:  chandeesh
 * Comments:
 * Revision history: 
 */


#ifndef BLACK_BOX_H
#define	BLACK_BOX_H

#include <stdint.h>
#include <xc.h>

/* Enum for maintaining the app state */
typedef enum {
    e_dashboard, 
    e_main_menu,
    e_view_log,
    e_set_time, 
    e_download_log, 
    e_clear_log
} State_t;


extern State_t state; // App state

//Function declarations

//Dashboard function declaration
void view_dashboard(void);

//Storing events function declaration
void event_store(void);

//Password function declaration
void password(void);

//main menu function declaration
void display_main_menu(void);

//View log function declaration
void view_log(void);

//Reading events function declaration
void event_reader(void);

//Change password function declaration
void change_password(void);

//Set time function declaration
void set_time(void);

//Download log function declaration
void download_log(void);
void print_uart();

//Clear log function declaration
void clear_log(void);



uint16_t get_speed();
unsigned char get_gear_pos();
void one_event(unsigned char*,unsigned char*,unsigned char*,unsigned char*);
#endif	/* XC_HEADER_TEMPLATE_H */

