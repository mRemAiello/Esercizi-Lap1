/*
 * File:   main.c
 * Author: Rem
 *
 * Created on 17 gennaio 2013, 8.48
 */

#define _XTAL_FREQ   8000000

#include <xc.h>
#include <pic16f690.h>
#include <delays.h>
#include <stdio.h>

// PIC16F690 Configuration Bit Settings

// CONFIG
#pragma config FOSC = INTRCIO   // Oscillator Selection bits (INTOSCIO oscillator: I/O function on RA4/OSC2/CLKOUT pin, I/O function on RA5/OSC1/CLKIN)
#pragma config WDTE = OFF       // Watchdog Timer Enable bit (WDT disabled and can be enabled by SWDTEN bit of the WDTCON register)
#pragma config PWRTE = OFF      // Power-up Timer Enable bit (PWRT disabled)
#pragma config MCLRE = ON       // MCLR Pin Function Select bit (MCLR pin function is MCLR)
#pragma config CP = OFF         // Code Protection bit (Program memory code protection is disabled)
#pragma config CPD = OFF        // Data Code Protection bit (Data memory code protection is disabled)
#pragma config BOREN = ON       // Brown-out Reset Selection bits (BOR enabled)
#pragma config IESO = ON        // Internal External Switchover bit (Internal External Switchover mode is enabled)
#pragma config FCMEN = ON       // Fail-Safe Clock Monitor Enabled bit (Fail-Safe Clock Monitor is enabled)

#define OFF   0
#define ON    1

unsigned adc, t_on, t_off;

void putch(unsigned char byte)
{
    /* output one byte */
    TXREG = byte;
    while(!TXSTAbits.TRMT) ;   /* set when register is empty */
}

void interrupt isr(void) {
    if (PIR1bits.CCP1IF == 1) {
        TMR1H = 0; TMR1L = 0; /* reset H/L bits Timer1 */
        if (CCP1CON == 0x08){
            CCP1CON = 0x09;
            /* setto il valore nei due registri a 8 bit **/
            CCPR1H = t_on >> 8;
            CCPR1L = t_on & 0xFF;
            //CCPR1 = 37500 --> 15ms
        }
        else {
            CCP1CON = 0x08;
            /* setto il valore nei due registri a 8 bit **/
            CCPR1H = t_off >> 8;
            CCPR1L = t_off & 0xFF;
            //CCPR1 = 12500 --> 5ms
        }
        PIR1bits.CCP1IF = 0;
    }
}

void main() {
    OSCCONbits.IRCF = 0b111;  // 8 Mhz clock

    ANSEL = 0;   // no analog inputs
    ANSELH = 0;

    TRISCbits.TRISC5 = 0; /* configure CCP1 pin port for output */

    OPTION_REGbits.T0CS = 0;
    OPTION_REGbits.PS = 0b110;
    OPTION_REGbits.PSA = 0;

    /** da settare */
    CCP1CON = 0x09; //Clear RC2 on match
    CCPR1H = 0x92;
    CCPR1L = 0x7C;
    //CCPR1 = 37500 --> 15ms

    PIE1bits.CCP1IE = 1; // global interrupt enable
    INTCONbits.GIE = 1;
    INTCONbits.PEIE = 1; // CCP interrupt
    T1CON = 0x21; //Prescaler 1:2, start Timer 1

    /* configure ADC */
    ANSELbits.ANS0 = 1; // AN0 on pin 19

    ADCON0bits.ADFM = 1;  // right justified
    ADCON0bits.VCFG = 0;  // Reference = VDD
    ADCON0bits.CHS = 0;   // Select channel 0
    ADCON0bits.ADON = 1;  // turn adc ok

    ADCON1bits.ADCS = 0b111;   // ADC clock = FOSC/64

    while(1){
        ADCON0bits.GO = 1; // start conversion
        while (ADCON0bits.GO == 1); // wait for end of conversion

        adc = (ADRESH << 8) + ADRESL;
        /** normalize the t_on, then multiply for 5 (0,5ys)
         * and divide for 2 (prescaler) **/
        t_on = adc + 432;
        t_off = 10000 - t_on;
    }
}

