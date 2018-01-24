#include <iostream>

using namespace std;



class String : public Object {
    char *str_data;
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




};

enum class TurtleType { String, Integer, GiantInt, Double, Bool, Char };

class Object {

    TurtleType object_type;
    
public:

    virtual ~Object() = 0;

    std::size_t getObjectSize();

    virtual bool operator==(Object &other) = 0;
    virtual bool operator>(Object &other) = 0;
    virtual bool operator<(Object &other) = 0;
    virtual int compareObject(Object &other) = 0;
    virtual Object *duplicate() const = 0;

};

//Push test
class MetaRow {
   
    int row_id;
    int row_size;
    int row_capacity;

    Object **_row_data;

public:

    MetaRow();
    ~MetaRow() { delete[] _row_data; }
    int getRowSize();


};
