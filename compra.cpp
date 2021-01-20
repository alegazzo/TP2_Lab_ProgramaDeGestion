#include <iostream>
#include <cstdlib>
#include<cstdio>
#include<cstring>
#include <iomanip>


 using namespace std;

#include"rlutil.h"
 #include"funcionesGlobales.h"
 #include "Clientes.h"
#include"funcionesGlobales.h"
#include "compra.h"
#include "Fecha.h"
#include "Proveedores.h"
#include"Productos.h"
#include"IDgenerator.h"

Fecha compra::getHoy(){
      return hoy;

}

void compra :: setCodigo(int id){
    codCompra = id;
}

void compra:: setCodProducto( char cod [7]){
   strcpy(codProducto, cod);
}

void compra:: setCodProveedor(char cod[4]){
      strcpy(codProveedor, cod);
}



void compra:: setCantidad(int valor){
      cantidad =  valor;
}

void compra :: setNombreProducto( char nombre[70]){
      strcpy(nombreProducto, nombre);

}

void compra::setPrecioParcial(int precio ){

precioParcial = precio;


}

 int  compra:: getCodigo(){
      return codCompra;
 }
char *   compra:: getCodProducto(){
      return codProducto;


}
int   compra:: getCantidad(){
      return cantidad;
}

char *  compra :: getCodigoProveedor(){
      return codProveedor;
}

char *  compra:: getNombreProducto(){
      return nombreProducto;
}
int compra:: getPrecioParcial(){

return precioParcial;
}



bool compra:: grabarEnDisco(){

FILE *puntero;

puntero = fopen("ARCHIVOS/Compras.dat", "ab");
 fwrite(this, sizeof(compra), 1, puntero);
fclose(puntero);
return true;
}






void menuCompras() {

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
            gotoxy(54, 4);
            cout<<" COMPRAS "<<endl;
            gotoxy(43+30, 4);
            cout<<"|";
            setColor(rlutil:: GREY);
            gotoxy(43, 5);
            cout<<"|";
            gotoxy(43+ 30, 5);
            cout<<"|";
            gotoxy(43, 6);
            cout<<" -----------------------------  ";
            setColor(rlutil:: WHITE);
            gotoxy(47, 4+3);
           // cout<<"------------------------"<<endl;
            gotoxy(50, 5+3);
            cout<<"1) REALIZAR COMPRA "<<endl;
            gotoxy(50, 6+3);
            cout<<"2) LISTAR COMPRAS  "<<endl;
            gotoxy(50, 7+3);
            cout<<"3) LISTAR POR ID "<<endl;
            gotoxy(47, 8+3);
            cout<<"------------------------"<<endl;
            gotoxy(49, 9+3);
            cout<<"0) VOLVER AL MENÚ "<<endl;
            gotoxy(50, 12+3);
            cout<<"INGRESE UNA OPCIÓN: "<<endl;
            gotoxy(70, 12+3);
            cin>>opc;
            system("cls");

            switch(opc){
               case 1:  realizarCompra();


                break;
                case 2: mostrarCompras();
                break;
                case 3:listarCompraID();


                break;
                case 0: return ;
                break;
                default: cout<<"OPCION NO VALIDA."<<endl;
                break;
            }

      }



 }


