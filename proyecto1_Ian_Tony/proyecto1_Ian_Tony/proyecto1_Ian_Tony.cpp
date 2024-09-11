#include "pch.h"
#include "banco.h"
#include "pago.h"
#include "prestamo.h"
#include "prestamoAutomovil.h"
#include "prestamoHipotecario.h"
#include "prestamoPersonal.h"
#include <list>
#include <string>
#include <iostream>
using namespace std;

int main()
{
    banco accionBanco;
    int opcionMenu;
    bool validadOpcionMenu;
    prestamoAutomovil carrito;
    prestamoHipotecario hipoteca;
    prestamoPersonal deuda;
    cout << "Bienvenido usuario a la banca en linea. " << endl;
    cout << "Que desea realizar hoy? Ingrese el numero de opcion: " << endl;
    cout << "--------------------------------------OPCIONES-------------------------------------------" << endl;
    cout << "1. Agregar un nuevo prestamo. " << endl;
    cout << "2. Eliminar un prestamo existente. " << endl;
    cout << "3. Gestinar un prestamo. " << endl;
    cout << "4. Mostrar todos los prestamos. " << endl;
    cout << "5. Salir. " << endl;
    cout << "-----------------------------INGRESE OPCION--------------------------------------" << endl;
    while (validadOpcionMenu) {
        cin >> opcionMenu;
        if (opcionMenu < 1 && opcionMenu > 5)
        {
            cout << "Opcion no valida. Intente de nuevo. " << endl;
        }
    }

    switch (opcionMenu)
    {
        case 1:
        {
            accionBanco.mostrarPrestamosExistentes();
            cout << "-------------------------------Ha elegido agregar nuevo prestamo--------------------------------" << endl;
            string TipoPrestamo;
            cout << "Ingrese el tipo de prestamo (Personal, Automovil, Hipotecario)" << endl;
            do
            {
                cin >> TipoPrestamo;
            } while (TipoPrestamo != "Personal" && TipoPrestamo != "Automovil" && TipoPrestamo != "Hipotecario");

            double montoNuevoPrestamo;
            cout << "Ingrese el monto del nuevo prestamo a realizar: " << endl;
            do { cin >> montoNuevoPrestamo; } while (montoNuevoPrestamo <= 0);

            //Asignar tasa de interes y plazo al préstamo
            double interesNuevoPrestamo;
            int plazoParaPago;

            if (TipoPrestamo == "Personal")
            {
                interesNuevoPrestamo = 0.0685;
                time_t now = time(0);
                tm* fechaComputadora = localtime(&now);
                plazoParaPago = fechaComputadora->tm_mon + 1;
                int mesUltimoPago = (plazoParaPago - 2) % 12;
                if (mesUltimoPago == 0) mesUltimoPago = 12;
            }
            else if (TipoPrestamo == "Automovil")
            {
                interesNuevoPrestamo = 0.0915 / 12;
                plazoParaPago = 12;
            }
            else if (TipoPrestamo == "Hipotecario")
            {
                interesNuevoPrestamo = 0.0536;
                plazoParaPago = 12;
            }
            prestamoCompleto nuevoprestamo = { TipoPrestamo, accionBanco.setNumeroPrestamoNuevo(), montoNuevoPrestamo, interesNuevoPrestamo, plazoParaPago };
            accionBanco.agregarPrestamo(nuevoprestamo);
        }
        case 2:
        {
            cout << "-------------------------------Ha elegido eliminar un presamo existente--------------------------------" << endl;
            int numeroPrestamoAEliminar;
            accionBanco.mostrarPrestamosExistentes();
            cout << "-------------------------------------------------------------------------------------------------------" << endl;
            cout << "Ingresa el numero de prestamo que desea eliminar (indice de la lista): " << endl;
            do
            {
                cin >> numeroPrestamoAEliminar;
            } while (numeroPrestamoAEliminar < 0 && numeroPrestamoAEliminar > accionBanco.getCapacidadArreglo());
            accionBanco.setEliminarPrestamoCompleto(numeroPrestamoAEliminar - 1);
            cout << "Prestamo eliminado con exito..." << endl;
        }
        case 3:
        {
            int opcionMenu2;
            cout << "---------------------------------Ha elegido gestionar un prestamo---------------------------------------" << endl;
            cout << "--------------------------------------OPCIONES-------------------------------------------" << endl;
            cout << "1. Ver informacion de un prestamo. " << endl;
            cout << "2. Abonar al saldo principal del prestamo. " << endl;
            cout << "3. Registrar pago de intereses. " << endl;
            cout << "-----------------------------INGRESE OPCION--------------------------------------" << endl;
            while (opcionMenu2) {
                cin >> opcionMenu2;
                if (opcionMenu2 < 1 && opcionMenu2 > 3)
                {
                    cout << "Opcion no valida. Intente de nuevo. " << endl;
                }
            }
            switch (opcionMenu2)
            {
            case 1:
            {
                cout << "-------------------Ha elegido ver informacion de un prestamo--------------------" << endl;
                int prestamoConsultar;
                accionBanco.mostrarPrestamosExistentes();
                cout << "-------------------------------------------------------------------------------------------------------" << endl;
                cout << "Ingresa el numero de prestamo que desea eliminar (indice de la lista): " << endl;
                do
                {
                    cin >> prestamoConsultar;
                } while (prestamoConsultar < 0 && prestamoConsultar > accionBanco.getCapacidadArreglo());
                accionBanco.getPrestamoPorNumero(prestamoConsultar - 1);
            }
            case 2:
            {
                cout << "----------------------Ha elegido abonar un prestamo------------------------------" << endl;
                int respuesta;
                cout << "Ingrese 1 para prestamo personal, 2 para prestamo automovil y 3 para prestamo hipotecario: " << endl;
                do
                {
                    cin >> respuesta;
                    if (respuesta < 0 && respuesta >3) { cout << "Opcion incorrecta, intente de nuevo. " << endl; }
                } while (respuesta < 0 && respuesta > 3);

                if (respuesta == 1)
                {
                    deuda.abonarMonto();
                }
                else if (respuesta == 2) { carrito.abonarMonto(); }
                else if (respuesta == 3) { hipoteca.abonarMonto(); }
            }
            case 3:
            {
                cout << "Pendiente." << endl;
            }
            }
        case 4:
        {
            accionBanco.mostrarPrestamosExistentes();
        }
    }
}