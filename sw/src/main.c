#include "xgpiops.h"
#include "xparameters.h"
#include <stdio.h>
#include <stdlib.h>
#include "time.h"
#include "psMIO.h"
#include "debug.h"

int main(void){
	mioStruct s = {
		.mioLED = 7,
		.mioPmod = {13, 10, 11, 12, 0, 9, 14, 15}
	};
	initMIO(&s);
	/// test code variables
	static u32 mioLEDstatus = 0;
	static const u32 period1 = 250;
	uint64_t next1 = ms_now() + period1;
	printf("entering while loop.\n");

	while(1){
		uint64_t now = ms_now();
		mioLedBlink(&s, period1, now, &next1, &mioLEDstatus);
	}
}
