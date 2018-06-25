#include "tarea_global.h"
#include "check_args.h"

extern char *optarg;
extern int optind, opterr, optopt;

/*
 *		Funcion que imprime en stdout el uso
 *		del programa.
 */



void print_usage(char* name){
	char opciones[] = "-n tam_array -t nº threads -f archivo_nombre\n";

	char descripcion[] = "Descripción:\n"
	                     "-n   Tamaño Array\n"
	                     "-t   nº threads\n"
	                     "-f   nombre de archivo de output con los numeros ordenados\n";
	                     //"-s   semilla (test)\n";

	printf("Uso: %s %s\n%s\n", name, opciones, descripcion);
}
/* FIN print_usage()*/

void check_args(int argc , char **argv){
	int opcion;
	//std::string optString = "f:h";
	std::string optString = "n:t:f:h";

	parametros.nombreArchivo = "";

	while ((opcion = getopt (argc, argv, optString.c_str())) != -1){
		switch (opcion) {
			case 'n':
					parametros.tamArray = atoi(optarg);
					break;
			case 't':
					parametros.nThreads = atoi(optarg);
					break;
			case 'f':
					//parametros.nombreArchivo = malloc(strlen(optarg)*sizeof(char));
					//strcpy(parametros.nombreArchivo, optarg);
					parametros.nombreArchivo = optarg;
					break;
			/*case 's':
					parametros.seed = atoi(optarg);
					break;*/
			case 'h':
			default:
					print_usage(argv[0]);
					exit(EXIT_FAILURE);
		}
	}

	if ( parametros.nombreArchivo == "" ) { //caso que no pone nada
		print_usage(argv[0]);
		exit(EXIT_FAILURE);
	}
}
/* FIN check_args()*/
