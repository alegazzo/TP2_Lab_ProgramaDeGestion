#ifndef ESTADISTICAS_H_INCLUDED
#define ESTADISTICAS_H_INCLUDED

void menuEstadisticas();

void  masVendidoPorCategoria();
int contarCantidadVendida(char [7]);
const char * nombreCategoria (int);

void gastosGanancia();
float gastoCompras(int);
float recaudacionVentas(int);
const char* nombreMes(int);
bool mesDeVenta(int, int);

void porcentajePorProducto();
void porcentajePorCategoria();
int totalProductosVendidos();
 int cantidadVendidaDelProducto( char [7]);

#endif // ESTADISTICAS_H_INCLUDED
