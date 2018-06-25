#include "tarea_global.h"
#include "writeToFile.h"
using namespace std;

void writeToFile (int* arr, int* arr2) { //arr1 secuencial //arr2 paralelo

  ofstream myfile (parametros.nombreArchivo);
  if (myfile.is_open())
  {
    myfile << "Arreglo Secuencial.\n";
    for(int count = 0; count < parametros.tamArray; count ++){
        myfile << arr[count] << " " ;
    }
    myfile << "\n";
    myfile << "Arreglo Paralelo.\n";
    for(int count = 0; count < parametros.tamArray; count ++){
        myfile << arr2[count] << " " ;
    }

    myfile.close();
  }
  else cout << "Unable to open file";
}