#include <stdio.h>
#include <stdlib.h>
#include <xc.h>
#pragma config FOSC = INTOSCIO
#pragma config WDTE = OFF // (WDT desativado)
int main(int argc, char** argv) {
int adc;
STATUS = 0b00011100;
OPTION_REG = 0b10000000;
OSCCON = 0b01110101;
ANSEL = 0b01011001;
PR2 = 0b00011000 ;//PWM
T2CON = 0b00000101 ;//PWM
TRISIO = 0b00111001;
CCP1CON = 0b00001100 ; // DUTY CYCLE
//CCP1CON = 0b00XX1100 ; // DUTY CYCLE
//ADCON0 = 0b10000011; //AN0
for(;;){
//AN3
if(ADCON0==0b10001101){
adc=ADRESH;
adc=adc<<8;
adc=adc+ADRESL;
CCPR1L = adc>>2;
CCP1CON=(CCP1CON&0b11100111);
CCP1CON=(CCP1CON|=((adc&0x0003)<<4));
ADCON0 = 0b10001111;
}
//CCPR1L = 0bXXXXXXXX ; // DUTY CYCLE
//CCP1CON = 0b00XX1100 ; // DUTY CYCLE
}
}
