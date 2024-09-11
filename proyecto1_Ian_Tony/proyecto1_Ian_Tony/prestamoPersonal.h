#include "prestamo.h"
#include <string>
#include <list>
#include <iostream>
using namespace std;

class prestamoPersonal : public prestamo
{
public:
    prestamoPersonal() : prestamo() {}
    virtual ~prestamoPersonal() {}

    void calcularInteres() override;
    void mostrarInformacion() override;
    void abonarMonto() override;
};
