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
	printf("entering while loop.\n");
	srand(666);

	while(1){
		if(timer1==500){
			mioLEDstatus ^= 1;
			XGpioPs_WritePin(&s.gpioPS, s.mioLED, mioLEDstatus);
			timer1 = 0;
		}
		//
		if(timer2==100){
			for(int i=0;i<8;i++){
				u8 rando = rand() % 2;
				XGpioPs_WritePin(&s.gpioPS, s.mioPmod[i], rando);
			}
			timer2 = 0;
		}
		//
		timer1++;
		timer2++;
		usleep(1000); // 1ms
	}
}
