#include <string>
#include <list>
#include <iostream>
using namespace std;
class prestamo
{
private:
	double montoInicial;
	double saldoPrincipal;
	double tasaInteres;
	int identificadorPrestamo;
	int plazo; 
	list<double> listaPagos;

public:
	//Constructor *Por el momento vacío*
	prestamo() : montoInicial(0), saldoPrincipal(0), tasaInteres(0), plazo(0), listaPagos(0) {};

	//Métodos virtuales de los cuales van a heredar las demas clases
	virtual void calcularInteres() {};
	virtual void mostrarInformacion() {};
	virtual void abonarMonto(double monto) {};	
	virtual void registrarPagoInteres(double monto) {};

	//getters and setters
	double getMontoIncial() const { return montoInicial; }
	int getidentificadorPrestamo() const { return identificadorPrestamo; }
	double getSaldoPrincipal() const { return saldoPrincipal; }
	double getTasaInteres() const { return tasaInteres; }
	int getPlazo() const { return plazo; }
	const list<double>& getListaPagos() const { return listaPagos; }

	void setMontoInicial(double cambiomonto) { montoInicial = cambiomonto; }
	void setIdentificadorPrestamo(int cambioidentificacion) { identificadorPrestamo = cambioidentificacion; }
	void setSaldoPrincipal(double cambiosaldoprincipal) { saldoPrincipal = cambiosaldoprincipal; }
	void setTasaInteres(double cambioplazo) { plazo = cambioplazo; }
	void setAgregarListaPagos(const double& pago) { listaPagos.push_back(pago); }
	void setEliminarListaPagos(const double& elemento) 
	{
		auto it = remove(listaPagos.begin(), listaPagos.end(), elemento);
		// Borrar los elementos "removidos" usando erase
		if (it != listaPagos.end()) {
			listaPagos.erase(it, listaPagos.end());
			cout << "El pago '" << elemento << "' ha sido eliminado." << endl;
		}
		else {
			cout << "El pago '" << elemento << "' no se encuentra en la lista." << endl;
		}
	}
};