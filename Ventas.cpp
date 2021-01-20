#include <iostream>
#include <cstdlib>
#include <ctime>
#include<cstdio>
#include<cstring>
#include <iomanip>

using namespace std;

 #include"rlutil.h"
 #include"funcionesGlobales.h"
 #include"Ventas.h"
 #include"Productos.h"
 #include"Clientes.h"

bool Venta::grabarEnDisco(){

FILE *puntero;
      puntero = fopen("ARCHIVOS/Ventas.dat", "ab");
      if(puntero == NULL) {
            return false;
      }
      fwrite(this, sizeof(Venta), 1, puntero);
      fclose(puntero);
      return true;

}


void Venta::setIdVenta(int id){
idVenta=id;
}

void Venta::setIdProducto(char cod [7]){
strcpy(idProducto, cod);


}


bool Venta::setCantidad(int cant){
cantidad= cant;

}
void Venta::setPrecio(int precio){

precioParcial = precio;

}

int Venta:: getIdVenta(){
return idVenta;

}

char* Venta::getIdProducto(){

return idProducto;

}
int Venta::getCantidad(){
return cantidad;

}
float Venta::getPrecioParcial(){
return precioParcial;
}
//METÓDOS DE LA CLASE "datosVentas"
bool datosVenta:: leerEnDisco(int pos){

 FILE *puntero;
      bool bandera;
      puntero = fopen("ARCHIVOS/DatosVenta.dat", "rb");
      if(puntero == NULL) {
            return false;
      }
      fseek(puntero, sizeof(datosVenta)*pos, SEEK_SET);
      bandera = fread(this, sizeof(datosVenta), 1, puntero);
    fclose(puntero);
    return bandera;


}

bool datosVenta::grabarEnDisco(){

FILE *puntero;
      puntero = fopen("ARCHIVOS/DatosVenta.dat", "ab");
      if(puntero == NULL) {
            return false;
      }
      fwrite(this, sizeof(datosVenta), 1, puntero);
      fclose(puntero);
      return true;

}







int datosVenta::setIdVenta(){
int autonumerico;
	FILE* pFile;

	pFile = fopen("ARCHIVOS/datosVenta.dat", "rb");

	if (pFile == NULL) {
            idVenta = 1;
            return idVenta;
	}

	fseek(pFile, 0, SEEK_END);
	autonumerico = ftell(pFile) / sizeof(datosVenta);
	fclose(pFile);
      idVenta = autonumerico+1;
	return idVenta;
}
void datosVenta::setIdCliente(int cod){
idCliente=cod;

}
int datosVenta::getIdVenta(){

return idVenta;

}
int datosVenta::getIdCliente(){

return idCliente;

}
Fecha datosVenta::getHoy(){

return Hoy;

}
void menuVentas() {

      int opc;
      while(true){
            setColor(rlutil:: GREY);
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
            cout<<" VENTAS "<<endl;
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
            gotoxy(50, 5+3);
            cout<<"1) REALIZAR VENTA "<<endl;
            gotoxy(50, 6+3);
            cout<<"2) LISTAR VENTAS  "<<endl;
            gotoxy(50, 7+3);
            cout<<"3) LISTAR POR ID "<<endl;
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
               case 1:  realizarVenta();


                break;
                case 2: mostrarVentas();

                break;
                case 3: listarVentaID();


                break;
                case 0: return ;
                break;
                default: cout<<"OPCION NO VALIDA."<<endl;
                break;
            }

      }



 }

