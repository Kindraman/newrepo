#include "tarea_global.h"
#include "llenarArr.h"

void llenarArr(int* arr){
	for(int i=0;i<parametros.tamArray;i++){
		*arr = rand() % 100;
		arr++;
	}
}