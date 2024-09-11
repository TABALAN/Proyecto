#include "pch.h"
#include "banco.h"
using namespace std;
#include <vector>
#include <string>
#include <iostream>

banco::banco() { 
	punteroEstructuraPrestamo = new prestamoCompleto[capacidadArreglo];
	//Llenar el arreglo con un par de prestamos
	prestamoCompleto prestamo1 = { "Personal", 00101, 5000.75, 0.0685, 10 };
	prestamoCompleto prestamo2 = { "Hipoteca", 00463, 75000.60, 0.07, 7 };
}

void banco::expandirArreglo() {
	//Al necesitar más espacio en el arreglo, duplicar la capacidad y copiar los datos en uno nuevo
	capacidadArreglo = capacidadArreglo * 2;
	prestamoCompleto* arregloExpandido = new prestamoCompleto[capacidadArreglo];

	for (int i = 0; i < getCapacidadArreglo(); i++)
	{
		arregloExpandido[i] = punteroEstructuraPrestamo[i];
	}
	delete[] punteroEstructuraPrestamo;

	punteroEstructuraPrestamo = arregloExpandido;
}

void banco::agregarPrestamo(const prestamoCompleto& nuevoPrestamo)
{
	if (getCapacidadArreglo() == capacidadArreglo) {
		expandirArreglo();
	}
	punteroEstructuraPrestamo[getCapacidadArreglo()+1] = nuevoPrestamo;
}

void banco::mostrarListaPrestamos() const
{
	cout << "------------------------------LISTA PRESTAMOS-----------------------------------" << endl;
	for (int i = 0; i < getCapacidadArreglo(); i++)
	{
		cout << "Prestamo " << (i + 1) << " de tipo: " << punteroEstructuraPrestamo[i].tipo;
	}
}

void banco::mostrarPrestamosExistentes() const
{
	cout << "-----------------------------PRESTAMOS-------------------------------" << endl;
	for (int i = 0; i < getCapacidadArreglo(); ++i) 
	{
		cout << "Prestamo " << (i + 1) << ":" << endl;
		cout << "Tipo de prestamo:" << punteroEstructuraPrestamo[i].tipo << endl;
		cout << "Monto Inicial: " << punteroEstructuraPrestamo[i].montoInicial << endl;
		cout << "Tasa de Interés: " << punteroEstructuraPrestamo[i].tasaInteres * 100 << "%" << endl;
		cout << "Plazo de Pagos: " << punteroEstructuraPrestamo[i].plazoPagos << endl;
	}
}

prestamoCompleto* banco::getPrestamoPorNumero(int numero) const {

	for (int i = 0; i < getCapacidadArreglo(); ++i) {
		if (punteroEstructuraPrestamo[i].numeroPrestamo == numero) {
			cout << "----------------------------------- Informacion del prestamo " << numero << "-------------------------------" << endl;
			cout << "Monto Inicial: " << punteroEstructuraPrestamo[i].montoInicial << endl;
			cout << "Tasa de Interés: " << punteroEstructuraPrestamo[i].tasaInteres << endl;
			cout << "Plazo de Pagos: " << punteroEstructuraPrestamo[i].plazoPagos << endl;
		}
	}
}

prestamoCompleto* banco::getListaUnTipo(string tipo) const {
	for (int i = 0; i < getCapacidadArreglo(); ++i) {
		if (punteroEstructuraPrestamo[i].tipo == tipo) {
			cout << "----------------------------------- Informacion del prestamo " << tipo << "-------------------------------" << endl;
			cout << "Numero prestamo: " << punteroEstructuraPrestamo[i].numeroPrestamo << endl;
			cout << "Monto Inicial: " << punteroEstructuraPrestamo[i].montoInicial << endl;
			cout << "Tasa de Interés: " << punteroEstructuraPrestamo[i].tasaInteres << endl;
			cout << "Plazo de Pagos: " << punteroEstructuraPrestamo[i].plazoPagos << endl;
		}
	}
	return 0;
}

double banco::getMontoInicialPrestamo(int indice) const {

	if (indice >= 0 && indice < getCapacidadArreglo()) {
		return punteroEstructuraPrestamo[indice].montoInicial;
	}
	else {
		// Manejar el caso de índice fuera de rango,
		cerr << "Índice fuera de rango." << endl;
		return 0;
	}
}

int banco::getNoPrestamo(int indice) const {
	if (indice >= 0 && indice < getCapacidadArreglo()) {
		return punteroEstructuraPrestamo[indice].numeroPrestamo;
	}
}

void banco::setNuevoMontoPrestamo(int indice, double monto) const {
	if (indice >= 0 && indice < getCapacidadArreglo())
	{
		punteroEstructuraPrestamo[indice].montoInicial = monto;
	}
}

void banco::setEliminarPrestamoCompleto(int indice) const {

	if (indice >= 0 && indice < getCapacidadArreglo()) {
		// Mover los elementos a la izquierda para eliminar el préstamo en el índice especificado
		for (int i = indice; i < getCapacidadArreglo() - 1; ++i) {
			punteroEstructuraPrestamo[i] = punteroEstructuraPrestamo[i + 1];
		}
		// Reducir el tamaño lógico del arreglo
		(getCapacidadArreglo() - 1);
	}
}

int banco::setNumeroPrestamoNuevo() const {
	return noNuevosPrestamos + 1;
}

int banco::getCapacidadArreglo() const {
	return sizeInicialArreglo;
}