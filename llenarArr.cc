#include "global.h"
#include "llenarArr.h"

void llenarArr(int* arr){
	srand (time(NULL)); //arreglo aleatorio
	for(int i=0;i<parametros.tamArray;i++){
		*arr = rand() % 100;
		arr++;
	}
}