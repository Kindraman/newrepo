#include "global.h"
#include "writeToFile.h"
using namespace std;

void writeToFile (int* arr, int* arr2, double speedUp) { //arr1 secuencial //arr2 paralelo

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
  


  ifstream timefile ("tiempos2.txt");
  if (timefile) {
    // The file exists, and is open for input
    ofstream timefile2;
    timefile2.open("tiempos.txt", std::ios_base::app);
    timefile2 << "\nTiempo speedUp: "<< speedUp;
    //timefile2.close();

  } else {
    ofstream myfile2 ("tiempos2.txt");
    myfile2 << "#TiemposParalelos";
    if (myfile2.is_open()){
      myfile2 << "\nTiempo speedUp: "<< speedUp;
      myfile2.close();
    } else cout << "Unable to writefile2";
  }
  

    

}