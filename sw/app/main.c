#include <stdio.h>
#include "xil_printf.h"
#include "xparameters.h"
#include "xil_io.h"
#include "xgpiops.h"
#include "sleep.h"


int main()
{
	XGpioPs Gpio;
	XGpioPs_Config *Config;
	u32 Pin = 7;

	Config = XGpioPs_LookupConfig(XPAR_PS7_GPIO_0_DEVICE_ID);
	XGpioPs_CfgInitialize(&Gpio, Config, Config->BaseAddr);

	XGpioPs_SetDirectionPin(&Gpio, Pin, 1);
	XGpioPs_SetOutputEnablePin(&Gpio, Pin, 1);

	while(1)
	{
		print("hellyeah\n\r");
		XGpioPs_WritePin(&Gpio, Pin, 1);
		usleep(200000);
		XGpioPs_WritePin(&Gpio, Pin, 0);
		usleep(200000);

		print("fuckinright\n\r");
		XGpioPs_WritePin(&Gpio, Pin, 1);
		usleep(100000);
		XGpioPs_WritePin(&Gpio, Pin, 0);
		usleep(100000);
	}
}
