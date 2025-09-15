#include "time.h"
#include "psMIO.h"

void mioLedBlink(mioStruct *s,
						u32 period,
						uint64_t now,
						uint64_t *next,
						u32 *mioLEDstatus);
