#ifndef CATEGORIAPS_H_
#define CATEGORIAPS_H_

#include <string>
#include <set>

class DTReprEstandarizada;
class DTProblemaSalud;
class ProblemaSalud;

using namespace std;

class CategoriaPS
{
private:
	char				codigoCPS;
	string				etiqueta;
	set<ProblemaSalud*>	problemasSalud;

public:
	//Constructores
	CategoriaPS(char codigoCPS,string etiqueta);

	//Getters
	char	getCodigoCPS();
	string	getEtiqueta();

	//Setters
	void	setCodigoCPS(char codigoCPS);
	void	setEtiqueta(string nombre);

	ProblemaSalud*		buscarPS(string);
	DTReprEstandarizada	obtenerReprEstandarizada(); //CUIDADO: Creo que puede ser un conjunto lo que devuelve
	DTProblemaSalud*	obtenerPS(); //CUIDADO: Creo que puede ser un conjunto lo que devuelve
};

#endif /* CATEGORIAPS_H_ */
