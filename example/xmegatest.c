// Demo USB device for ATxmega32a4u
// (C) 2011 Kevin Mehall (Nonolith Labs) <km@kevinmehall.net>
//
// Licensed under the terms of the GNU GPLv3+

#include "xmegatest.h"

unsigned int timer = 15625; // 500ms

int main(void){

	PORTE.DIRSET = (1<<0) | (1<<1);
	PORTE.OUTSET = (1<<0);
	
	SetupHardware();

	sei();
	
	TCC0.CTRLA = TC_CLKSEL_DIV1024_gc; // 31.25KHz = 0.032ms
	
	
	while (1){
		while(TCC0.CNT < timer){ 
			USB_Task();
		}
		PORTE.OUTTGL = (1<<0);
    	TCC0.CNT=0;
	}
}



/** Configures the board hardware and chip peripherals for the project's functionality. */
void SetupHardware(void)
{    
	USB_ConfigureClock();
	USB_Init();
}

/** Event handler for the library USB Control Request reception event. */
void EVENT_USB_Device_ControlRequest(void)
{

}

