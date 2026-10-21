# COTS – ATmega32 Embedded Drivers

A collection of reusable **Embedded C drivers for the ATmega32 microcontroller**, organized using a layered architecture.

## 📁 Project Structure

```text
COTS
├── APP
├── HAL
│   ├── Buzzer
│   ├── DC Motor
│   ├── IR Sensor
│   ├── LED
│   ├── Seven Segment
│   └── Switch
├── LIB
└── MCAL
    └── DIO
```

## 🏗️ Architecture

* **APP** – Application layer containing application-specific logic.
* **HAL** – Hardware Abstraction Layer for interfacing with external hardware components.
* **MCAL** – Microcontroller Abstraction Layer for controlling microcontroller peripherals.
* **LIB** – Common utilities, standard data types, and bit manipulation macros.

## 🔧 Implemented Drivers

### HAL

* **LED** – LED control.
* **Seven Segment** – Displaying numeric digits.
* **Switch** – Push-button input handling.
* **IR Sensor** – Infrared sensor interfacing.
* **DC Motor** – DC motor control.
* **Buzzer** – Buzzer control.

### MCAL

* **DIO** – Digital Input/Output pin and port control.

### LIB

* **BIT_MATH** – Bit manipulation macros.
* **STD_TYPES** – Standard data type definitions.

## 🎯 Purpose

This project aims to build a reusable driver library for **Embedded C development on AVR microcontrollers**, following a layered architecture that promotes modularity, code reusability, and maintainability.

The library is continuously evolving, with more HAL components and MCAL peripherals planned for future development.

## 🚀 Future Plans

* Develop additional HAL drivers.
* Implement more MCAL peripherals, including timers, interrupts, and ADC.
* Improve driver documentation and error handling.
* Build practical embedded systems projects using the library.
