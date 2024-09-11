#include "pch.h"
#include "prestamoHipotecario.h"
#include "banco.h"
#include <list>
#include <string>
#include <iostream>
using namespace std;

banco accionBanco;

void prestamoHipotecario::mostrarInformacion()
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

void prestamoHipotecario::calcularInteres()
{
	int Noprestamo;
	accionBanco.mostrarListaPrestamos();
	cout << "---------------------------------------------------------" << endl;
	cout << "Ingrese el numero de prestamo que desea calcular: " << endl;
	bool validacion = true;
	while (validacion == true)
	{
		cin >> Noprestamo;
		if (Noprestamo < accionBanco.getCapacidadArreglo() && Noprestamo > accionBanco.getCapacidadArreglo())
		{
			cout << "El numero no es valido, ingrese de nuevo. " << endl;
		}
	}
	double interesPrestamoHipotecario = accionBanco.getMontoInicialPrestamo(Noprestamo-1) * ((getEuribor() + getDiferencial()) / 12);
	cout << "--------------------------------------------------------------------------" << endl;
	cout << "Calculando interes... " << endl;
	cout << "El interes del prestamo " << accionBanco.getNoPrestamo(Noprestamo-1) << "es: " << interesPrestamoHipotecario << endl;
	cout << "--------------------------------------------------------------------------" << endl;
}

void prestamoHipotecario::abonarMonto()
{
	int numeroPrestamoHipotecario;
	double monto;
	double nuevoSaldo;
	cout << "-----------------------------------LISTA PRESTAMOS PERSONALES-----------------------------------" << endl;
	accionBanco.getListaUnTipo("Hipotecario");
	cout << "--------------------------------------------------------------------------" << endl;
	cout << "Ingrese el numero de la cuenta que desea abonar: " << endl;
	do
	{
		cin >> numeroPrestamoHipotecario;
	} while (numeroPrestamoHipotecario < 0 && numeroPrestamoHipotecario > accionBanco.getCapacidadArreglo());

	double saldoDeCuenta = accionBanco.getMontoInicialPrestamo(numeroPrestamoHipotecario - 1);

	cout << "Ingrese el monto a depositar (No ingrese un numero menor a cero o mayor al monto): " << endl;
	do
	{
		cin >> monto;
	} while (monto < 0 && monto > saldoDeCuenta);

	cout << "---------------------------------------------------------------------------------" << endl;
	cout << "Realizando pago......." << endl;
	nuevoSaldo = saldoDeCuenta - monto;
	accionBanco.setNuevoMontoPrestamo(numeroPrestamoHipotecario - 1, nuevoSaldo);
}