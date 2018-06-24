#include "tarea_global.h"
#include "ordenarArrSec.h" //para traer el quicksort

void initOrdenParal(int* arr){
    #pragma omp parallel num_thread(parametros.nthread) private(th_id) {
        int size_thread = parametros.tamArray / parametros.nthread;
        ordenarArrParal(arr,size_thread,parametros.nthread); //primera vez que se llama
    }
}


void ordenarArrParal(int* arr, int size_thread, int nthread){

    #pragma omp_set_num_thread(nthread)
    th_id = omp_get_thread_num();

    inicio = size_thread * th_id;
    fin = inicio + size_thread;

    if(!(size_thread == parametros.tamArray)){ //Si el tamaño de segmento del thread aun no es igual al tamaño del arreglo
        quicksort(arr,inicio,size_thread - 1);
        #pragma omp barrier //barrera de contencion

        nthread/=2; //Se necesita la mitad de los thread
        size_thread*=2; //Se abarca el doble en tamaño de segmento

        //#pragma omp_set_num_threads(nthread);
        ordenarArrParal(arr,th_id,size_thread,nthread);

        //quicksort(array, 0, parametros.tamArray - 1);
    } else { //iteracion final se ordena el arreglo completo
        //single thread se encarga de ordenar el arreglo completo
        #pragma omp single
        quicksort(arr,0,parametros.tamArray-1); //Ultima revision se repasa el arreglo completo
    }
    //max num thread = tamArray

    
}