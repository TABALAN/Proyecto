#pragma once
#include "prestamo.h"
#include <string>
#include <list>
#include <iostream>
using namespace std;

class prestamoAutomovil : public prestamo
{
public:
	prestamoAutomovil() : prestamo() {}  //Constructor heradado

	virtual ~prestamoAutomovil() {}

	void calcularInteres() override;
	void mostrarInformacion() override;
	void abonarMonto() override;
};

