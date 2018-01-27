#ifndef _STRING_H_
#define _STRING_H_

#include "Object.h"


#include <string>


class String : public Object {
    
    std::string str_data;
    int str_size;
    int str_capacity;

public:

    String();
    String(std::string s);
    String(char *s);
    ~String();

    void toLower();
    void toUpper();

    virtual Object *duplicate() const;
    virtual ~String();

    virtual void printObject() const override {

    }



};

#endif