#ifndef FECHA_H_INCLUDED
#define FECHA_H_INCLUDED


class Fecha{
      private:
      int dia, mes, anio;
      public:
      Fecha ();  ///Al instanciar un objeto fecha, se le asignará la fecha del sistema.
      int getDia();
      int getMes();
      int getAnio();
      void mostrarFecha();

};


#endif // FECHA_H_INCLUDED


