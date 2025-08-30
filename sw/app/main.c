#include "xgpiops.h"
#include "xparameters.h"
#include "sleep.h"
#include <stdio.h>

int main(void){
	// define PS MIO LED and Pmod J4 pins.
	static const u32 mioLED = 7;
	static const u32 mioPmod[8] = {13, 10, 11, 12, 0, 9, 14, 15};

	// initialize PS MIO GPIO.
	XGpioPs gpiops;
	XGpioPs_Config *cfg = XGpioPs_LookupConfig(XPAR_XGPIOPS_0_DEVICE_ID);
	XGpioPs_CfgInitialize(&gpiops, cfg, cfg->BaseAddr);

	// initialize MIO LED pin as output, set low.
	XGpioPs_SetDirectionPin(&gpiops, mioLED, 1);
	XGpioPs_SetOutputEnablePin(&gpiops, mioLED, 1);
	XGpioPs_WritePin(&gpiops, mioLED, 0);

	// initialize MIO Pmod J4 pins as outputs, set low. Pmod 8LD connected.
	for(int i=0;i<8;i++){
		XGpioPs_SetDirectionPin(&gpiops, mioPmod[i], 1);
		XGpioPs_SetOutputEnablePin(&gpiops, mioPmod[i], 1);
		XGpioPs_WritePin(&gpiops, mioPmod[i], 0);
	}

	printf("entering while loop.\n");
	static u32 mioLEDstatus = 0;;
	static u8 idx = 0;
	static u8 dir = 0;
	static u8 incr = 1;

	while(1){
		// blink mioLED every 500ms
		if(incr == 5)
		{
			mioLEDstatus ^= 1;
			XGpioPs_WritePin(&gpiops, mioLED, mioLEDstatus);
			incr = 0;
		}

		// ping pong 8LD Pmod, shift every 100ms.
		for(int i=0;i<8;i++){
			XGpioPs_WritePin(&gpiops, mioPmod[i], 0);
		}
		XGpioPs_WritePin(&gpiops, mioPmod[idx], 1);

		if(dir == 0){
			idx++;
		} else{
			idx--;
		}

		if(idx == 7){
			dir = 1;
		} else if(idx == 0){
			dir = 0;
		}

		incr++;
		usleep(100000); // 100ms
	}
}
