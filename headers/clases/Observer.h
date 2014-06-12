/*
 * Observer.h
 *
 *  Created on: 11/06/2014
 *      Author: matias
 */

#ifndef OBSERVER_H_
#define OBSERVER_H_

class Parametro;

class Observer
{
public:
	Observer();

	virtual void update(Parametro*)=0;

	virtual ~Observer();
};



#endif /* OBSERVER_H_ */
