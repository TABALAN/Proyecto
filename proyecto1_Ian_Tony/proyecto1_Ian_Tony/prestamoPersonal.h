#pragma once
#include "prestamo.h"
#include <string>
#include <list>
#include <iostream>
using namespace std;
class prestamoPersonal : public prestamo
{
public:
	prestamoPersonal() : prestamo() {} //Constructor de la clase heredando del constructor padre
	virtual ~prestamoPersonal() {} //Destructor

	void mostrarInformacion() override;
	void calcularInteres() override;
};

