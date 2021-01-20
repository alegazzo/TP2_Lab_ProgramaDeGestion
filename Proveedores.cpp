#include <iostream>
#include <cstdlib>
#include <ctime>
#include<cstdio>
#include<cstring>
#include <iomanip>

 using namespace std;

 #include"rlutil.h"
 #include"Proveedores.h"
 #include"funcionesGlobales.h"


void Proveedor::setCodigo(){
   bool bandera=false;
   bool bandera2 = false;
   char cod[4];
   cout<<"INGRESE CODIGO (3 LETRAS): ";
   cin.ignore();
   cin.getline(cod, 4);
   bandera= validarCadena(cod);
   bandera2 = validarCodProveedor(cod);
      while(bandera==false || bandera2 == false){

          mensajeError("ERROR, CODIGO INVALIDO O REPETIDO");
          cout<<"INGRESE CODIGO (3 LETRAS): ";
          system("color 0F");
           cin.getline(cod, 4);
           bandera=validarCadena(cod);
            bandera2 = validarCodProveedor(cod);
      }
    strcpy(codigo,cod);

}

void Proveedor::setNombre(){
    bool bandera=false;
   char name[50];
   cout<<"INGRESE NOMBRE: ";
   cin.getline(name, 50);
   bandera= validarCadena(name);
      while(bandera==false){

          mensajeError("ERROR DE DATO");
            system("color 0F");
           cout<<"INGRESE NOMBRE:  ";
           cin.getline(name, 50);
           bandera=validarCadena(name);
      }
     strcpy(nombre, name);
}


void Proveedor::setEmail(){

    bool bandera=false;
   char mail[50];
   cout<<"INGRESE MAIL: ";
   cin.getline(mail, 50);
   bandera= validarCadena(mail);
      while(bandera==false){

          mensajeError("ERROR REINGRESE EL MAIL");
            system("color 0F");
           cout<<"INGRESE MAIL ";
           cin.getline(mail, 50);
           bandera=validarCadena(mail);
      }
   strcpy(email, mail);
}
void Proveedor::setEstado(bool state){

estado = state;

}


char * Proveedor:: getCodigo(){
      return codigo;
}
char * Proveedor :: getNombre(){
      return nombre;
}
char * Proveedor :: getEmail(){
      return email;
}
bool  Proveedor :: getEstado(){

return estado;
}
int Proveedor :: getPosicion (char cod [4]){
int pos = 0;

     while(leerDeDisco(pos)) {
            if(strcmp(this->codigo,cod)== 0){
               return pos;
            }
        pos ++;
      }
    return -1;
}


bool Proveedor:: grabarEnDisco( int pos){

FILE *puntero;
bool bandera;
      if (pos == -1){
        puntero = fopen("ARCHIVOS/Proveedores.dat", "ab");
            if(puntero == NULL) {
                  return false;
            }
      }

      else{
            puntero = fopen("ARCHIVOS/Proveedores.dat", "rb+");
            if(puntero == NULL) {
                return false;
            }
           fseek(puntero,pos* sizeof(Proveedor),0);
      }

  bandera = fwrite(this, sizeof(Proveedor), 1, puntero);
  fclose(puntero);
      if (bandera == false) {
           return false;
      }
   return true;
}

bool Proveedor :: leerDeDisco( int pos ) {
      FILE *puntero;
      bool bandera;
      puntero = fopen("ARCHIVOS/Proveedores.dat", "rb");
      if(puntero == NULL) {
      return false;
}
      fseek(puntero, sizeof(Proveedor)*pos, SEEK_SET);
      bandera = fread(this, sizeof(Proveedor), 1, puntero);
    fclose(puntero);
    return bandera;
}

void Proveedor :: mostrarRegistro() {
      setColor(rlutil:: GREEN);
    cout<<left;
     cout<<setw(15);
      cout<< nombre;
      cout<<setw(15);
      cout << codigo;
      cout<<setw(5);
      cout<<email;
      cout<<endl;
      setColor(rlutil:: BLUE);
      cout<<"........................................................."<<endl;

}

