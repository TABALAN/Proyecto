#include "pch.h"
#include "prestamoPersonal.h"
#include "banco.h"
#include <list>
#include <string>
#include <iostream>
#include <ctime>
using namespace std;

prestamoPersonal::prestamoPersonal() {} //Constructor de la clase

//Instancia de banco para realizar acciones en torno a la informacion que posee
banco accionBanco;
prestamo accionPrestamo;

void prestamoPersonal::mostrarInformacion()
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

void prestamoPersonal::calcularInteres()
{
	double resultadoInteres;
	double interesPrestamoPersonal = 0.0685;
	double saldoPrestamoPersonal = accionPrestamo.getSaldoPrincipal();
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
	cout << "El interes del prestamo " << accionPrestamo.getidentificadorPrestamo() << "es: " << resultadoInteres << endl;
	cout << "--------------------------------------------------------------------------" << endl;
}
