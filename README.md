# COTS – ATmega32 Embedded Drivers

A collection of reusable **Embedded C drivers for the ATmega32 microcontroller**, organized using a layered architecture.

## 📁 Project Structure

```text
COTS
├── APP
├── HAL
│   ├── LED
│   │   ├── LED_interface.h
│   │   └── LED_program.c
│   └── SEVSEG
│       ├── SEVSEG_interface.h
│       └── SEVSEG_program.c
├── LIB
│   ├── BIT_MATH.h
│   └── STD_TYPES.h
└── MCAL
    └── DIO
        ├── DIO_config.h
        ├── DIO_interface.h
        ├── DIO_private.h
        ├── DIO_program.c
        └── DIO_register.h
```

## 🏗️ Architecture

- **APP** – Application layer
- **HAL** – Hardware Abstraction Layer
- **MCAL** – Microcontroller Abstraction Layer
- **LIB** – Common libraries and utilities

## 🔧 Current Drivers

### HAL

- **LED** – LED control driver
- **Seven Segment** – Seven-segment display control driver

### MCAL

- **DIO** – Digital Input/Output driver

### LIB

- Bit Manipulation Macros
- Standard Data Types

## 🎯 Purpose

This project is being developed as a reusable driver library for **Embedded Systems development using AVR microcontrollers**.

The current implementation includes DIO, LED, and Seven Segment drivers, with more drivers and modules planned as the project evolves.
