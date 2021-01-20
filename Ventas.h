#ifndef VENTAS_H_INCLUDED
#define VENTAS_H_INCLUDED

#include "Fecha.h"

class Venta{
private:

int idVenta;
char idProducto[7];
int cantidad;
float precioParcial;

public:

void setIdVenta(int);
void setIdProducto(char [7]);
bool setCantidad(int);
void setPrecio(int);
bool leerEnDisco();
bool grabarEnDisco();
int getIdVenta();
char* getIdProducto();
int getCantidad();
float getPrecioParcial();

};


class datosVenta{
private:
int idVenta;
int idCliente;
Fecha Hoy;

public:

int setIdVenta();
void setIdCliente(int);
bool leerEnDisco(int);
bool grabarEnDisco();
int getIdVenta();
int getIdCliente();
Fecha getHoy();
};
int obtenerPosicionIdVenta(int);
void menuVentas();
void realizarVenta();
void mostrarVentas();
void listarVentaID();
void mostrarNombreCliente(int);
void mostrarNombreProducto(char [7]);
void  leerArchivoVentas( int );

#endif // VENTAS_H_INCLUDED
