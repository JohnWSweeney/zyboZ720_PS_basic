#ifndef PSMIO_U
#define PSMIO_U

#include "xgpiops.h"

typedef struct{
	XGpioPs gpioPS;
	u32 mioLED;
	u32 mioPmod[8];
} mioStruct;

void initMIO(mioStruct *s);

#endif
