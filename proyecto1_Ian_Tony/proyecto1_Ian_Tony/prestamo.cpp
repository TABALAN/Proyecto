#include "pch.h"
#include "prestamo.h"
#include <list>
#include <string>
#include <iostream>
using namespace std;

//Constructor vac�o
prestamo::prestamo() : montoInicial(0), saldoPrincipal(0), tasaInteres(0), plazo(0) {}

//Definir estructura de los m�todos a sobreescribir en cada clase hija
void prestamo::calcularInteres() {}
void prestamo::mostrarInformacion() {}
void prestamo::abonarMonto() {}
void prestamo::registrarPagoInteres(double monto) {}