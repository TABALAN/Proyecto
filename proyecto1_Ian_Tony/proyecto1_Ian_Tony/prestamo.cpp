#include "pch.h"
#include "prestamo.h"
#include <list>
#include <string>
#include <iostream>
using namespace std;

//Constructor vac�o
prestamo::prestamo() {}

//Definir estructura de los m�todos a sobreescribir en cada clase hija
void prestamo::calcularInteres() {}
void prestamo::mostrarInformacion() {}
void prestamo::abonarMonto(double monto) {}
void prestamo::registrarPagoInteres(double monto) {}