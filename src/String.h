#ifndef _STRING_H_
#define _STRING_H_

#include "Object.h"
#include "Integer.h"


#include <string>

// Can easily optimize this class by using char array... later.
class String : public Object {

    std::string str_value;

public:

    String(std::string value);

    
    bool operator==(String &other) const;
    bool operator!=(String &other) const override;
    bool operator>(String &other) const override;
    bool operator<(String &other) const override;

    String operator+(String &other) const;
    String &operator+=(String &other) const;

    String toString() const override;

    void printObject() const override;

    String &toLower();
    String &toUpper();
    Integer to_integer();



};

#endif