void realizarVenta(){

      datosVenta datos;
      Venta nuevaVenta;
      Cliente aVerificar;
      Cliente clienteQueCompra;
      Articulo aVender;
      int ID,cliente, pos, cantidadVenta;
      bool bandera;
      char codProducto[7];
      char opc;



      ID =  datos.setIdVenta();

      cout<<"INGRESE CODIGO DE CLIENTE: ";
      cin>> cliente;
      bandera=aVerificar.validarIdCliente(cliente);
      while (bandera==false){
            mensajeError("ERROR, NO ENCONTRADO");
            system("color 0F");
            cout<<"REINGRESE CODIGO DE CLIENTE: ";
            cin>> cliente;
            bandera=aVerificar.validarIdCliente(cliente);
      }
      datos.setIdCliente(cliente);
      clienteQueCompra.leerDeDisco( aVerificar.getPosicionPorId(cliente));
      setColor(rlutil:: LIGHTRED);
      cout<<left;
      cout<<"------------------------------------------------------------------"<<endl;
      cout<<setw(7)<<"  ID   | "<<setw(15)<<"  NOMBRE    | "<<setw(15)<<"APELLIDO    |" <<setw(8)<<"  DNI    |"<<setw(15)<<"    TELEFONO    |"<<endl;
      cout<<"------------------------------------------------------------------"<<endl;
      clienteQueCompra.mostrarRegistro();
      setColor(rlutil:: WHITE);
      cout<<endl;
      cout<<endl;

      do{


            do{
                  cout<<"INGRESE CODIGO DE PRODUCTO A VENDER: "<<endl;
                  cin>>codProducto;
                  pos = aVender.getPosicion(codProducto);

                  while(pos == -1) {

                      cout<<"El PRODUCTO NO EXISTE, REINGRESE EL CODIGO: ";
                      cin>>codProducto;
                      pos = aVender.getPosicion(codProducto);
                  }
                  setColor(rlutil:: LIGHTRED);
                  cout<<"--------------------------------------------------------------------------"<<endl;
                  setColor(rlutil:: CYAN);
                  cout<<setw(7)<<"  ID PRODUCTO  | "<<setw(10)<<"    NOMBRE    | "<<setw(7)<<"      TIPO      |" <<setw(8)<<"  PRECIO  |"<<setw(8)<<"  CANTIDAD  |"<<endl;
                  setColor(rlutil:: LIGHTRED);
                  cout<<"--------------------------------------------------------------------------"<<endl;
                  setColor(rlutil:: YELLOW);

                  aVender.leerDeDisco(pos);
                  if(aVender.getStock()==0){
                        mensajeError("STOCK 0, NO SE PUEDE VENDER");
                        system("color 0F");
                        opc='n';
                  }
                 else{
                  aVender.mostrarRegistroVenta();
                  setColor(rlutil:: WHITE);
                  cout << "DESEA AGREGAR ESTE PRODUCTO A LA VENTA? (S/N)";
                  cin >> opc;}

            } while(opc =='n'||opc =='N');


            do{
                  cout<<" INGRESE LA CANTIDAD A VENDER: ";
                  cin>> cantidadVenta;
                 bandera = aVender.descontarStock(cantidadVenta,pos);


            }while(bandera==false);

            nuevaVenta.setIdVenta(ID);
            nuevaVenta.setIdProducto(codProducto);
            nuevaVenta.setCantidad(cantidadVenta);
            nuevaVenta.setPrecio((aVender.getPrecio()*1.6)*cantidadVenta);
            bandera=nuevaVenta.grabarEnDisco();

          if(bandera) {
                  mensajeExito("Producto agregado a la venta.");
                  system("color 0F");
            }
            else{
                  mensajeError("No se puede continuar");
                  system("color 0F");
                  system("pause");
                  system("cls");
                  return;
            }

           cout<<"DESEA AGREGAR UN NUEVO PRODUCTO A LA VENTA? (S/N)";
           cin>>opc;
           system("cls");


      } while(opc =='s'||opc =='S');

      datos.grabarEnDisco();

      pos=obtenerPosicionIdVenta(ID);
      datos.leerEnDisco(pos);

      setColor(rlutil:: LIGHTRED);
      cout<<left;
      cout<<"--------------------------------------------------------------"<<endl;
      setColor(rlutil:: YELLOW);
      cout<<setw(7)<<"  ID VENTA  | "<<setw(20)<<"         CLIENTE           | "<<setw(15)<<"      FECHA       |"<<endl;
      setColor(rlutil:: LIGHTRED);
      cout<<"--------------------------------------------------------------"<<endl;
      setColor(rlutil:: YELLOW);
      cout<<"    ";
      cout<<setw(15);
      cout<<datos.getIdVenta();
      cout<<setw(12);
      mostrarNombreCliente(datos.getIdCliente());
      datos.getHoy().mostrarFecha();
      leerArchivoVentas(datos.getIdVenta());


system("pause");
system("cls");
setColor(rlutil:: WHITE);

 }



 void mostrarVentas() {
      system("cls");
      datosVenta reg;
      int x = 0;
     while(reg.leerEnDisco(x) ) {
 setColor(rlutil:: LIGHTRED);
            cout<<left;
            cout<<"--------------------------------------------------------------"<<endl;
            setColor(rlutil:: YELLOW);
            cout<<setw(7)<<"  ID VENTA  | "<<setw(20)<<"         CLIENTE           | "<<setw(15)<<"      FECHA       |"<<endl;
            setColor(rlutil:: LIGHTRED);
            cout<<"--------------------------------------------------------------"<<endl;
            setColor(rlutil:: YELLOW);
            cout<<"    ";
            cout<<setw(15);
            cout<<reg.getIdVenta();
            cout<<setw(12);
            mostrarNombreCliente(reg.getIdCliente());

            reg.getHoy().mostrarFecha();
            leerArchivoVentas(reg.getIdVenta());
            x++;
      }
  system("pause");
  system("cls");
}


