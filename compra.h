#ifndef COMPRA_H_INCLUDED
#define COMPRA_H_INCLUDED
#include "Fecha.h"

class compra{
     private:
     int codCompra; ///Codigo numerico.
     char  codProducto[7]; /// 3 numeros y 3 letras
     char codProveedor[4]; /// 3 o cuatro letras
     char nombreProducto[70];
     int cantidad;
     int precioParcial;
     Fecha hoy;


     public:

    void setCodigo(int);
    void setCodProducto( char [7]);
    void setCantidad(int);
    void setCodProveedor(char [4]);
    void setNombreProducto( char [70]);
    void setTipoProducto();
    void setPrecioParcial(int );
    int getCodigo();
    char * getCodProducto();
    int  getCantidad();
    char *  getCodigoProveedor();
    char *  getNombreProducto();
    int  getTipoProducto();
    int getPrecioParcial();
    Fecha getHoy();
    bool grabarEnDisco();

} ;




int obtenerPosicionIDcompra(int);
void listarCompraID();
void menuCompras();
void realizarCompra();
void mostrarCompras();
void  leerArchivoCompras( int id, int pos);

#endif // COMPRA_H_INCLUDED
