#include <iostream>
#include <cstdlib>
#include <ctime>
#include<cstdio>
#include<cstring>

 using namespace std;

 #include"rlutil.h"
 #include "Proveedores.h"
 #include "Clientes.h"
 #include "compra.h"
 #include "Productos.h"
 #include "Ventas.h"
 #include"estadisticas.h"

int main(){
      setlocale(LC_ALL, "spanish");
      int opc;


      while(true){
            setColor(rlutil:: LIGHTGREEN);
            gotoxy(43, 2);
            cout<<" -----------------------------  ";
            gotoxy(43, 3);
            cout<<"|";
            gotoxy(43+ 30, 3);
            cout<<"|";
            gotoxy(43, 4);
            cout<<"|";
            gotoxy(44, 4);
            setColor(rlutil:: YELLOW);
            cout<<" GAZZO CANDY BUSINESS SYSTEM  "<<endl;
            setColor(rlutil:: LIGHTGREEN);
            gotoxy(43+30, 4);
            cout<<"|";
            gotoxy(43, 5);
            cout<<"|";
            gotoxy(43+ 30, 5);
            cout<<"|";
            gotoxy(43, 6);
            cout<<" -----------------------------  ";
            setColor(rlutil:: WHITE);
            gotoxy (50, 3+5);
            cout<<"MENÚ PRINCIPAL"<<endl;
            gotoxy(47, 4+5);
            cout<<"------------------------"<<endl;
            gotoxy(50, 5+5);
            cout<<"1) PROVEEDORES "<<endl;
            gotoxy(50, 6+5);
            cout<<"2) COMPRAS "<<endl;
            gotoxy(50, 7+5);
            cout<<"3) CLIENTES "<<endl;
            gotoxy(50, 8+5);
            cout<<"4) PRODUCTOS / STOCK "<<endl;
            gotoxy(50, 9+5);
            cout<<"5) VENTAS "<<endl;
            gotoxy(50, 10+5);
            cout<<"6) ESTADISTICAS "<<endl;
            gotoxy(47, 11+5);
            cout<<"------------------------"<<endl;
            gotoxy(48, 13+5);
            cout<<"0) SALIR DEL PROGRAMA"<<endl;
            gotoxy(50, 15+5);
            cout<<"INGRESE UNA OPCIÓN: "<<endl;
            gotoxy(70, 15+5);
            cin>>opc;
            system("cls");

            switch(opc){
                  case 1: menuProveedores();



                  break;
                  case 2:  menuCompras();


                  break;
                  case 3: menuClientes();

                  break;
                  case 4: menuProductos();

                  break;
                  case 5: menuVentas();

                  break;
                  case 6: menuEstadisticas();

                  break;
                  case 0: return 0;
                  break;
                  default: cout<<"OPCION NO VALIDA."<<endl;
                  system("pause");
                  break;
            }

      }

    return 0;
}
