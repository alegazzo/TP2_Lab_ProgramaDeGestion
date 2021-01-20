#include <iostream>
#include <cstdlib>
#include <ctime>
#include<cstdio>
#include<cstring>
#include <iomanip>

 using namespace std;

 #include"rlutil.h"
 #include"funcionesGlobales.h"
 #include "Clientes.h"
void Cliente::setCodCliente(){
 int cantidad;
	FILE* pFile;

	pFile = fopen("ARCHIVOS/Clientes.dat", "rb");

	if (pFile == NULL) {
            cantidad = 1;
            idCliente=cantidad;
            return;
	}

	fseek(pFile, 0, SEEK_END);
	cantidad = ftell(pFile) / sizeof(Cliente);
	fclose(pFile);
	idCliente=cantidad+1;
}


 void Cliente :: setDni(){
int documento;
 cout << "INGRESE NRO DE DNI DEL CLIENTE: ";
 cin >> documento;

 while(documento <= 0 || (documento/10000000)<1) {      /// un DNI tiene 8 cifras. si es menor a 8 cifras, la división con 10000000 va dar menos de uno.
    mensajeError("ERROR REINGRESE DNI");
    system("color 0F");
    cout << "REINGRESE NRO DE DNI DEL CLIENTE: ";
    cin >> documento;
 }
dni = documento;

}

 void Cliente :: setNombre(){
    bool bandera=false;
   char name[70];
   cout<<"INGRESE NOMBRE: ";
   cin.getline(name, 70);
   bandera= validarCadena(name);
      while(bandera==false){

          mensajeError("ERROR DE DATO");
            system("color 0F");
           cout<<"INGRESE NOMBRE:  ";
           cin.getline(name, 70);
           bandera=validarCadena(name);
      }
     strcpy(nombre, name);
}






void Cliente::setApellido(){
     bool bandera=false;
   char name[70];
   cout<<"INGRESE APELLIDO: ";
   cin.getline(name, 70);
   bandera= validarCadena(name);
      while(bandera==false){

          mensajeError("ERROR DE DATO");
            system("color 0F");
           cout<<"INGRESE APELLIDO:  ";
           cin.getline(name, 70);
           bandera=validarCadena(name);
      }
     strcpy(apellido, name);
}






void Cliente::setNumTelefono(){
 int telefono;
 cout << "INGRESE NRO DE TELEFONO DEL CLIENTE: ";
 cin >> telefono;

 while(telefono <= 0||(telefono / 10000000)<1 ){
    mensajeError("ERROR TELEFONO ERRONEO");
    system("color 0F");
    cout << "REINGRESE NRO DE TELEFONO DEL CLIENTE: ";
    cin >> telefono;
 }
numTelefono = telefono;

}


void Cliente::setEstado(bool state){

estado = state;

}

char * Cliente::getNombre(){

return nombre;
}


char * Cliente::getApellido(){

return apellido;
}

int Cliente::getDni (){
return dni;

}

int  Cliente:: getNumTelefono(){
    return numTelefono;

}

bool Cliente::getEstado(){

return estado;

}

int Cliente::getPosicion(int documento){
int pos = 0;

while(leerDeDisco(pos)) {
            if(this->dni== documento){
               return pos;
            }
        pos ++;
    }
    return -1;

}

int Cliente::getPosicionPorId(int id){
int pos = 0;

while(leerDeDisco(pos)) {
            if(this->idCliente== id){
               return pos;
            }
        pos ++;
    }
    return -1;

}

bool Cliente::grabarEnDisco(int pos){
FILE *puntero;
bool bandera;
    if (pos == -1){
        puntero = fopen("ARCHIVOS/Clientes.dat", "ab");
            if(puntero == NULL) {
                  return false;
        }
    }

   else{
        puntero = fopen("ARCHIVOS/Clientes.dat", "rb+");
        if(puntero == NULL) {
          return false;
        }
        fseek(puntero,pos* sizeof(Cliente),0);
    }

  bandera = fwrite(this, sizeof(Cliente), 1, puntero);
  fclose(puntero);
      if (bandera == false) {
           return false;
      }
   return true;



}

bool Cliente::leerDeDisco(int pos){
    FILE *puntero;
      bool bandera;
      puntero = fopen("ARCHIVOS/Clientes.dat", "rb");
      if(puntero == NULL) {
      return false;
}
    fseek(puntero, sizeof(Cliente)*pos, SEEK_SET);
    bandera = fread(this, sizeof(Cliente), 1, puntero);
    fclose(puntero);
    return bandera;


}
bool Cliente::validarIdCliente(int id){
FILE *puntero;


      puntero = fopen("ARCHIVOS/Clientes.dat", "rb");
      if(puntero == NULL) {
      return true;
     }

      while (fread(this, sizeof(Cliente), 1, puntero)){
        if(this->idCliente == id&&this->getEstado()==true) {
                  fclose(puntero);
                  return true;

            }
      }
    fclose(puntero);
    return false;


}

