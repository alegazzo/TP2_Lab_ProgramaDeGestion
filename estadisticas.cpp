#include <iostream>
#include <cstdlib>
#include <ctime>
#include<cstdio>
#include<cstring>
#include<iomanip>

 using namespace std;

 #include"rlutil.h"
 #include "Proveedores.h"
 #include "Clientes.h"
 #include "compra.h"
 #include "Productos.h"
 #include "Ventas.h"
#include"estadisticas.h"

 void menuEstadisticas(){
    int opc;

      while(true){
            gotoxy(43, 2);
            setColor(rlutil:: LIGHTBLUE);
            cout<<" -----------------------------  ";
            gotoxy(43, 3);
            setColor(rlutil:: LIGHTBLUE);
            cout<<"|";
            gotoxy(43+ 30, 3);
            setColor(rlutil:: GREEN);
            cout<<"|";
            setColor(rlutil:: LIGHTBLUE);
            gotoxy(43, 4);
            cout<<"|";
            gotoxy(51, 4);
            setColor(rlutil:: YELLOW);
            cout<<" ESTADÍSTICAS "<<endl;
            setColor(rlutil:: GREEN);
            gotoxy(43+30, 4);
            cout<<"|";
            setColor(rlutil:: LIGHTBLUE);
            gotoxy(43, 5);
            cout<<"|";
            gotoxy(43+ 30, 5);
            setColor(rlutil:: GREEN);
            cout<<"|";
            gotoxy(43, 6);
            cout<<" -----------------------------  ";
            setColor(rlutil:: WHITE);
            gotoxy(37, 5+3);
            cout<<"1) PORCENTAJE DE CANTIDAD VENDIDA DE CADA PRODUCTO "<<endl;
            gotoxy(37, 6+3);
            cout<<"2) PORCENTAJE DE CANTIDAD VENDIDA DE CADA CATEGORÍA  "<<endl;
            gotoxy(37, 7+3);
            cout<<"3) PRODUCTO MÁS VENDIDO DE CADA CATEGORÍA "<<endl;
            gotoxy(37, 8+3);
            cout<<"4) REPORTE DE GASTOS Y GANACIA DEL MES ACTUAL "<<endl;
            gotoxy(47, 9+3);
            cout<<"------------------------"<<endl;
            gotoxy(48, 10+3);
            cout<<"0) VOLVER AL MENÚ "<<endl;
            gotoxy(50, 13+3);
            cout<<"INGRESE UNA OPCIÓN: "<<endl;
            gotoxy(70, 13+3);
            cin>>opc;
            system("cls");

            switch(opc){
               case 1: porcentajePorProducto();


                break;
                case 2: porcentajePorCategoria();


                break;
                case 3: masVendidoPorCategoria();

                 break;
                case 4: gastosGanancia();
                break;
                case 0: return ;
                break;
                default: cout<<"OPCION NO VALIDA."<<endl;
                break;
            }

      }
}

void porcentajePorProducto(){

   int cantidadTotal , cantidadTotalProducto;
   Articulo producto;
   float porcentaje;
   int x =0;
   cantidadTotal = totalProductosVendidos();
     cout<<left;
      setColor(rlutil:: RED);
      cout<<"----------------------------------------------"<<endl;
      setColor(rlutil:: YELLOW);
      cout<<setw(18)<<"NOMBRE    | "<<setw(15)<<"CÓDIGO    |" <<setw(8)<<" PORCENTAJE  |"<<endl;
      setColor(rlutil:: RED);
     cout<<"----------------------------------------------"<<endl;
     setColor(rlutil:: WHITE);

      while(producto.leerDeDisco(x++)){
      cantidadTotalProducto = cantidadVendidaDelProducto( producto.getCodigo());
           porcentaje =((float) cantidadTotalProducto/ cantidadTotal )*100;
            cout<<left;
           cout<<setw(18);
           cout<< producto.getNombre();
           cout<<setw(15);
          cout << producto.getCodigo();
         cout<<setw(5);
          cout<< fixed<<setprecision(2)<<porcentaje;
          cout<<" %";
         cout<<endl;
         setColor(rlutil:: LIGHTGREEN);
         cout<<"----------------------------------------------"<<endl;
          setColor(rlutil:: WHITE);
      }

system("pause");
system("cls");


}

