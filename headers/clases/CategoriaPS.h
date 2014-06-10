#ifndef CATEGORIAPS_H_
#define CATEGORIAPS_H_

#include <string>

using namespace std;

class CategoriaPS
{
private:
	char	codigoCPS;
	string	nombre;

public:
	//Constructores
	CategoriaPS(char codigoCPS,string nombre);

	//Getters
	char	getCodigoCPS();
	string	getNombre();

	//Setters
	void	setCodigoCPS(char codigoCPS);
	void	setNombre(string nombre);
};

#endif /* CATEGORIAPS_H_ */
