#include "global.h"
#include "check_args.h"
#include "llenarArr.h"
#include "ordenarArrSec.h"
#include "ordenarArrParal.h"
#include "time_manager.h"
#include "writeToFile.h"
//#include "indexInvertido.h"


using namespace std;

struct args_t  parametros;
int main(int argc , char *argv []) {
    //std::chrono::time_point<std::chrono::high_resolution_clock> t_start, t_end1, t_end2, t_end3;
    clock_t start_time;
    clock_t end_time;
    double total_time1, total_time2;
    
    //Seccion preparativa: obtiene argumentos y llena el arreglo tamaño N con numeros aleatorios (int)
    check_args(argc, argv);
    int *arr = new int[parametros.tamArray];
    llenarArr(arr); //el arreglo se llena
    //Fin sección

    //hay que copiar array en otro array
    int* arr2 = new int[parametros.tamArray];
    for(int i=0;i< parametros.tamArray;i++){
        arr2[i] = arr[i];
    }

    //Seccion que imprime arreglo desordenado
    /*
    cout << "Array1 antes de ordenarse: " << endl;
    for (int i = 0; i < parametros.tamArray; i++) {
        cout << arr[i] << " ";
    }
    cout << endl << endl;
    */
    //Fin sección

    //Seccion que imprime arreglo desordenado
    /*
    cout << "Array2 antes de ordenarse: " << endl;
    for (int i = 0; i < parametros.tamArray; i++) {
        cout << arr2[i] << " ";
    }
    cout << endl << endl;
    */
    //Fin sección

    //Seccion de ordenamiento del Array y calculo tiempo de procesamiento #Secuencial#
    start_time = clock();
    ordenarArrSec(arr); //implementado con quicksort
    end_time = clock();
    total_time1 = timing(start_time,end_time);
    printf("\nTiempo de ejecucion secuencial : %lf segundos \n", total_time1);
    //Fin sección

    //Seccion que imprime arreglo ordenado
    /*
    cout << "Array1 despues de ordenarse: " << endl;
    for (int i = 0; i < parametros.tamArray; i++) {
        cout << arr[i] << " ";
    }
    cout << endl << endl;
    */
    //Fin sección

    
    //Seccion de ordenamiento del Array y calculo tiempo de procesamiento #Paralelo#
    start_time = clock();
    int size_thread = parametros.tamArray / parametros.nThreads;
    ordenarParal(arr2,size_thread,parametros.nThreads); //implementado con quicksort
    end_time = clock();
    total_time2 = timing(start_time,end_time);
    printf("\nTiempo de ejecucion paralelo : %lf segundos \n", total_time2);
    //Fin sección
    
    //Seccion que imprime arreglo_sec y arreglo_paral en archivo de nombre ingresado
    

    double speedUp = total_time1 / total_time2;
    printf("\nEl SpeedUp es de: %f\n",speedUp);
    writeToFile(arr,arr2, speedUp);

    //Seccion que imprime arreglo desordenado
    /*
    cout << "Array2 despues de ordenarse: " << endl;
    for (int i = 0; i < parametros.tamArray; i++) {
        cout << arr2[i] << " ";
    }
    cout << endl << endl;
    */
    //Fin sección

    /*

    printf("%d\n,%d\n,%d\n,%s\n",parametros.tamArray,parametros.nThreads,parametros.seed,parametros.nombreArchivo);
    */
    //tablaVocabulario tabla(archivoIndice);
    //tabla.mostrar();



    return(EXIT_SUCCESS);
}
