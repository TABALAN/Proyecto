#include "pch.h"
#include "prestamoAutomovil.h"
#include "banco.h"
#include "prestamo.h"
#include <string>
#include <list>
#include <iostream>
using namespace std;

//Instancia de banco para realizar acciones en torno a la informacion que posee
banco accionBanco;
prestamo accionPrestamo;

void prestamoAutomovil::mostrarInformacion()
{
	int noPrestamo;
	cout << "------------------------ Lista de prestamos -----------------------------" << endl;
	accionBanco.mostrarListaPrestamos();
	cout << "-------------------------------------------------------------------------------------------------------" << endl;
	cout << "Ingresa el numero de prestamo que desea consultar (indice de la lista): " << endl;
	do
	{
		cin >> noPrestamo;
	} while (noPrestamo < 0 && noPrestamo > accionBanco.getCapacidadArreglo());
	accionBanco.getPrestamoPorNumero(noPrestamo);
}

void prestamoAutomovil::calcularInteres() 
{
	int Noprestamo;
	accionBanco.getListaUnTipo("Automovil");
	cout << "---------------------------------------------------------" << endl;
	cout << "Ingrese el numero de prestamo que desea calcula: " << endl;
	bool validacion = true;
	while (validacion == true)
	{
		cin >> Noprestamo;
		if (Noprestamo < accionBanco.getCapacidadArreglo() && Noprestamo > accionBanco.getCapacidadArreglo())
		{
			cout << "El numero no es valido, ingrese de nuevo. " << endl;
		}
	}
	double montoPrestamoAutomovil = accionBanco.getMontoInicialPrestamo(Noprestamo-1);
	double interesMensualAutomovil = static_cast<double>(0.0915) / 12;
	int plazoMeses = 7;

	double resultadoInteresAutomovil = (montoPrestamoAutomovil * interesMensualAutomovil) / (pow(1 - (1 + interesMensualAutomovil), -plazoMeses));

	cout << "--------------------------------------------------------------------------" << endl;
	cout << "Calculando interes... " << endl;
	cout << "El interes del prestamo " << accionBanco.getNoPrestamo(Noprestamo-1) << "es: " << interesMensualAutomovil << endl;
	cout << "--------------------------------------------------------------------------" << endl;
}

void prestamoAutomovil::abonarMonto()
{
	int numeroPrestamoAutomovil;
	double monto;
	double nuevoSaldo;
	cout << "-----------------------------------LISTA PRESTAMOS AUTOMOVILES-----------------------------------" << endl;
	accionBanco.getListaUnTipo("Automovil");
	cout << "--------------------------------------------------------------------------" << endl;
	cout << "Ingrese el numero de la cuenta que desea abonar: " << endl;
	do
	{
		cin >> numeroPrestamoAutomovil;
	} while (numeroPrestamoAutomovil < 0 && numeroPrestamoAutomovil > accionBanco.getCapacidadArreglo());

	double saldoDeCuenta = accionBanco.getMontoInicialPrestamo(numeroPrestamoAutomovil - 1);

	cout << "Ingrese el monto a depositar (No ingrese un numero menor a cero o mayor al monto): " << endl;
	do
	{
		cin >> monto;
	} while (monto < 0 && monto > saldoDeCuenta);

	cout << "---------------------------------------------------------------------------------" << endl;
	cout << "Realizando pago......." << endl;
	nuevoSaldo = saldoDeCuenta - monto;
	accionBanco.setNuevoMontoPrestamo(numeroPrestamoAutomovil - 1, nuevoSaldo);
}