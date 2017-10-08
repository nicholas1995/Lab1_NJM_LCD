#include<p18f452.h>
#include<delays.h>
#include"xlcd.h"



#pragma config OSC = HS
#pragma config WDT = OFF
#pragma config LVP = OFF

void DelayFor18TCY( void )
{
    Delay1TCY();
    Delay1TCY();
    Delay1TCY();
    Delay1TCY();
    Delay1TCY();
    Delay1TCY();
    Delay1TCY();
    Delay1TCY();
    Delay10TCYx(1);
}

void DelayPORXLCD (void)
{
 Delay10KTCYx(6);
}

void DelayXLCD (void)
{
 Delay10KTCYx(2); 
}

void init_LCD(void){
    OpenXLCD( FOUR_BIT & LINES_5X7 );
    while( BusyXLCD() );
    WriteCmdXLCD( FOUR_BIT & LINES_5X7 );
    while( BusyXLCD() );
    WriteCmdXLCD( BLINK_ON );
    while( BusyXLCD() );
    WriteCmdXLCD( SHIFT_DISP_LEFT );
}
void main(void){
    init_LCD();
    while( BusyXLCD() );
    SetDDRamAddr( 0x40 );
    putrsXLCD( "HELLO WORLD " );
    while(1){}
    
}