void realizarCompra(){

      int ID, pos, cantidad;
      char seguir;
      bool bandera;
      bool verificado;
      char codProducto[7];
      char codProveedor [4];
      char opc;
      int precioParcial = 0;
      Articulo productoExistente;
      compra nuevaCompra;
      IDGenerator identificador, reg;
      Proveedor aVerificar;
      char  nombre [70];

    ID =  identificador.generateID();  /// Clase para generar el ID que va a linkear todos los registros de la compra.
    identificador.generatePos();


      cout<<"INGRESE CODIGO DE PROVEEDOR: "<<endl;                              /// ANTES DE EMPEZAR SE VALIDA CODIGO DE PROVEEDOR
      cin.ignore();
      cin.getline(codProveedor, 4);

      verificado = aVerificar.validarCodProveedor(codProveedor);
      while (verificado == true) {
            mensajeError("ERROR, NO ENCONTRADO");
            system("color 0F");

            cout<<"REINGRESE CODIGO DE PROVEEDOR: ";
            cin.getline(codProveedor, 4);
            verificado = aVerificar.validarCodProveedor(codProveedor);
      }

    do{
            do{
                  cout<<"Ingrese código de producto a comprar: "<<endl;
                  cin>>codProducto;
                  pos = productoExistente.getPosicion(codProducto);
                  opc = 'S';
                  if(pos == -1) {
                      cout<<"PRODUCTO NO REGISTRADO, DESEA DAR DE ALTA NUEVO PRODUCTO? (S/N)"<<endl;
                      cin>>opc;
                  }

            } while (opc =='n'||opc =='N') ;

            if(pos == -1) {
                  setColor(rlutil:: LIGHTRED);
                  cout<<"------------------------------"<<endl;
                  setColor(rlutil:: WHITE);
                  cout<<" REGISTRO DE PRODUCTO NUEVO"<<endl;      /// Si el producto no existe, se hace el registro del producto.
                  setColor(rlutil:: LIGHTRED);
                  cout<<"------------------------------"<<endl;\
                  setColor(rlutil:: WHITE);
                  Articulo nuevoProducto(1);                    /// constructor para que el stock del articulo a registrar inice en cero hasta que se le acumule la cantidad a comprar.
                  nuevoProducto.setCodigo();
                  strcpy(codProducto, nuevoProducto.getCodigo());
                  nuevoProducto.setNombre();
                  nuevoProducto.setTipo();
                  nuevoProducto.setPrecio();
                  precioParcial = nuevoProducto.getPrecio();
                  strcpy(nombre, nuevoProducto.getNombre());
                  cout<<"Ingrese cantidad a comprar:  ";
                  cin>> cantidad;
                  nuevoProducto.actualizarStock(cantidad);


                  if(nuevoProducto.grabarEnDisco()){
                        mensajeExito("registrado con exito");
                        system("color 0F");
                  }
                  else{
                        mensajeError("No es posible registrar nuevo producto");
                        system("color 0F");
                        system("pause");
                        system("cls");
                        return;
                  }

            }
            else{
            setColor(rlutil:: LIGHTRED);
            cout<<"--------------------------------------------------------------------------"<<endl;
            setColor(rlutil:: CYAN);
            cout<<setw(7)<<"  ID PRODUCTO  | "<<setw(10)<<"    NOMBRE    | "<<setw(7)<<"      TIPO      |" <<setw(8)<<"  PRECIO  |"<<setw(8)<<"  CANTIDAD  |"<<endl;
            setColor(rlutil:: LIGHTRED);
            cout<<"--------------------------------------------------------------------------"<<endl;
            setColor(rlutil:: YELLOW);

                  productoExistente.leerDeDisco(pos);                /// si el producto ya existe se utiliza el objeto producto existente para actualizar el stock con la nueva cantidad ingresada
                  productoExistente.mostrarRegistro();
                  strcpy(nombre, productoExistente.getNombre());
                  setColor(rlutil:: WHITE);
                  cout<<" INGRESE LA CANTIDAD A COMPRAR: ";
                  cin>> cantidad;
                  precioParcial = productoExistente.getPrecio();
                  productoExistente.actualizarStock(cantidad);
                  productoExistente.grabarEnDisco(pos);

            }
            nuevaCompra.setCodigo(ID);                      ///  en el archivo de compras, se guarda el subregistro de la compra (un subregistro es la compra de un producto particular).
            nuevaCompra.setCantidad(cantidad);       /// El registro total de compra se compone de todos los subregistros que tienen el mismo ID.
            nuevaCompra.setCodProducto(codProducto);
            nuevaCompra.setNombreProducto(nombre);
            nuevaCompra.setCodProveedor(codProveedor);
            nuevaCompra.setPrecioParcial(precioParcial*cantidad);
            bandera = nuevaCompra.grabarEnDisco();
            if(bandera) {
                  mensajeExito("Producto agregado a la compra.");
                  system("color 0F");
            }
            else{
                  mensajeError("No se puede continuar");
                  system("color 0F");
                  system("pause");
                  system("cls");
                  return;
            }



          cout<<"¿Desea seguir comprando? S/N "<<endl;
          cin>>seguir;
      } while(seguir== 's'|| seguir == 'S' );
      identificador.grabarEnDisco();
      system("cls");

      pos=obtenerPosicionIDcompra(ID);
      reg.leerDisco(pos);
      leerArchivoCompras(reg.getID(), reg.getPos());

      system("pause");
      system("cls");

 setColor(rlutil:: WHITE);



}




