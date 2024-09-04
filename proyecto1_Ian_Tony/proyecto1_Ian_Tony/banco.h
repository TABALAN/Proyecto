using namespace std;
#include <vector>
#include <string>

struct prestamoCompleto {
	int numeroPrestamo;
	double montoInicial;
	double tasaInteres;
	int plazoPagos;
};

class banco
{
private:
	prestamoCompleto* punteroEstructuraPrestamo = nullptr;
	int sizeInicialArreglo = 0;
	int capacidadArreglo = 1;
public:
	banco() {};

	~banco() { delete[] punteroEstructuraPrestamo; }

	void expandirArreglo() {}

	void agregarPrestamo(const prestamoCompleto& nuevoPrestamo){}

	void mostrarPrestamosExistentes() const {}

	int getCapacidadArreglo() const { return sizeInicialArreglo; }

	prestamoCompleto* getPrestamoPorNumero(int numero) const;
};