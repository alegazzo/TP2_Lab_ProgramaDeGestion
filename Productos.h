#ifndef PRODUCTOS_H_INCLUDED
#define PRODUCTOS_H_INCLUDED

class Articulo{
private:
      char codigo[7];  ///Código alfanumerico compuesto por 3 numeros y 3 letras.
      char nombre[70];
      float precio;
      int codTipo;    /// 1- bombon 2- chocolate 3- alfajor 4 - caramelos.
      int stock;

public:
    Articulo(int = 0);  /// si recibe un 1, inicializa el stock en cero.
    void setCodigo();
    void setNombre();
    void setPrecio();
    void setTipo();
    void actualizarStock(int );
    char *getCodigo();
    char *getNombre();
    const char *getNombreTipo();
    int getTipo();
    float getPrecio();
    int getStock();
    bool grabarEnDisco(int = -1);
    bool leerDeDisco(int);
    void mostrarRegistro();
    void mostrarRegistroVenta();
    int getPosicion(char[]);
    bool descontarStock(int, int);
};

void agruparTipo();
void stockMayorValor();
void stockMenorValor();
void menuProductos();
void listarTodosProductos();
void ordenarProductosStock();
int cantidadProductos();
void ordenarMayor_Menor(Articulo *, int );
void ordenarMenor_Mayor(Articulo *, int );

#endif // PRODUCTOS_H_INCLUDED