void  leerArchivoVentas( int id){
 int precioTotal = 0;
    FILE *puntero;
      Venta reg;
      bool bandera = true;
      bool bandera2 = true;
      puntero = fopen("ARCHIVOS/Ventas.dat", "rb");
      if(puntero == NULL) {

            cout<<"error"<<endl;
            system("pause");
      }

      setColor(rlutil:: WHITE);


  while (fread(&reg, sizeof(Venta), 1 , puntero)) {
            if(reg.getIdVenta()==id){

                  if(bandera) {

                        setColor(rlutil:: MAGENTA);
                        cout<<left;
                        cout<<endl;
                        setColor(rlutil:: LIGHTRED);
                        cout<<"------------------------------------------------------------------------"<<endl;
                        setColor(rlutil:: CYAN);
                        cout<<setw(7)<<"  ID PRODUCTO  | "<<setw(15)<<"  NOMBRE PRODUCTO   | "<<setw(15)<<"  CANTIDAD    |" <<setw(8)<<" PRECIO PARCIAL  |"<<endl;
                        setColor(rlutil:: LIGHTRED);
                        cout<<"------------------------------------------------------------------------"<<endl;
                        bandera = false;
                  }


                  setColor(rlutil:: MAGENTA);
                  cout<<"    ";
                  cout<<setw(18);
                  cout<<reg.getIdProducto();
                  cout<<setw(20);
                  mostrarNombreProducto(reg.getIdProducto());
                  cout<<setw(17);
                  cout<<reg.getCantidad();
                  cout<<setw(8);
                  cout<<reg.getPrecioParcial()<<"$";
                  cout<<setw(0);
                  cout<<endl;
                  setColor(rlutil:: LIGHTRED);
                  cout<<"------------------------------------------------------------------------"<<endl;
                  precioTotal += reg.getPrecioParcial();

            }
      }

      cout<<left;
      cout<<endl;
      cout<<endl;
      setColor(rlutil:: LIGHTRED);
      cout<<"------------------------"<<endl;
      cout<<setw(16)<<" PRECIO FINAL: " <<setw(5)<< precioTotal <<" $| "<<endl;
      setColor(rlutil:: LIGHTRED);
      cout<<"------------------------"<<endl;
      setColor(rlutil:: WHITE);
      cout<<"*******************************************************************************************************************"<<endl;
      cout<<endl;
      cout<<endl;


 setColor(rlutil:: WHITE);
 fclose(puntero);
}



void mostrarNombreCliente(int id){
 Cliente reg;
 int pos;
pos = reg.getPosicionPorId(id);
reg.leerDeDisco(pos);

 cout<< reg.getNombre();
 cout<<setw(14);
 cout<< reg.getApellido();

}

void mostrarNombreProducto(char cod [7]){
Articulo reg;
int x=0;
while(reg.leerDeDisco(x++)){
      if(strcmp(cod,reg.getCodigo())==0){
            cout<< reg.getNombre();

      }


}


}


int obtenerPosicionIdVenta(int id){
int pos = 0;
datosVenta reg;
FILE* pFile;

pFile = fopen("ARCHIVOS/DatosVenta.dat", "rb");

      if (pFile == NULL) {
            return -1;
      }

      while(fread(&reg, sizeof(datosVenta), 1, pFile)){
            if (id==reg.getIdVenta()){
                  fclose(pFile);
               return pos;

            }

            pos++;

      }
fclose(pFile);
 return -1;




}



void listarVentaID(){

  system("cls");
     datosVenta reg;
      int pos;
      int id;
      cout<<"INGRESAR ID DE LA VENTA: ";
      cin>>id;

      pos=obtenerPosicionIdVenta(id);
      if(pos== -1){
            mensajeError("NO ENCONTRADO");
            system("color 0F");
            return;
      }
      reg.leerEnDisco(pos);

      setColor(rlutil:: LIGHTRED);
      cout<<left;
      cout<<"--------------------------------------------------------------"<<endl;
      setColor(rlutil:: YELLOW);
      cout<<setw(7)<<"  ID VENTA  | "<<setw(20)<<"         CLIENTE           | "<<setw(15)<<"      FECHA       |"<<endl;
      setColor(rlutil:: LIGHTRED);
      cout<<"--------------------------------------------------------------"<<endl;
      setColor(rlutil:: YELLOW);
      cout<<"    ";
      cout<<setw(15);
      cout<<reg.getIdVenta();
      cout<<setw(12);
      mostrarNombreCliente(reg.getIdCliente());
      reg.getHoy().mostrarFecha();
      leerArchivoVentas(reg.getIdVenta());

      system("pause");
      system("cls");

 setColor(rlutil:: WHITE);



}
