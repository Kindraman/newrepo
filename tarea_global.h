#ifndef _GLOBAL_H_
#define _GLOBAL_H_

#include <cstdio>
#include <iostream>
#include <cstdlib>
#include <string>
#include <fstream>
#include <iomanip>
#include <list>
#include <forward_list>
#include <deque>
#include <chrono>
#include <unistd.h>
#include <stdio.h>
#include <string.h>
#include <omp.h>
#include <iostream>
#include <fstream>


struct args_t {

	int tamArray;
	int nThreads;
	//int seed;
    char* nombreArchivo;
};

extern struct args_t parametros;


#endif
