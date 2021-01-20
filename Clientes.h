#ifndef CLIENTES_H_INCLUDED
#define CLIENTES_H_INCLUDED

class Cliente{
      private:
      int idCliente;
      int dni;
      char nombre[70];
      char apellido[70];
      int numTelefono;
      bool estado;

      public:

     void setDni ();
     void setNombre();
     void setApellido();
     void setNumTelefono();
     void setEstado(bool);
     char * getNombre();
     char * getApellido();
     int  getDni ();
     int getPosicion(int);
     int getPosicionPorId(int);
     int  getNumTelefono();
     bool getEstado();
     bool grabarEnDisco(int = -1);
     bool leerDeDisco(int);
     void mostrarRegistro();
     void setCodCliente();
     bool validarIdCliente(int);


 };

 void menuClientes();
 void altaCliente ();
 void listarClientes();
 void bajaCliente();

#endif // CLIENTES_H_INCLUDED
