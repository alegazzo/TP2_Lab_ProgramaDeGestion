#include <iostream>
#include <cstdlib>
#include <ctime>
#include<cstdio>
#include<cstring>

 using namespace std;

#include "funcionesGlobales.h"

void mensajeError( char mensaje[70]){
      system("cls");
      system("color 4F");
      cout<<mensaje<<endl;
      system("pause");
      system("cls");

 }

void mensajeExito(char mensaje[70]){
      system("cls");
      system("color 2F");
      cout<<mensaje<<endl;
      system("pause");
      system("cls");
 }

 bool validarCadena(char *cadena) {
      int contador;
      int x, cant;

      contador = 0;
     cant =  strlen(cadena);

      for (x= 0; x<cant; x++){
          if (cadena[x]== ' ' ) {
                contador++;
            }
      }
      if (contador == cant) {
          return false;
      }
      else {
            return true;
      }
}


