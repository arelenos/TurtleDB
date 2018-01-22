#ifndef _OBJECT_H_
#define _OBJECT_H_

#include <cstdlib>

enum class TurtleType { String, Integer, GiantInt, Double, Bool, Char };

class Object {


protected:

    TurtleType object_type;
    
public:

    virtual ~Object() = 0;

    virtual unsigned int getObjectSize() const;

    virtual bool operator==(Object &other) const = 0;
    virtual bool operator>(Object &other) const = 0;
    virtual bool operator<(Object &other) const = 0;
    virtual int compareObject(Object &other) const = 0;
    virtual Object *duplicate() const = 0;

    virtual void printObject() const = 0;

};



#endif
