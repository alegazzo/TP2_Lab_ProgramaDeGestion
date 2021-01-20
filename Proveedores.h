#ifndef PROVEEDORES_H_INCLUDED
#define PROVEEDORES_H_INCLUDED

class Proveedor {
    private:
    char codigo[4];
    char nombre[50];
    char email [50];
    bool estado;

    public:
    void setCodigo();
    void setNombre();
    void setEmail ();
    void setEstado(bool);
    char * getCodigo();
    char * getNombre();
    char * getEmail ();
    int  getPosicion(char[]);
    bool getEstado();
    bool grabarEnDisco(int = -1);
    bool leerDeDisco(int);
    void mostrarRegistro();
    bool validarCodProveedor(char*);

};

void menuProveedores();
void altaProveedor();
void listarProveedores();
void bajaProveedor();


#endif // PROVEEDORES_H_INCLUDED
