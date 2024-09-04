#include "pch.h"
#include "prestamoAutomovil.h"
#include "banco.h"
#include "prestamo.h"
#include <string>
#include <list>
#include <iostream>
using namespace std;

prestamoAutomovil::prestamoAutomovil() {} //Constructor

//Instancia de banco para realizar acciones en torno a la informacion que posee
banco accionBanco;
prestamo accionPrestamo;

void prestamoAutomovil::mostrarInformacion()
{
	int noPrestamo;
	bool encontrado = false;
	cout << "------------------------ Lista de prestamos -----------------------------" << endl;
	accionPrestamo.getListaPagos();
	cout << "-----------------------------------------------------" << endl;
	while (encontrado == false) {
		cout << "Por favor ingrese el numero del prestamo que desea consultar: " << endl;
		cin >> noPrestamo;

		//Buscar dentro de la lista específicada en el get, en un rango de begin a end
		auto it = find(accionPrestamo.getListaPagos().begin(), accionPrestamo.getListaPagos().end(), noPrestamo);

		if (it != accionPrestamo.getListaPagos().end()) {
			cout << "Elemento encontrado... " << endl;
			encontrado = true;
		}
		else {
			cout << "Elemento no encontrado" << endl;
		}
	}
	accionBanco.getPrestamoPorNumero(noPrestamo);
}

void prestamoAutomovil::calcularInteres() 
{
	double montoPrestamoAutomovil = accionPrestamo.getMontoIncial();

}