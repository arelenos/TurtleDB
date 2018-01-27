#ifndef _INTEGER_H_
#define _INTEGER_H_

#include "Object.h"

class CannotCastTypeAsInt {};

class Integer : public Object {

    int int_value;

public:
    // No need to overload with double/long etc, since NOT explicit
    Integer(const int value);
    Integer(const char *value);
    Integer(const std::string value);
    Integer(const String value);

    virtual unsigned int getObjectSize() const;

    virtual bool operator==(Object &other) const = 0;
    virtual bool operator!=(Object &other) const = 0;
    virtual bool operator>(Object &other) const = 0;
    virtual bool operator<(Object &other) const = 0;
    virtual int compareObject(Object &other) const = 0;
    virtual Object operator+(Object &other) const = 0;
    virtual Object &operator+=(Object &other) = 0;
    virtual String toString() const = 0;

    virtual Object *duplicate() const = 0;

    virtual void printObject() const = 0;



};

#endif
