#include "pch.h"
#include "prestamoPersonal.h"
#include "prestamo.h"
#include "banco.h"
#include <string>
#include <iostream>
#include <ctime>
using namespace std;

//Instancia de banco para realizar acciones en torno a la informacion que posee
banco accionBanco;

void prestamoPersonal::mostrarInformacion()
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

void prestamoPersonal::calcularInteres()
{
	int Noprestamo;
	accionBanco.getListaUnTipo("Personal");
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
	double resultadoInteres;
	double interesPrestamoPersonal = 0.0685;
	double saldoPrestamoPersonal = accionBanco.getMontoInicialPrestamo(Noprestamo-1);
	int numeroDiasTranscurridos;

	//Obtener la fecha actual de la computadora
	time_t now = time(0);
	tm* fechaComputadora = localtime(&now);
	int mesActual = fechaComputadora->tm_mon + 1; //Para obtener el mes correcto se suma '1'
	int mesUltimoPago = (mesActual - 2) % 12;
	if (mesUltimoPago == 0) mesUltimoPago = 12; //Ajuste para que siga trabajando dentro de los 12 meses
	numeroDiasTranscurridos = 2 * 30;

	//Aplicacion de la ecuacion para calculo de interes
	resultadoInteres = (saldoPrestamoPersonal * interesPrestamoPersonal * numeroDiasTranscurridos) / 360;

	cout << "--------------------------------------------------------------------------" << endl;
	cout << "Calculando interes... " << endl;
	cout << "El interes del prestamo " << accionBanco.getNoPrestamo(Noprestamo-1) << "es: " << resultadoInteres << endl;
	cout << "--------------------------------------------------------------------------" << endl;
}

void prestamoPersonal::abonarMonto()
{
	int numeroPrestamoPersonal;
	double monto;
	double nuevoSaldo;
	cout << "-----------------------------------LISTA PRESTAMOS PERSONALES-----------------------------------" << endl;
	accionBanco.getListaUnTipo("Personal");
	cout << "--------------------------------------------------------------------------" << endl;
	cout << "Ingrese el numero de la cuenta que desea abonar: " << endl;
	do
	{
		cin >> numeroPrestamoPersonal;
	} while (numeroPrestamoPersonal < 0 && numeroPrestamoPersonal > accionBanco.getCapacidadArreglo());

	double saldoDeCuenta = accionBanco.getMontoInicialPrestamo(numeroPrestamoPersonal-1);

	cout << "Ingrese el monto a depositar (No ingrese un numero menor a cero o mayor al monto): " << endl;
	do
	{
		cin >> monto;
	} while (monto < 0 && monto > saldoDeCuenta);

	cout << "---------------------------------------------------------------------------------" << endl;
	cout << "Realizando pago......." << endl;
	nuevoSaldo = saldoDeCuenta - monto;
	accionBanco.setNuevoMontoPrestamo(numeroPrestamoPersonal - 1, nuevoSaldo);
}