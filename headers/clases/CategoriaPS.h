#ifndef CATEGORIAPS_H_
#define CATEGORIAPS_H_

#include <string>
#include <set>

class DTReprEstandarizada;
class DTProblemaSalud;
class DTCategoriaPS;
class ProblemaSalud;

using namespace std;

class CategoriaPS
{
private:
	string				codigoCPS;
	string				etiqueta;
	set<ProblemaSalud*>	problemasSalud;

public:
	//Constructores
	CategoriaPS(string codigoCPS,string etiqueta);

	//Getters
	string	getCodigoCPS();
	string	getEtiqueta();
	set<ProblemaSalud*> getProbSal();

	//Setters
	void	setCodigoCPS(string codigoCPS);
	void	setEtiqueta(string nombre);
	void	setProbSal(set<ProblemaSalud*>);

	ProblemaSalud*		buscarPS(string);
	DTReprEstandarizada	obtenerReprEstandarizada(); //CUIDADO: Creo que puede ser un conjunto lo que devuelve
	DTProblemaSalud*	obtenerPS(); //CUIDADO: Creo que puede ser un conjunto lo que devuelve
	DTCategoriaPS obtenerCategoria();

	~CategoriaPS();
};

#endif /* CATEGORIAPS_H_ */
