/*
 * Component.h
 *
 *  Created on: Nov 14, 2013
 *      Author: slacker
 */

#ifndef COMPONENT_H_
#define COMPONENT_H_

#include <memory>

class Component
{
public:
	virtual ~Component();

	virtual std::string getID() = 0;
};

typedef std::shared_ptr<Component> CompPtr;

#endif /* COMPONENT_H_ */
