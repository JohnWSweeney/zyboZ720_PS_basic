#include "debug.h"

inline void mioLedBlink(mioStruct *s,
						 u32 period,
						 uint64_t now,
						 uint64_t *next,
						 u32 *mioLEDstatus){
	 if ((int64_t)(now - *next) >= 0){
		 *mioLEDstatus ^= 1U;
		 XGpioPs_WritePin(&s->gpioPS, s->mioLED, *mioLEDstatus);
		 *next += period;
	 }
 }
