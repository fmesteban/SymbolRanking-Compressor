#ifndef FILEMANAGER_H_
#define FILEMANAGER_H_
#include <iostream>
#include <string>
#include <stdio.h>
#include <stdlib.h>
#include <cstdio>
#include <cstddef>
using namespace std;

template <typename dato>
class FileManager {
	public:
		FileManager(){

		}
		/* Dado un filename, lo abre y vuelca su contenido en el buffer.
		 * Precondiciones:
		 *  -fileIn debe ser un nombre de archivo valido, ubicado en el mismo directorio del
		 *   proyecto
		 *  -buffer todavia no contemplo la cantidad de memoria necesaria
		 *  Postcondiciones:
		 *  -El metodo modifica el array buffer, agregando el total del contenido del archivo a procesar.
		 *   el tipo de dato del buffer va a depender del tipo de datos que contenga el file a cargar en memoria.
		 *   char si se trata del compresor o unsigned short si se trata del descompresor
		*/
		dato* processFile(char* filename){
			FILE* fileIn;
			unsigned long lSize;
			unsigned int result;
			dato* buffer;

			fileIn = fopen(filename, "rb");
			if (!fileIn){fputs ("File error",stderr); exit(1);}

			//obtain file size:
			fseek (fileIn , 0 , SEEK_END);
			lSize = ftell (fileIn);
			rewind (fileIn);

			// allocate memory to contain the whole file:
			buffer = (dato*) malloc (lSize);
			if (buffer == NULL) {fputs ("Memory error",stderr); exit (2);}

			// copy the file into the buffer:
			result = fread (buffer,1,lSize,fileIn);
			if (result != lSize) {fputs ("Reading error",stderr); exit (3);}

			/* the whole file is now loaded in the memory buffer. */
			fclose (fileIn);
			return buffer;
		}

		unsigned long getSize(char* filename){
			FILE* fileIn;
			unsigned long lSize;

			fileIn = fopen(filename, "rb");
			if (!fileIn){fputs ("File error",stderr); exit(1);}

			//obtain file size:
			fseek (fileIn , 0 , SEEK_END);
			lSize = ftell (fileIn);

			return lSize;
		}

		/*
		 * Dado el nombre del archivo a procesar, ya sea a comprimir o descomprimir, se crea el archivo
		 * en donde se guararan los resultados.
		 * Precondiciones:
		 *  -filename debe ser un nombre de archivo valido, ubicado en el mismo directorio del
		 *   proyecto
		 * Postcondiciones:
		 *  -devuelve un FILE* apuntando al archivo de salida creado
		 */
		FILE* createFileOut(char* filename){
			return NULL;
		}
};

#endif /* FILEMANAGER_H_ */
