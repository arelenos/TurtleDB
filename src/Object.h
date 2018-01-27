#ifndef _OBJECT_H_
#define _OBJECT_H_

#include "Utils.h"
class String;
#include <cstdlib>
#include <string>

class Object {


protected:

    TurtleType object_type;
    
public:

    // virtual ~Object() = 0;
    Object(TurtleType object_type) : object_type{object_type} {}
    // virtual unsigned int getObjectSize() const;

    // virtual bool operator==(Object &other) const = 0;
    // virtual bool operator!=(Object &other) const = 0;
    // virtual bool operator>(Object &other) const = 0;
    // virtual bool operator<(Object &other) const = 0;
    // virtual int compareObject(Object &other) const = 0;
    virtual String toString() const = 0;

    virtual void printObject() const = 0;

};



#endif
