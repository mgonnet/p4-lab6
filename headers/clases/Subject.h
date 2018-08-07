/*
 * Subject.h
 *
 *  Created on: 11/06/2014
 *      Author: matias
 */

#ifndef SUBJECT_H_
#define SUBJECT_H_

#include <set>

class Observer;
class Parametro;

using namespace std;

class Subject
{
private:
	set<Observer*>	observadores;

	virtual void dummy()=0;

public:
	void	addObserver(Observer* observador);
	void	rmObserver(Observer* observador);
	void	notifyAll(Parametro* parametro);
};


#endif /* SUBJECT_H_ */