void porcentajePorCategoria(){

   Articulo producto;
      int pos;
      int x;
      int cantidadVendidaPorCategoria;
      int cantidadTotal;

     cantidadTotal = totalProductosVendidos();
      setColor(rlutil:: RED);
      cout<<left;
      cout<<"-----------------------------"<<endl;
      setColor(rlutil:: YELLOW);
      cout<<setw(16)<<"CATEGORÍA    | "<<"PORCENTAJE  |" <<endl;
      setColor(rlutil:: RED);
      cout<<"-----------------------------"<<endl;
     setColor(rlutil:: WHITE);

      for(x=0; x<4; x++){
            pos = 0;
              cantidadVendidaPorCategoria =0;
            while(producto.leerDeDisco(pos++)){
                  if (producto.getTipo() == x +1 ){
                        cantidadVendidaPorCategoria+= contarCantidadVendida(producto.getCodigo());

                  }
            }

            cout<<setw(18);
            cout<<nombreCategoria(x+1);
            cout<<fixed<<setprecision(2)<<((float) cantidadVendidaPorCategoria/cantidadTotal) *100;
            cout<<" % "<<endl;
            setColor(rlutil:: MAGENTA);
            cout<<"-----------------------------"<<endl;
            setColor(rlutil:: WHITE);
      }

      system("pause");
      system("cls");
 }

int cantidadVendidaDelProducto( char cod [7]){
 Venta ventas;
      FILE * puntero;
      int total= 0;
      puntero = fopen("ARCHIVOS/Ventas.dat", "rb");
      if(puntero == NULL) {
            return -1;
      }
      while(fread(&ventas, sizeof(Venta), 1, puntero)){
            if (strcmp(ventas.getIdProducto(), cod) == 0) {
                  total+=ventas.getCantidad();
            }

      }
      fclose(puntero);
      return  total;



 }

int totalProductosVendidos() {

  Venta ventas;
      FILE * puntero;
      int total= 0;
      puntero = fopen("ARCHIVOS/Ventas.dat", "rb");
      if(puntero == NULL) {
            return -1;
      }
      while(fread(&ventas, sizeof(Venta), 1, puntero)){
            total+= ventas.getCantidad();
      }
      fclose(puntero);
      return  total;

}

void masVendidoPorCategoria(){

     Articulo producto;
      int pos;
      int x;
      char codProducto[7];
      int cantidadVendida;
      int cantidadVendidaMayor ;

      for(x=0; x<4; x++){
            pos = 0;
            cantidadVendida = 0;
            cantidadVendidaMayor = 0;
            while(producto.leerDeDisco(pos++)){
                  if (producto.getTipo() == x +1 ){
                        cantidadVendida = contarCantidadVendida(producto.getCodigo());
                        if(cantidadVendida > cantidadVendidaMayor){
                              strcpy(codProducto, producto.getCodigo());
                              cantidadVendidaMayor = cantidadVendida;
                        }

                  }
            }
            cout<<left;
            setColor(rlutil:: LIGHTRED);
            cout<<"-------------------------------------------"<<endl;
            setColor(rlutil:: WHITE);
            cout <<" -MÁS VENDIDO DE ";
            setColor(rlutil:: GREY);
            cout<<nombreCategoria(x+1);
            cout<<setw(2);
            cout<<": ";
            setColor(rlutil:: YELLOW);
            cout<<setw(15);
            mostrarNombreProducto(codProducto);
            cout<<endl;
            setColor(rlutil:: WHITE);
            cout<< " -CANTIDAD VENDIDA: " ;
            setColor(rlutil:: LIGHTGREEN);
            cout<<cantidadVendidaMayor<<endl;

      }
      setColor(rlutil:: LIGHTRED);
      cout<<"-------------------------------------------"<<endl;
      setColor(rlutil:: WHITE);
      cout<<endl;
      cout<<endl;
      cout<<endl;
      system("pause");
      system("cls");

}

int contarCantidadVendida(char cod [7]){

Venta reg;
int cantidad = 0;
FILE * puntero;
 puntero = fopen("ARCHIVOS/Ventas.dat", "rb");
      if(puntero == NULL) {
            return -1;
      }

      while(fread(&reg, sizeof(Venta), 1, puntero)) {
            if(strcmp(reg.getIdProducto(), cod) == 0) {
                  cantidad += reg.getCantidad();
            }
      }
      fclose(puntero);
      return cantidad;

}

const char * nombreCategoria (int opc) {

     const char* vacio=" ";
    const char* bombon = "BOMBON ";
    const char* chocolate = "CHOCOLATE";
    const char* alfajor = "ALFAJOR";
    const char* caramelos = "CARAMELOS";

      switch(opc){

          case 1: return bombon;
          break;
          case 2:return chocolate;
          break;
          case 3:return alfajor;
          break;
          case 4:return caramelos;
          break;
          default: return vacio;
          break;
      }
}

