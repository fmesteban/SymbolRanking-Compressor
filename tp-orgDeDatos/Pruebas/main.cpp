#include <iostream>
#include "FileManager/FileManager.h"
#include "Compresor/Compresor.h"

using namespace std;

//const long megaByte = 1024*1024;
const unsigned char orden = 3;

int main(int argc,char *argv[]){

	//Variables de argv--> comprime/descomprime, archivo entrada, archivo salida
	//Ver opcion de que el usuario indique el orden del contexto maximo.

	char* operacionARealizar = argv[1];
	char* nombreDelArchivo = argv[2];
	FILE* fileOut;

	FileManager fileManager;
	char* buffer = fileManager.processFile(nombreDelArchivo);
	unsigned long size = fileManager.getSize(nombreDelArchivo);

	cout << "El archivo ha sido abierto y colocado en memoria correctamente" << endl;

	/*
	*Se instancia la clase Compresor, pasandole como parametro el buffer
	*
	*Se instancia a compresor.comprimir() o compresor.descomprimir() de
	* acuerdo al parametro pasado por el usuario
	*/

	Compresor compresor;
	if (*operacionARealizar == 'c'){
		compresor.comprimir(buffer,size);
	}
	//else if(operacionARealizar[1]=='d')compresor.descomprimir(buffer,size);

	/*
	 * Luego de la instancia de compresion/descompresion se llama al file
	 * Manager para que guarde los resultados en el archivo de salida
	 */

	return 0;
}



