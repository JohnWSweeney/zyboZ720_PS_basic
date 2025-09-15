#include "time.h"

inline uint64_t ms_now(void){
	XTime t;
	XTime_GetTime(&t);
	return (uint64_t)((t * 1000ULL) / COUNTS_PER_SECOND);
}
