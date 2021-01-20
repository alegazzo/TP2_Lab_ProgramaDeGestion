#include <iostream>
#include <cstdlib>
#include <ctime>
#include<cstdio>
#include<cstring>

 using namespace std;

#include "Fecha.h"

Fecha :: Fecha (){
      time_t t;
    struct tm *f;
    t = time(NULL);
    f = localtime(&t);
    anio = f->tm_year+1900;
    mes  = f->tm_mon+1;
    dia  = f->tm_mday;
}

int Fecha::getDia(){
     return dia;
}
int Fecha::getMes(){
     return mes;
}
int Fecha::getAnio(){
     return anio;
}

void Fecha :: mostrarFecha(){
 cout<<dia<<" / "<<mes<<" / "<<anio<<endl;
}
