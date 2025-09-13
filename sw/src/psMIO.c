#include "psMIO.h"

void initMIO(mioStruct *s){
	XGpioPs_Config *cfg = XGpioPs_LookupConfig(XPAR_PS7_GPIO_0_DEVICE_ID);
	XGpioPs_CfgInitialize(&s->gpioPS, cfg, cfg->BaseAddr);
	XGpioPs_SetDirectionPin(&s->gpioPS, s->mioLED, 1);
	XGpioPs_SetOutputEnablePin(&s->gpioPS, s->mioLED, 1);
	XGpioPs_WritePin(&s->gpioPS, s->mioLED, 0);

	for(int i=0;i<8;i++){
		 XGpioPs_SetDirectionPin(&s->gpioPS, s->mioPmod[i], 1);
		 XGpioPs_SetOutputEnablePin(&s->gpioPS, s->mioPmod[i], 1);
		 XGpioPs_WritePin(&s->gpioPS, s->mioPmod[i], 0);
	 }
};
