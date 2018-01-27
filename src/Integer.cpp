#include "Integer.h"
#include "String.h"
#include <sstream>


Integer::Integer(const int value) : Object(TurtleType::Integer_TT), int_value{value} {}



Integer::Integer(const char *value) : Object(TurtleType::Integer_TT) {
    this->int_value = atoi(value);
}


Integer::Integer(const std::string value) : Object(TurtleType::Integer_TT) {
    std::stringstream convert(value);
    convert >> this->int_value;
}

Integer::Integer(const String value) : Object(TurtleType::Integer_TT) {
    this->int_value = value.toInteger();
}

// Unneeded?
// unsigned int getObjectSize() const override {
//     return sizeof(*this);
// }

bool Integer::operator==(const Integer &other) const override {
    return this->int_value == other.int_value;
}

bool Integer::operator!=(const Integer &other) const override {
    return not (*this == other);
}

bool Integer::operator>(const Integer &other) const override {
    return this->int_value > other.int_value;
}

bool Integer::operator<(const Integer &other) const override {
    return this->int_value < other.int_value;

}

// int Integer::compareObject(Integer &other) const override {

// }

Integer Integer::operator+(const Integer &other) const {
    return Integer(this->int_value + other.int_value);
}

Integer Integer::operator-(const Integer &other) const {
    return Integer(this->int_value - other.int_value);
}

Integer Integer::operator*(const Integer &other) const {
    return Integer(this->int_value * other.int_value);
    
}

Integer Integer::operator/(const Integer &other) const {
    return Integer(this->int_value * other.int_value);

}

Integer Integer::operator%(const Integer &other) const {
    return Integer(this->int_value % other.int_value);
}

Integer &Integer::operator+=(const Integer &other) {
    this->int_value += other.int_value;
    return *this;
}

Integer &Integer::operator-=(const Integer &other) {
    this->int_value -= other.int_value;
    return *this;
}

Integer &Integer::operator*=(const Integer &other) {
    this->int_value *= other.int_value;
    return *this;
}

Integer &Integer::operator/=(const Integer &other) {
    this->int_value /= other.int_value;
    return *this;
}

String Integer::toString() const override {
    return String(std::to_string(this->int_value));

}

void Integer::printObject() const override {
    std::cout << this->int_value;
}
