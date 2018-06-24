#include "tarea_global.h"
#include "check_args.h"
#include "llenarArr.h"
#include "ordenarArrSec.h"
#include "time_manager.h"
//#include "indexInvertido.h"


using namespace std;

struct args_t  parametros;
int main(int argc , char *argv []) {
	//std::chrono::time_point<std::chrono::high_resolution_clock> t_start, t_end1, t_end2, t_end3;
	clock_t start_time;
    clock_t end_time;
    double total_time;
    
	//Seccion preparativa: obtiene argumentos y llena el arreglo tamaño N con numeros aleatorios (int)
	check_args(argc, argv);
	int *arr = new int[parametros.tamArray];
	llenarArr(arr); //el arreglo se llena
	//Fin sección

	//hay que copiar array en otro array
	int* arr2 = new int[parametros.tamArray];
	for(int i=0;i< parametros.tamArray;i++){
		*arr2 = *arr
		arr2++;
		arr++;
	}

	//Seccion que imprime arreglo desordenado
	cout << "Array1 antes de ordenarse: " << endl;
    for (int i = 0; i < parametros.tamArray; i++) {
        cout << arr[i] << " ";
    }
    cout << endl << endl;
    //Fin sección

    //Seccion que imprime arreglo desordenado
	cout << "Array2 antes de ordenarse: " << endl;
    for (int i = 0; i < parametros.tamArray; i++) {
        cout << arr2[i] << " ";
    }
    cout << endl << endl;
    //Fin sección

    //Seccion de ordenamiento del Array y calculo tiempo de procesamiento #Secuencial#
    start_time = clock();
    ordenarArrSec(arr); //implementado con quicksort
    end_time = clock();
    total_time = timing(start_time,end_time);
    printf("Tiempo de ejecucion secuencial : %lf segundos \n", total_time);
    //Fin sección

    //Seccion que imprime arreglo ordenado
	cout << "Array despues de ordenarse: " << endl;
    for (int i = 0; i < parametros.tamArray; i++) {
        cout << arr[i] << " ";
    }
    cout << endl << endl;
    //Fin sección

    /*
    //Seccion de ordenamiento del Array y calculo tiempo de procesamiento #Paralelo#
    start_time = clock();
    initOrdenParal(arr); //implementado con quicksort
    end_time = clock();
    total_time = timing(start_time,end_time);
    printf("Tiempo de ejecucion secuencial : %lf segundos \n", total_time);
    //Fin sección
    */

    /*

	printf("%d\n,%d\n,%d\n,%s\n",parametros.tamArray,parametros.nThreads,parametros.seed,parametros.nombreArchivo);
	*/
	//tablaVocabulario tabla(archivoIndice);
	//tabla.mostrar();



	return(EXIT_SUCCESS);
}