void gastosGanancia() {

   float gasto, recaudacion;
   Fecha hoy;

    gasto = gastoCompras(hoy.getMes());
    recaudacion = recaudacionVentas(hoy.getMes());
     setColor(rlutil:: LIGHTMAGENTA);
      gotoxy(43, 2);
      cout<<" -----------------------------  ";
      gotoxy(43, 3);
      cout<<"|";
      gotoxy(43+ 30, 3);
      cout<<"|";
      gotoxy(43, 4);
      cout<<"|";
      gotoxy(50, 4);
      setColor(rlutil:: YELLOW);
      cout<<nombreMes(hoy.getMes())<<"  " <<hoy.getAnio()<<endl;
      setColor(rlutil:: LIGHTMAGENTA);
      gotoxy(43+30, 4);
      cout<<"|";
      gotoxy(43, 5);
      cout<<"|";
      gotoxy(43+ 30, 5);
      cout<<"|";
      gotoxy(43, 6);
      cout<<" -----------------------------  ";
      setColor(rlutil:: WHITE);

     setColor(rlutil:: LIGHTCYAN);
      gotoxy(43, 2+7);
      cout<<" -----------------------------  ";
      gotoxy(43, 3+7);
      cout<<"|";
      gotoxy(43+ 30, 3+7);
      cout<<"|";
      gotoxy(43, 4+7);
      cout<<"|";
      gotoxy(50, 4+7);
      setColor(rlutil:: YELLOW);
      cout<<" GASTOS: " << gasto << "$ "<<endl;
      setColor(rlutil:: LIGHTCYAN);
      gotoxy(43+30, 4+7);
      cout<<"|";
      gotoxy(43, 5+7);
      cout<<"|";
      gotoxy(43+ 30, 5+7);
      cout<<"|";
      gotoxy(43, 6+7);
      cout<<" -----------------------------  ";
      setColor(rlutil:: WHITE);

     setColor(rlutil:: LIGHTCYAN);
      gotoxy(43, 2+13);
      cout<<" -----------------------------  ";
      gotoxy(43, 3+13);
      cout<<"|";
      gotoxy(43+ 30, 3+13);
      cout<<"|";
      gotoxy(43, 4+13);
      cout<<"|";
      gotoxy(50, 4+13);
      setColor(rlutil:: YELLOW);
      cout<<" INGRESOS: " << recaudacion << "$ "<<endl;
      setColor(rlutil:: LIGHTCYAN);
      gotoxy(43+30, 4+13);
      cout<<"|";
      gotoxy(43, 5+13);
      cout<<"|";
      gotoxy(43+ 30, 5+13);
      cout<<"|";
      gotoxy(43, 6+13);
      cout<<" -----------------------------  ";
      setColor(rlutil:: WHITE);

      setColor(rlutil:: LIGHTGREEN);
      gotoxy(43, 2+20);
      cout<<" -----------------------------  ";
      gotoxy(43, 3+20);
      cout<<"|";
      gotoxy(43+ 30, 3+20);
      cout<<"|";
      gotoxy(43, 4+20);
      cout<<"|";
      gotoxy(50, 4+20);
      if(recaudacion-gasto<=0) {
            setColor(rlutil:: RED);
      }
      else{
            setColor(rlutil:: YELLOW);
      }
      cout<<" GANACIA: " << recaudacion-gasto << "$ "<<endl;
      setColor(rlutil:: LIGHTGREEN);
      gotoxy(43+30, 4+20);
      cout<<"|";
      gotoxy(43, 5+20);
      cout<<"|";
      gotoxy(43+ 30, 5+20);
      cout<<"|";
      gotoxy(43, 6+20);
      cout<<" -----------------------------  ";
      setColor(rlutil:: WHITE);

cout<<endl;
cout<<endl;
system("pause");
system("cls");



 }


float gastoCompras(int mes) {

      compra compras;
      FILE * puntero;
      float gasto = 0;
      puntero = fopen("ARCHIVOS/Compras.dat", "rb");
      if(puntero == NULL) {
            return -1;
      }
      while(fread(&compras, sizeof(compra), 1, puntero)){
            if(compras.getHoy().getMes()==mes){
                  gasto+=compras.getPrecioParcial();
            }

      }
      fclose(puntero);
      return  gasto;

}

float recaudacionVentas(int mes) {

      Venta ventas;
      FILE * puntero;
      float rec = 0;
      puntero = fopen("ARCHIVOS/Ventas.dat", "rb");
      if(puntero == NULL) {
            return -1;
      }
      while(fread(&ventas, sizeof(Venta), 1, puntero)){
            if(mesDeVenta(ventas.getIdVenta(), mes)) {
                  rec+=ventas.getPrecioParcial();
            }

      }
      fclose(puntero);
      return  rec;

}

bool mesDeVenta(int id, int mes) {
  datosVenta reg;
  int x=0;
      while(reg.leerEnDisco(x++)){
            if(reg.getIdVenta()== id && reg.getHoy().getMes() == mes) {
                  return true;
            }
      }
      return false;


}

const char* nombreMes(int mes){
      const char* noviembre = "NOVIEMBRE";
      const char* diciembre = "DICIEMBRE";


    switch(mes) {
            case 11: return noviembre;
            break;
            case 12: return diciembre;
            break;


      }

}




