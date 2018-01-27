#include "String.h"
#include <algorithm>

String::String(std::string value) : str_value{value}, Object(String_TT) {}


bool String::operator==(String &other) const override {
    return this->str_value == other.str_value;
}

bool String::operator!=(String &other) const override {
    return not (*this == other);

}

bool String::operator>(String &other) const override {
    return this->str_value > other.str_value;
}

bool String::operator<(String &other) const override {
    return this->str_value < other.str_value;

}

String String::operator+(String &other) const override {
    return String(this->str_value + other.str_value);
}

String &String::operator+=(String &other) const override {
    this->str_value += other.str_value;
}

String String::toString() const override {
    return *this;

}

void String::printObject() const override {
    std::cout << this->str_value;
}

void String::toLower() {
    std::transform(
        this->str_value.begin(), 
        this->str_value.end(), 
        this->str_value.begin(), 
        ::tolower);
}

void String::toUpper() {
    std::transform(
        this->str_value.begin(), 
        this->str_value.end(), 
        this->str_value.begin(), 
        ::toupper);
}

Integer String::to_integer() {
    return Integer(std::stoi(this->str_value));
}