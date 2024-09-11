#pragma once
#include "prestamo.h"
#include <string>
#include <list>
#include <iostream>
using namespace std;

class prestamoHipotecario : public prestamo
{
private:
	double euribor = 0.03094;
	double diferencial = 0.04;
public:
	prestamoHipotecario() : prestamo() {} //Constructor heredado
	virtual ~prestamoHipotecario() {} //Destructor

	//getters para los atributos privados de esta clase
	double getEuribor() { return euribor; }
	double getDiferencial() { return diferencial; }

	void mostrarInformacion() override;
	void calcularInteres() override;
	void abonarMonto() override;
};

