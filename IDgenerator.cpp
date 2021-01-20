#include <iostream>
#include <cstdlib>
#include <ctime>
#include<cstdio>
#include<cstring>

 using namespace std;

#include"rlutil.h"
 #include"funcionesGlobales.h"
 #include "Clientes.h"
#include"funcionesGlobales.h"
#include "compra.h"
#include "IDgenerator.h"

int IDGenerator :: generatePos(){
      int cantidad;
	FILE* pFile;

	pFile = fopen("ARCHIVOS/Compras.dat", "rb");

	if (pFile == NULL) {
            cantidad = 0;
            pos = 0;
            return cantidad;
	}

	fseek(pFile, 0, SEEK_END);
	cantidad = ftell(pFile) / sizeof(compra);
	fclose(pFile);
	pos = cantidad;
	return cantidad;
}

int IDGenerator :: generateID(){
      int autonumerico ;
	FILE* pFile;

	pFile = fopen("ARCHIVOS/archivoDeID.dat", "rb");

	if (pFile == NULL) {
            ID = 1;
            return ID;
	}

	fseek(pFile, 0, SEEK_END);
	autonumerico = ftell(pFile) / sizeof(IDGenerator);
	fclose(pFile);
      ID = autonumerico+1;
	return ID;
}

bool IDGenerator :: grabarEnDisco(){

      FILE *puntero;
      puntero = fopen("ARCHIVOS/archivoDeID.dat", "ab");
      if(puntero == NULL) {
            return false;
      }
      fwrite(this, sizeof(IDGenerator), 1, puntero);
      fclose(puntero);
      return true;
}

bool IDGenerator :: leerDisco(int pos){

      FILE *puntero;
      bool bandera;
      puntero = fopen("ARCHIVOS/archivoDeID.dat", "rb");
      if(puntero == NULL) {
            return false;
      }
      fseek(puntero, sizeof(IDGenerator)*pos, SEEK_SET);
      bandera = fread(this, sizeof(IDGenerator), 1, puntero);
    fclose(puntero);
    return bandera;
}


int IDGenerator :: getID(){
      return ID;
}

int IDGenerator :: getPos(){
      return pos;
}

