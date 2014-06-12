/*
 * Singleton.h
 *
 *  Created on: 12/06/2014
 *      Author: matias
 */

#ifndef SINGLETON_H_
#define SINGLETON_H_

class Singleton
{
private:
	Singleton();

	static Singleton*	instancia;

public:
	static Singleton*	getInstance();

	virtual ~Singleton();
};

Singleton* Singleton::instancia=NULL;

#endif /* SINGLETON_H_ */