void mostrarCompras() {

      system("cls");
      IDGenerator reg;
      int x = 0;
     while(reg.leerDisco(x) ) {
           leerArchivoCompras(reg.getID(), reg.getPos());
            x++;
      }
      system("pause");
      system("cls");
}






void  leerArchivoCompras( int id, int pos){
 int precioTotal = 0;
    FILE *puntero;
      compra reg ;
      bool bandera = true;
      bool bandera2 = true;
      puntero = fopen("ARCHIVOS/Compras.dat", "rb");
      if(puntero == NULL) {

            cout<<"error"<<endl;
            system("pause");
      }

      setColor(rlutil:: WHITE);
      cout<<"*******************************************************************************************************************"<<endl;
      setColor(rlutil:: WHITE);
      fseek(puntero, sizeof(compra)* pos, SEEK_SET);

      while (fread(&reg, sizeof(compra), 1 , puntero)) {
           if(reg.getCodigo()==id){
                  if(bandera) {
                        setColor(rlutil:: LIGHTRED);
                        cout<<left;
                        cout<<"------------------------------------------------"<<endl;
                        setColor(rlutil:: YELLOW);
                        cout<<setw(7)<<"  ID COMPRA  | "<<setw(15)<<"  PROVEEDOR    | "<<setw(15)<<"    FECHA      |"<<endl;
                        setColor(rlutil:: LIGHTRED);
                        cout<<"------------------------------------------------"<<endl;
                        setColor(rlutil:: YELLOW);
                        cout<<"    ";
                        cout<<setw(15);
                        cout<<reg.getCodigo();
                        cout<<setw(13);
                        cout<<reg.getCodigoProveedor();

                        reg.getHoy().mostrarFecha();

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
                  cout<<reg.getCodProducto();
                  cout<<setw(20);
                  cout<<reg.getNombreProducto();
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


            else {

                  cout<<endl;
                  cout<<left;
                  setColor(rlutil:: LIGHTRED);
                  cout<<"----------------------"<<endl;

                  cout<<setw(15)<<" PRECIO FINAL: " << precioTotal <<" $| "<<endl;
                  setColor(rlutil:: LIGHTRED);
                  cout<<"----------------------"<<endl;
                  cout<<endl;
                  cout<<endl;




                  return;
            }


      }

      cout<<left;
      cout<<endl;
      cout<<endl;
      setColor(rlutil:: LIGHTRED);
      cout<<"----------------------"<<endl;
      cout<<setw(15)<<" PRECIO FINAL: " << precioTotal <<" $| "<<endl;
      setColor(rlutil:: LIGHTRED);
      cout<<"----------------------"<<endl;
      cout<<endl;
      cout<<endl;


 setColor(rlutil:: WHITE);
}


int obtenerPosicionIDcompra(int id){
int pos = 0;
IDGenerator reg;
FILE* pFile;

pFile = fopen("ARCHIVOS/archivoDeID.dat", "rb");

      if (pFile == NULL) {

       return -1;

      }

      while(fread(&reg, sizeof(IDGenerator), 1, pFile)){
            if (id==reg.getID()){
               return pos;

            }

            pos++;

      }

 return -1;




}








void listarCompraID(){

      system("cls");
      IDGenerator reg;
      int pos;
      int id;
      cout<<"INGRESAR ID DE LA COMPRA: ";
      cin>>id;

      pos=obtenerPosicionIDcompra(id);
       if(pos== -1){
            mensajeError("NO ENCONTRADO");
            system("color 0F");
            return;
      }
      reg.leerDisco(pos);
      leerArchivoCompras(reg.getID(), reg.getPos());

      system("pause");
      system("cls");

 setColor(rlutil:: WHITE);





}




