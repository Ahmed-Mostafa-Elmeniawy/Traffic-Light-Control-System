/*
 * Registers.h
 *
 *  Created on: Jan 27, 2023
 *      Author: ahmad
 */

#ifndef INC_REGISTERS_H_
#define INC_REGISTERS_H_

#include "Types.h"

 /************** PORTA Registers **************/
#define DDRA		*((volatile uint8_t*) 0x3A)
#define PORTA		*((volatile uint8_t*) 0x3B)
#define PINA		*((const volatile uint8_t*) 0x39)

/************* PORTB Registers *************/
#define DDRB		*((volatile uint8_t*) 0x37)
#define PORTB		*((volatile uint8_t*) 0x38)
#define PINB		*((const volatile uint8_t*) 0x36)

/************* PORTC Registers *************/
#define DDRC		*((volatile uint8_t*) 0x34)
#define PORTC		*((volatile uint8_t*) 0x35)
#define PINC		*((const volatile uint8_t*) 0x33)

/************* PORTD Registers *************/
#define DDRD		*((volatile uint8_t*) 0x31)
#define PORTD		*((volatile uint8_t*) 0x32)
#define PIND		*((const volatile uint8_t*) 0x30)

/************* Status Register *************/
#define SREG		*((volatile uint8_t*) 0x5F)
#define SREG_I      7

/************* External Interrupt Registers *************/
#define MCUCR		*((volatile uint8_t*) 0x55)
#define MCUCSR		*((volatile uint8_t*) 0x54)
#define GICR		*((volatile uint8_t*) 0x5B)
#define GIFR		*((volatile uint8_t*) 0x5A)
#define MCUCR_ISC00 0
#define MCUCR_ISC01 1
#define MCUCR_ISC10 2
#define MCUCR_ISC11 3
#define MCUCSR_ISC2 6
#define GICR_INT2   5
#define GICR_INT0   6
#define GICR_INT1   7
#define GIFR_INTF2  5
#define GIFR_INTF0  6
#define GIFR_INTF1  7

/************* ADC Registers *************/
#define ADMUX		*((volatile uint8_t*) 0x27)
#define ADCSRA		*((volatile uint8_t*) 0x26)
#define ADCDATA		*((volatile u16*) 0x24)
#define ADCL		*((volatile uint8_t*) 0x24)
#define ADCH		*((volatile uint8_t*) 0x25)
#define SFIOR		*((volatile uint8_t*) 0x50)

/************* Timer/Counter Iterrupt *************/
#define TIMSK		*((volatile uint8_t*) 0x59)
#define TIFR		*((volatile uint8_t*) 0x58)

/************* Timer/Counter 0 *************/
#define TCCR0		*((volatile uint8_t*) 0x53)
#define TCNT0		*((volatile uint8_t*) 0x52)
#define OCR0		*((volatile uint8_t*) 0x5C)

/************* Timer/Counter 1 *************/
#define TCCR1A		*((volatile uint8_t*) 0x4F)
#define TCCR1B		*((volatile uint8_t*) 0x4E)

#define TCNT1		*((volatile uint16_t*) 0x4C)
#define TCNT1L		*((volatile uint8_t*) 0x4C)
#define TCNT1H		*((volatile uint8_t*) 0x4D)

#define OCR1A		*((volatile uint16_t*) 0x4A)
#define OCR1AL		*((volatile uint8_t*) 0x4A)
#define OCR1AH		*((volatile uint8_t*) 0x4B)

#define OCR1B		*((volatile uint16_t*) 0x48)
#define OCR1BL		*((volatile uint8_t*) 0x48)
#define OCR1BH		*((volatile uint8_t*) 0x49)

#define ICR1		*((volatile uint16_t*) 0x46)
#define ICR1L		*((volatile uint8_t*) 0x46)
#define ICR1H		*((volatile uint8_t*) 0x47)


/************* Timer/Counter 2 *************/
#define TCCR2		*((volatile uint8_t*) 0x45)
#define TCNT2		*((volatile uint8_t*) 0x44)
#define OCR2		*((volatile uint8_t*) 0x43)

/************* Watchdog Timer *************/
#define WDTCR		*((volatile uint8_t*) 0x41)

/************* UART *************/
#define UDR         *((volatile uint8_t*) 0x2C)
#define UCSRA		*((volatile uint8_t*) 0x2B)
#define UCSRB		*((volatile uint8_t*) 0x2A)
#define UCSRC		*((volatile uint8_t*) 0x40)
#define UBRRL		*((volatile uint8_t*) 0x29)
#define UBRRH		*((volatile uint8_t*) 0x40)

/************* SPI *************/
#define SPCR        *((volatile uint8_t*) 0x2D)
#define SPSR		*((volatile uint8_t*) 0x2E)
#define SPDR		*((volatile uint8_t*) 0x2F)

/************* I2C *************/
#define TWBR        *((volatile uint8_t*) 0x20)
#define TWCR		*((volatile uint8_t*) 0x56)
#define TWSR		*((volatile uint8_t*) 0x21)
#define TWDR        *((volatile uint8_t*) 0x23)
#define TWAR		*((volatile uint8_t*) 0x22)

#endif /* INC_REGISTERS_H_ */