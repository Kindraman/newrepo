
#include "tarea_global.h"
#include "time_manager.h"

double timing(clock_t startTime, clock_t endTime){
	return ((double)(endTime - startTime)) / CLOCKS_PER_SEC;
}