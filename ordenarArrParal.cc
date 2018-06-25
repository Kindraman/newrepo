#include "tarea_global.h"
#include "ordenarArrSec.h" //para traer el quicksort


void ordenarParal(int* arr, int size_thread, int nthreads)
{
    omp_set_num_threads(nthreads);
    int th_id;
    int inicio, fin;
   // printf("\nnthreadT:%d vs nthreadp:%d, nthreads_param:%d\n",parametros.nThreads,omp_get_num_threads(),nthreads);
    #pragma omp parallel private(th_id,inicio,fin) firstprivate(size_thread,nthreads) shared(arr) 
    {

        //ordenarArrParal(arr,size_thread,parametros.nthread); //primera vez que se llama
        th_id = omp_get_thread_num();

        inicio = size_thread * th_id;
        fin = inicio + size_thread;
        //printf("Thread nº:%d, inicio:%d, fin:%d\n",omp_get_thread_num(),inicio,fin);
        if(!(size_thread == parametros.tamArray)){ //Si el tamaño de segmento del thread aun no es igual al tamaño del arreglo
            quicksort(arr,inicio,fin - 1);
            #pragma omp barrier //barrera de contencion

            nthreads/=2; //Se necesita la mitad de los thread
            size_thread*=2; //Se abarca el doble en tamaño de segmento
            ordenarParal(arr,size_thread,nthreads);
        } else { //iteracion final se ordena el arreglo completo
            //single thread se encarga de ordenar el arreglo completo
            #pragma omp single
            quicksort(arr,0,parametros.tamArray-1); //Ultima revision se repasa el arreglo completo
            //#pragma omp_barrier
            
        }
    }
    
}