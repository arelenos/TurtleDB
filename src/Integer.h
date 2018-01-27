#ifndef _INTEGER_H_
#define _INTEGER_H_

#include "Object.h"

class Integer : public Object {

    int int_value;


public:
    // No need to overload with double/long etc, since NOT explicit
    Integer(const int value);
    Integer(const char *value);
    Integer(const std::string value);
    Integer(const String value);


    virtual bool operator==(Integer &other) const override;
    virtual bool operator!=(Integer &other) const override;
    virtual bool operator>(Integer &other) const override;
    virtual bool operator<(Integer &other) const override;

    Integer operator+(Integer &other) const;
    Integer operator-(Integer &other) const;
    Integer operator*(Integer &other) const;
    Integer operator/(Integer &other) const;
    Integer operator%(Integer &other) const;

    Integer &operator+=(Integer &other);
    Integer &operator-=(Integer &other);
    Integer &operator*=(Integer &other);
    Integer &operator/=(Integer &other);

    virtual String toString() const override;

    virtual void printObject() const override;



};

#endif