void Cliente::mostrarRegistro(){
    setColor(rlutil:: LIGHTCYAN);
    //cout<<left;
    cout<<setw(2);
    cout<<" ";
    cout<<setw(7);
    cout<< idCliente;
    cout<<setw(15);
    cout<< nombre;
    cout<<setw(15);
    cout << apellido;
    cout<<setw(15);
    cout<<dni;
    cout<<setw(15);
    cout<<numTelefono;
    cout<<endl;
    setColor(rlutil:: LIGHTRED);
    cout<<".................................................................."<<endl;

}



void menuClientes(){
    int opc;


      while(true){
            setColor(rlutil:: YELLOW);
            gotoxy(43, 2);
            cout<<" -----------------------------  ";
            gotoxy(43, 3);
            cout<<"|";
            gotoxy(43+ 30, 3);
            cout<<"|";
            setColor(rlutil:: LIGHTCYAN);
            gotoxy(43, 4);
            cout<<"|";
            gotoxy(54, 4);
            cout<<" CLIENTES "<<endl;
            gotoxy(43+30, 4);
            cout<<"|";
            setColor(rlutil:: RED);
            gotoxy(43, 5);
            cout<<"|";
            gotoxy(43+ 30, 5);
            cout<<"|";
            gotoxy(43, 6);
            cout<<" -----------------------------  ";
            setColor(rlutil:: WHITE);
            gotoxy(47, 4+3);
            cout<<"------------------------"<<endl;
            gotoxy(50, 5+3);
            cout<<"1) ALTA CLIENTE "<<endl;
            gotoxy(50, 6+3);
            cout<<"2) LISTAR CLIENTES  "<<endl;
            gotoxy(50, 7+3);
            cout<<"3) BAJA CLIENTE "<<endl;
            gotoxy(47, 8+3);
            cout<<"------------------------"<<endl;
            gotoxy(48, 9+3);
            cout<<"0) VOLVER AL MENÚ "<<endl;
            gotoxy(50, 12+3);
            cout<<"INGRESE UNA OPCIÓN: "<<endl;
            gotoxy(70, 12+3);
            cin>>opc;
            system("cls");

            switch(opc){
               case 1: altaCliente ();


                break;
                case 2: listarClientes();


                break;
                case 3:bajaCliente();


                break;
                case 0: return ;
                break;
                default: cout<<"OPCION NO VALIDA."<<endl;
                break;
            }

      }
}

void altaCliente (){
Cliente nuevoCliente;
  nuevoCliente.setCodCliente();
  nuevoCliente.setDni();
  cin.ignore();
  nuevoCliente.setNombre();
  nuevoCliente.setApellido();
  nuevoCliente.setNumTelefono();
  nuevoCliente.setEstado(true);

     if (nuevoCliente.grabarEnDisco() ){
       mensajeExito("Cliente registrado");
        system("color 0F");
      }
  else{
      mensajeError("Error de archivo" );
      system("color 0F");
  }



}


void listarClientes(){
system("cls");
  Cliente listado;
  int pos = 0;
  setColor(rlutil:: LIGHTRED);
  cout<<left;
  cout<<"------------------------------------------------------------------"<<endl;
  cout<<setw(7)<<"  ID   | "<<setw(15)<<"  NOMBRE    | "<<setw(15)<<"APELLIDO    |" <<setw(8)<<"  DNI    |"<<setw(15)<<"    TELEFONO    |"<<endl;
  cout<<"------------------------------------------------------------------"<<endl;



      while(listado.leerDeDisco(pos)) {
            if(listado.getEstado()){
                listado.mostrarRegistro();
            }
        pos ++;
      }
  cout<<endl<<endl;
  system("pause");
  system("cls");
  setColor(rlutil:: WHITE);

}

void bajaCliente(){
Cliente aBajar;
system("cls");
int dni;
int pos;
char continuar;

cout<< "INGRESE EL DOCUMENTO DE CLIENTE A DAR DE BAJA: ";
cin>> dni;
pos = aBajar.getPosicion(dni);
if (pos == -1){
   mensajeError("NO SE ENCONTRO EL DNI DEL CLIENTE");
   system("color 0F");
   return;
}
aBajar.leerDeDisco(pos);
setColor(rlutil:: LIGHTRED);
cout << endl << endl;
cout<<left;
  cout<<"------------------------------------------------------------------"<<endl;
  cout<<setw(7)<<"  ID   | "<<setw(15)<<"  NOMBRE    | "<<setw(15)<<"APELLIDO    |" <<setw(8)<<"  DNI    |"<<setw(15)<<"    TELEFONO    |"<<endl;
  cout<<"------------------------------------------------------------------"<<endl;
aBajar.mostrarRegistro();
setColor(rlutil:: WHITE);
cout << endl << endl;
cout<< "DESEA DAR DE BAJA EL REGISTRO? (S/N)";
cin >> continuar;
if(continuar=='S' || continuar == 's'){
aBajar.setEstado(false);
aBajar.grabarEnDisco(pos);
    mensajeExito("CLIENTE DADO DE BAJA CON EXITO");
}
system ("cls");
system("color 0F");
}















