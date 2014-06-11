#include <string>

class Farmacologico;

using namespace std;

class Medicamento
{
private:
	string	nombre;

public:
	//Creadoras
	Medicamento(string nombre,Farmacologico farmacologico);

	//Getters
	string	getNombre();

	//Setters
	void	setNombre(string nombre);
};
