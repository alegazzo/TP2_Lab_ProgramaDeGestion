#ifndef IDGENERATOR_H_INCLUDED
#define IDGENERATOR_H_INCLUDED

class IDGenerator{
private:
      int pos;
      int ID;
public:
     int generatePos();
      int generateID();
      int getID();
      int getPos();
      bool grabarEnDisco();
      bool leerDisco(int );
};


#endif // IDGENERATOR_H_INCLUDED