bool Proveedor :: validarCodProveedor( char * cod){
      FILE *puntero;
      int ban;

      puntero = fopen("ARCHIVOS/Proveedores.dat", "rb");
      if(puntero == NULL) {
      return true;
     }

      while (fread(this, sizeof(Proveedor), 1, puntero)){
         ban = strcmp(this->codigo, cod);
            if(ban == 0&&this->getEstado()==true) {
                  fclose(puntero);
                  return false;

            }
      }
    fclose(puntero);
    return true;
}



void menuProveedores(){
    int opc;


      while(true){

          setColor(rlutil:: CYAN);
            gotoxy(43, 2);
            cout<<" -----------------------------  ";
            gotoxy(43, 3);
            cout<<"|";
            gotoxy(43+ 30, 3);
            cout<<"|";
            setColor(rlutil:: LIGHTCYAN);
            gotoxy(43, 4);
            cout<<"|";
            gotoxy(52, 4);
            cout<<" PROVEEDORES "<<endl;
            gotoxy(43+30, 4);
            cout<<"|";
            setColor(rlutil:: LIGHTGREEN);
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
            cout<<"1) ALTA PROVEEDOR "<<endl;
            gotoxy(50, 6+3);
            cout<<"2) LISTAR PROVEEDORES  "<<endl;
            gotoxy(50, 7+3);
            cout<<"3) BAJA PROVEEDOR "<<endl;
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
               case 1: altaProveedor();


                break;
                case 2: listarProveedores();


                break;
                case 3: bajaProveedor();


                break;
                case 0: return ;
                break;
                default: cout<<"OPCION NO VALIDA."<<endl;
                break;
            }

      }
}


void altaProveedor(){
 Proveedor nuevoProveedor;

  nuevoProveedor.setCodigo();
  nuevoProveedor.setNombre();
  nuevoProveedor.setEmail();
  nuevoProveedor.setEstado(true);

      if (nuevoProveedor.grabarEnDisco() ){
           mensajeExito("Proveedor registrado");
            system("color 0F");
      }
      else{
          mensajeError("Error de archivo" );
            system("color 0F");
      }
}

void listarProveedores() {

      system("cls");
      Proveedor listado;
      int pos = 0;
      setColor(rlutil:: LIGHTBLUE);
      cout<<left;
      cout<<"---------------------------------------------------------"<<endl;
      cout<<setw(15)<<"NOMBRE    | "<<setw(15)<<"CÓDIGO    |" <<setw(8)<<"         MAIL             |"<<endl;
     cout<<"---------------------------------------------------------"<<endl;



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

void bajaProveedor(){
Proveedor aBajar;
system("cls");
char cod[4];
int pos;
char continuar;

cout<< "INGRESE EL CODIGO DE PROVEEDOR A DAR DE BAJA: ";
cin>> cod;
pos = aBajar.getPosicion(cod);
if (pos == -1){
   mensajeError("NO SE ENCONTRO EL CODIGO DE PROVEEDOR");
   system("color 0F");
   return;
}
aBajar.leerDeDisco(pos);
setColor(rlutil:: LIGHTBLUE);
cout << endl << endl;
cout<<left;
cout<<"---------------------------------------------------------"<<endl;
cout<<setw(15)<<"  NOMBRE    | "<<setw(15)<<"CÓDIGO    |" <<setw(8)<<"         MAIL             |"<<endl;
cout<<"---------------------------------------------------------"<<endl;
aBajar.mostrarRegistro();
setColor(rlutil:: WHITE);
cout << endl << endl;
cout<< "DESEA DAR DE BAJA EL REGISTRO? (S/N)";
cin >> continuar;
if(continuar=='S' || continuar == 's'){
aBajar.setEstado(false);
aBajar.grabarEnDisco(pos);
   mensajeExito("PROVEEDOR DADO DE BAJA CON EXITO");
}
system ("cls");
system("color 0F");
}


