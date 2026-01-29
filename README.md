# TRAINING-432: Training Road Map 2025 | Mariyam  
[Project Jira Link](https://maanzai.atlassian.net/browse/TRAINING-432)  
[Training Plan for Embedded Software Engineer](https://maanzai.atlassian.net/wiki/spaces/MES/pages/257458198/Training+plan+for+Embedded+Software+Engineer)

| Version  | Change  |
|---|---|
| v0.4 | Implemented UART driver and tested with a logic analyzer and Putty (Serial Terminal) |
| v0.3 | Implemented timer driver and tested with a state machine application |
| v0.2 | Implemented GPIO driver and tested with onboard red LED |
| v0.1 | Implemented start-up phase along with a blinky program for testing purposes |

# LIN Driver and Application Development

This embedded systems training project focuses on developing hardware drivers culminating in a LIN driver and a LIN-based application utilizing those drivers. The project is organized into sequential phases to build up from basic startup code to full application functionality:

- Start-up  
- GPIO Driver  
- Timer Driver  
- UART Driver  
- LIN Driver
- LIN Application  

---

## Table of Contents
- [TRAINING-432: Training Road Map 2025 | Mariyam](#training-432-training-road-map-2025--mariyam)
- [LIN Driver and Application Development](#lin-driver-and-application-development)
  - [Table of Contents](#table-of-contents)
  - [Project Status](#project-status)
    - [Completed Phases](#completed-phases)
      - [Start-up](#start-up)
      - [GPIO Driver](#gpio-driver)
      - [Timer Driver](#timer-driver)
      - [UART Driver](#uart-driver)
    - [Upcoming Phases](#upcoming-phases)
  - [Getting Started](#getting-started)
    - [Dependencies](#dependencies)
    - [Building](#building)
    - [Running Tests](#running-tests)
    - [Usage](#usage)
  - [GPIO Driver (Phase 2)](#gpio-driver-phase-2)
    - [Implemented Components](#implemented-components)
      - [Data Structures](#data-structures)
      - [Enumerations](#enumerations)
      - [Macros](#macros)
      - [APIs Implemented](#apis-implemented)
    - [Testing](#testing)
  - [Timer Driver (Phase 3)](#timer-driver-phase-3)
    - [Implemented Components](#implemented-components-1)
      - [Data Structures](#data-structures-1)
      - [Enumerations](#enumerations-1)
      - [Macros](#macros-1)
      - [APIs Implemented](#apis-implemented-1)
    - [Testing](#testing-1)
  - [UART Driver (Phase 4)](#uart-driver-phase-4)
    - [Implemented Components](#implemented-components-2)
      - [Data Structures](#data-structures-2)
      - [Enumerations](#enumerations-2)
      - [Macros](#macros-2)
      - [APIs Implemented](#apis-implemented-2)
    - [Testing](#testing-2)
  - [Release Process](#release-process)
  - [Further Reading](#further-reading)
  - [Author](#author)


---

## Project Status

### Completed Phases
#### Start-up  
- Implemented vector table, reset handler, and initial hardware setup on TM4C123GH6PMI  
- Main function blinks the red LED to demonstrate successful initialization  

#### GPIO Driver
- A complete GPIO driver was implemented, including data structures, enums, macros, and GPIO APIs.
- Testing performed using onboard LEDs.

#### Timer Driver
- A complete timer driver was implemented, including data structures, enums, macros, and timer APIs.
- Testing performed using onboard LEDs and timer.

#### UART Driver
- UART driver for UART0 and UART1 was implemented, including data structures, enums, macros, and UART APIs.
- Testing performed using logic analyzer and putty.
  
### Upcoming Phases
1. LIN Driver
2. LIN Application

---
## Getting Started

### Dependencies

- **Hardware:**  
  - TM4C123GH6PMI mircrocontroller
  - Logic analyzer, USB cables, LEDs, push buttons as needed  

- **Software:**  
  - GCC toolchain for ARM Cortex-M  
  - GDB debugger  
  - Make (build system)  
  - Optional: IDEs like Keil, IAR, or VSCode with Cortex plugins  
  - Saleae Logic
  - Putty

- **Documentation:**  
  - Microcontroller reference manuals  
  - Compiler and linker manuals  
  - Board user manual

> *Note:* Ensure your environment is set up with cross-compilation tools and your PATH includes the GCC binaries. In case of windows you will need to install [cygwin](https://www.cygwin.com/install.html)  first.

---

### Building

Use the provided Makefile for building. 
* Build firmware and generate binaries:
  ```
  make build
  ```
* Clean build artifacts:
  ```
  make clean
  ```
* Full cycle (clean, build):
  ```
  make all
  ```
* To Flash first you need to install the manufacturer's flashing tool, in this case its [LM FLASH PROGRAMMER](https://www.ti.com/tool/LMFLASHPROGRAMMER)
### Running Tests

At present, manual hardware verification is used (e.g., red LED blinking on startup). Automated unit testing is planned for future phases.


### Usage

Once flashed, the device runs startup code and jumps to main(), that blinks the onboard red LED, demonstrating successful initialization.

Future phases will add driver APIs and applications interfacing with hardware peripherals and serial terminals.

**[Back to top](#table-of-contents)**

## GPIO Driver (Phase 2)
This phase introduces a modular and reusable GPIO driver for TM4C123GH6PMI.
### Implemented Components
#### Data Structures
1. ``gpio_Regs``   : Maps GPIO hardware registers
2. ``gpio_Config`` : Stores configuration for each pin

#### Enumerations
1. ``gpio_Port`` : Port A to F
2. ``gpio_Pins`` : Pin 0  to pin 7
3. ``gpio_Mode`` : Input or output mode
4. ``gpio_Error`` : 0(SUCCESS) to 15

#### Macros
1. ``Base addresses`` : Base address of ports, clock
1. ``Register offsets`` : Register offsets of each port
1. ``Bit offsets`` : To access each  bit
1. ``Mask values`` : Pins masked addresses for each port

#### APIs Implemented
All return type: ``gpio_Error``

1. ``gpio_initGpioPort`` : Initializes GPIO port
2. ``gpio_digitalToggle`` : Toggles pin state
3. ``gpio_digitalWrite`` : Writes 0/1 to output pin
4. ``gpio_digitalRead`` : Reads input pin state
5. ``gpio_interruptCallback`` : Called on an interrupt

### Testing
Verified GPIO output using onboard red LED. Onboard LED mapping was read from the boards user manual, which in his case is Tiva C Series TM4C123G.

**[Back to top](#table-of-contents)**

## Timer Driver (Phase 3)
This phase implements a timer driver for the TM4C123GH6PMI microcontroller, supporting both 16/32-bit timers and 32/64-bit wide.
### Implemented Components
#### Data Structures
1. ``gptm_Regs``   : Maps Timer hardware registers
2. ``gptm_Config`` : Stores configuration for each timer

#### Enumerations
1. ``gptm_SelectTimer`` : Timer module to use (TIMER0–TIMER5 or WTIMER0–WTIMER5)
2. ``gptm_Channel`` : Channel A or Channel B or Both channels
3. ``gptm_Mode`` : One-shot, periodic
4. ``gptm_CountDirection`` : COUNT_DIR
5. ``gptm_Cfg`` : Split or concatination
6. ``gptm_ERROR``: 16(SUCCESS) to 31

#### Macros
1. ``Base addresses`` : Base address of timers, clocks
1. ``Register offsets`` : Register offsets of each timer
1. ``Bit offsets`` : To access each  bit
1. ``Mask values`` : Register's bits masked addresses for each timer

#### APIs Implemented
All return type: ``GPIO_ERROR`` except gptm_interruptCallback

1. ``gptm_initTimer`` : Initializes GPTM timer
2. ``gptm_startTimer`` : Starts timer
3. ``gptm_blockingDelay`` : For polling
5. ``gptm_convertSecToTicks`` : Converts Seconds to ticks
6. ``gptm_validateConfiguration`` : Helper function that validates configuration
7. ``gptm_enableClockForTimer`` : Helper function to enable clock for selected timer
8. ``gptm_reloadTimer`` : Reloads timer with new load value
9. ``void gptm_interruptCallback`` : Called on an interrupt



### Testing
Verified via application-level state machine controlling system behavior. The state machine coordinates GPIO inputs (SW1, SW2), timer events, and LED outputs. State transitions are triggered by GPIO and GPTM interrupts, while state execution is handled in the main loop.

**[Back to top](#table-of-contents)**

## UART Driver (Phase 4)
This phase implements a UART driver for the TM4C123GH6PMI microcontroller, enabling serial communication via UART peripherals. The driver supports configurable baud rate, data length, parity, stop bits, and interrupt handling for reciever.

### Implemented Components
#### Data Structures
1. ``uart_Regs``   : Maps Timer hardware registers
2. ``uart_Config`` : Stores configuration for each timer

#### Enumerations
1. ``uart_Number`` : UART module selection (UART0, UART1, etc.)
2. ``uart_BaudRate`` : Supported baud rates (9600, 19200, 38400, 57600, 115200)
3. ``uart_WordLength`` : Word lengths from 5 to 8 bits
4. ``uart_StopBits`` : 1 or 2 stop bits
5. ``uart_Parity`` : None, Even, Odd parity
6. ``uart_RcvrInterruptEnable``: Interrupt enable/disable
7. ``uart_Error``: Error and status codes for driver operations

#### Macros
1. ``Base addresses`` : Base address of UARTs and clock to enable each UART
1. ``Register offsets`` : Register offsets of each UART
1. ``Bit offsets`` : To access each bit of registers
1. ``Mask values`` : Register's bits masked addresses for each UART

#### APIs Implemented
All return type: ``uart_Error`` except in

1. ``uart_init`` : Initializes UART peripheral based on provided configuration, including clock enable, GPIO pin configuration for UART functionality, baud rate divisor calculation, line control settings, FIFO, and interrupt setup
2. ``uart_getBase`` : Returns base address of the UART selected
3. ``uart_enableClock`` : Enabled clock for the UART selected
4. ``uart_sendChar`` : Sends a single character via UART
5. ``uart_sendString`` : Sends a null-terminated string via UART
6. ``uart_receiveChar`` : Receives a single character via UART in polling mode or interrupt-driven mode
7. ``uart0_interruptCallback`` : Interrupt callback routine for UART 0
8. ``uart1_interruptCallback`` : Interrupt callback routine for UART 1


### Testing
Used logic analyzer to verify the functional correctness and accuracy. For echo testing, a USB-TTL converter was used with PuTTY (Serial Terminal). 

**[Back to top](#table-of-contents)**


## Release Process

This project follows a phased release strategy:

1. Each training phase is developed in a separate Git branch (e.g., ES_T1_Mariyam for phase 1).
2. Completed phases are merged into the main branch (ES_Main_Mariyam) via pull requests.
3. Pull requests link to Jira sub-tasks for traceability.
4. Approved merges are tagged accordingly, e.g. ES_T1_Mariyam.

**[Back to top](#table-of-contents)**




## Further Reading

* [TM4C123GH6PMI Datasheet](https://www.ti.com/lit/ds/symlink/tm4c123gh6pm.pdf)
* [ARM Cortex-M4 Technical Reference Manual](https://developer.arm.com/documentation/dui0553/a/)

**[Back to top](#table-of-contents)**


## Author

* **Mariyam Shahid** 

**[Back to top](#table-of-contents)**
