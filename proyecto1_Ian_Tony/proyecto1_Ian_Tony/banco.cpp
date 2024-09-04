#include "pch.h"
#include "banco.h"
using namespace std;
#include <vector>
#include <string>
#include <iostream>

banco::banco() { punteroEstructuraPrestamo = new prestamoCompleto[capacidadArreglo]; }

void banco::expandirArreglo() {
	//Al necesitar más espacio en el arreglo, duplicar la capacidad y copiar los datos en uno nuevo
	capacidadArreglo = capacidadArreglo * 2;
	prestamoCompleto* arregloExpandido = new prestamoCompleto[capacidadArreglo];

	for (int i = 0; i < sizeInicialArreglo; i++)
	{
		arregloExpandido[i] = punteroEstructuraPrestamo[i];
	}
	delete[] punteroEstructuraPrestamo;

	punteroEstructuraPrestamo = arregloExpandido;
}

void banco::agregarPrestamo(const prestamoCompleto& nuevoPrestamo)
{
	if (sizeInicialArreglo == capacidadArreglo) {
		expandirArreglo();
	}
	punteroEstructuraPrestamo[sizeInicialArreglo++] = nuevoPrestamo;
}

void banco::mostrarPrestamosExistentes() const 
{
	for (int i = 0; i < sizeInicialArreglo; ++i) 
	{
		cout << "Préstamo " << (i + 1) << ":" << endl;
		cout << "Monto Inicial: " << punteroEstructuraPrestamo[i].montoInicial << endl;
		cout << "Tasa de Interés: " << punteroEstructuraPrestamo[i].tasaInteres << endl;
		cout << "Plazo de Pagos: " << punteroEstructuraPrestamo[i].plazoPagos << endl;
	}
}

prestamoCompleto* banco::getPrestamoPorNumero(int numero) const {

	for (int i = 0; i < sizeInicialArreglo; ++i) {
		if (punteroEstructuraPrestamo[i].numeroPrestamo == numero) {
			cout << "----------------------------------- Informacion del prestamo " << numero << "-------------------------------" << endl;
			cout << "Monto Inicial: " << punteroEstructuraPrestamo[i].montoInicial << endl;
			cout << "Tasa de Interés: " << punteroEstructuraPrestamo[i].tasaInteres << endl;
			cout << "Plazo de Pagos: " << punteroEstructuraPrestamo[i].plazoPagos << endl;
		}
	}
}