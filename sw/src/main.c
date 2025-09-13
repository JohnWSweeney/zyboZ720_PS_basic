#include "xgpiops.h"
#include "xparameters.h"
#include "sleep.h"
#include <stdio.h>
#include <stdlib.h>
#include "psMIO.h"

int main(void){
	mioStruct s = {
		.mioLED = 7,
		.mioPmod = {13, 10, 11, 12, 0, 9, 14, 15}
	};
	initMIO(&s);

	/// test code variables
	static u32 mioLEDstatus = 0;
	static u32 timer1 = 0;
	static u32 timer2 = 0;
	static u8 idx = 0;
	static u8 dir = 0;
	printf("entering while loop.\n");

	while(1){
		if(timer1==500){
			mioLEDstatus ^= 1;
			XGpioPs_WritePin(&s.gpioPS, s.mioLED, mioLEDstatus);
			timer1 = 0;
		}
		//
		if(timer2==50){
			// turn off all LEDs.
			for(int i=0;i<8;i++){
				XGpioPs_WritePin(&s.gpioPS, s.mioPmod[i], 0);
			}
			// turn on LED at index.
			XGpioPs_WritePin(&s.gpioPS, s.mioPmod[idx], 1);
			// reverse ping pong direction at edges.
			if(idx==7){
				dir = 1;
			}else if(idx==0){
				dir = 0;
			}
			// increment/decrement index depending on ping pong direction.
			if(dir==0){
				idx++;
			}
			else{
				idx--;
			}
			//
			timer2 = 0;
		}
		//
		timer1++;
		timer2++;
		usleep(1000); // 1ms
	}
}
