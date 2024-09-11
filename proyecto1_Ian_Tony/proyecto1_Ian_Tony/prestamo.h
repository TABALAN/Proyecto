#pragma once
#include <string>
#include <list>
#include <iostream>
#include "banco.h"
using namespace std;

class prestamo
{
private:
    double montoInicial;
    double saldoPrincipal;
    double tasaInteres;
    int identificadorPrestamo;
    int plazo;

public:
    prestamo();
    banco accionBanco;

    virtual void calcularInteres() = 0;
    virtual void mostrarInformacion() = 0;  
    virtual void abonarMonto() = 0;
    virtual void registrarPagoInteres(double monto) = 0;

    double getMontoIncial() const { return montoInicial; }
    int getidentificadorPrestamo() const { return identificadorPrestamo; }
    double getSaldoPrincipal(int indice) const { return accionBanco.getMontoInicialPrestamo(indice); }
    double getTasaInteres() const { return tasaInteres; }
    int getPlazo() const { return plazo; }

    void setMontoInicial(double cambiomonto) { montoInicial = cambiomonto; }
    void setIdentificadorPrestamo(int cambioidentificacion) { identificadorPrestamo = cambioidentificacion; }
    void setSaldoPrincipal(double cambiosaldoprincipal) { saldoPrincipal = cambiosaldoprincipal; }
    void setTasaInteres(int cambioplazo) { plazo = cambioplazo; }
};
