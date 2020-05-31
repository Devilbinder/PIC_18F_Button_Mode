#include <xc.h>
#include <pic18f4520.h>
#include "conbits.h"

char run = 1;
char tracking = 0;

void main(void) {
    TRISB=0; //0b00000000
    TRISDbits.RD7=1; //0b10000000
    TRISDbits.RD6=1; //0b11000000
    
    LATB=0; //0b00000000
   
    while(1){
        
        if(PORTDbits.RD7==1){ //0b10000000
            __delay_ms(250);
            if(tracking == 0){
                tracking = 1;
            }else if(tracking == 1){
                tracking = 0;
            }
            while(PORTDbits.RD7==1);
        }
        
        if(run >= 0x80){ //0b10000000
			run = 1;
		}else{
			run *= 2; //0b00001000
        }
        if(tracking == 0){
            LATB=run; 
        }
        if(tracking == 1){
            LATB=~run;     
        }
        
        __delay_ms(250);
    }
    
}
