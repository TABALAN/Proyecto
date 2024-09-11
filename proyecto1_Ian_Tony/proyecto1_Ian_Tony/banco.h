#ifndef BANCO_H
#define BANCO_H
using namespace std;
#include <vector>
#include <string>

struct prestamoCompleto {
	string tipo;
	int numeroPrestamo;
	double montoInicial;
	double tasaInteres;
	int plazoPagos;
};

class banco
{
private:
	prestamoCompleto* punteroEstructuraPrestamo = nullptr;
	int sizeInicialArreglo = 1;
	int capacidadArreglo = 1;
	int noNuevosPrestamos = 100;
public:
	banco();

	~banco() { delete[] punteroEstructuraPrestamo; }

	void expandirArreglo();

	void agregarPrestamo(const prestamoCompleto& nuevoPrestamo);

	void mostrarPrestamosExistentes() const;

	void mostrarListaPrestamos() const;

	int getCapacidadArreglo() const;

	prestamoCompleto* getPrestamoPorNumero(int numero) const;

	double getMontoInicialPrestamo(int indice) const;

	void setEliminarPrestamoCompleto(int indice) const;

	int setNumeroPrestamoNuevo() const;

	void setNuevoMontoPrestamo(int indice, double monto) const;
	
	prestamoCompleto* getListaUnTipo(string tipo) const;

	int getNoPrestamo(int indice) const;
};

#endif