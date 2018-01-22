#ifndef _INTEGER_H_
#define _INTEGER_H_

#include "Object.h"


class Integer : public Object {

    int int_value;

public:

    Integer();

    virtual void printObject() const override;


};