#include <string>

using namespace std;

class Medicamento
{
private:
	string	nombre;

public:
	//Creadoras
	Medicamento(string nombre);

	//Getters
	string	getNombre();

	//Setters
	void	setNombre(string nombre);
};
