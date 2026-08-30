# COTS – ATmega32 Embedded Drivers

A collection of reusable **Embedded C drivers for the ATmega32 microcontroller**, organized using a layered architecture.

## 📁 Project Structure

```text
COTS
├── APP
├── HAL
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

### MCAL

- DIO (Digital Input/Output)

### LIB

- Bit Manipulation Macros
- Standard Data Types

## 🎯 Purpose
This project is being developed as a reusable driver library for **Embedded Systems development using AVR microcontrollers**.

More drivers and modules will be added as the project evolves.
