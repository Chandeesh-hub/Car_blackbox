# Car Black Box System

## Overview

The **Car Black Box System** is an embedded system developed using the **PIC18F4580 microcontroller** to monitor and record important vehicle parameters and events in real time.

The system stores vehicle information, including time, speed, and gear position, in EEPROM. A DS1307 Real-Time Clock (RTC) provides timestamps for recorded events.

Users can interact with the system through a Character LCD (CLCD) and matrix keypad to view event logs, download recorded data to a PC, configure the RTC time, and clear stored logs.

## Features

- **Real-Time Monitoring:** Displays vehicle parameters such as time, speed, and gear position.
- **EEPROM Data Logging:** Stores vehicle event records in non-volatile memory.
- **RTC Integration:** Uses the DS1307 RTC to maintain event timestamps.
- **Event Log Management:** Supports viewing, downloading, and clearing recorded logs.
- **Time Configuration:** Allows users to configure the RTC through the keypad interface.
- **CLCD Interface:** Displays the dashboard, menu options, and stored event information.
- **UART Communication:** Transfers recorded vehicle data to a PC through serial communication.

## Hardware Components

| Component | Purpose |
|---|---|
| PIC18F4580 | Main microcontroller |
| DS1307 RTC | Real-time clock and timestamping |
| EEPROM | Non-volatile event data storage |
| CLCD | Displays vehicle parameters and menus |
| Matrix Keypad | User input and menu navigation |
| UART Interface | Communication with PC |

## Software and Technologies

- Embedded C
- MPLAB X IDE
- MPLAB XC8 Compiler
- PIC18F4580 Microcontroller
- I2C Communication
- UART Communication
- ADC (where applicable)

## System Functionalities

### 1. Dashboard
Displays the current time, vehicle speed, and gear position on the CLCD.

### 2. View Event Logs
Allows users to navigate through previously recorded vehicle events using the matrix keypad.

### 3. Download Event Logs
Transfers stored vehicle information from EEPROM to a PC through UART communication.

### 4. Set RTC Time
Allows users to configure the time maintained by the DS1307 RTC.

### 5. Clear Event Logs
Provides an option to clear previously stored event records from EEPROM.

## System Workflow

1. Initialize the PIC18F4580 peripherals and connected modules.
2. Read the current time from the DS1307 RTC.
3. Monitor vehicle parameters.
4. Record relevant events with their timestamps.
5. Store event information in EEPROM.
6. Allow users to access log management functions through the CLCD and keypad.
7. Transfer recorded data to a PC using UART when requested.

## Communication Protocols

| Protocol | Application |
|---|---|
| I2C | DS1307 RTC and EEPROM communication |
| UART | Downloading event logs to a PC |
| ADC | Reading analog vehicle parameters, where applicable |

## Learning Outcomes

Through this project, I gained practical experience in:

- PIC18F4580 microcontroller programming.
- Embedded C programming and peripheral interfacing.
- I2C and UART communication protocols.
- EEPROM read/write operations and data management.
- RTC interfacing and timestamp handling.
- CLCD and matrix keypad interfacing.
- Implementing menu-driven embedded applications.
- Debugging and integrating multiple hardware peripherals.

## Future Enhancements

- Add GPS-based vehicle location tracking.
- Integrate wireless data transmission.
- Add additional vehicle sensors for enhanced monitoring.
- Develop a PC-side application for visualizing recorded events.

---

**Project Domain:** Embedded Systems | Automotive Electronics | Microcontroller Programming

**Controller:** PIC18F4580

**Language:** Embedded C
