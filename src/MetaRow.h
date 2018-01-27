#ifndef _METAROW_H_
#define _METAROW_H_

class Object;


class MetaRow {

    int row_id;
    int row_size;
    int row_capacity;
        
    string label[];
    Object **row_data;

public:

    MetaRow(string );
    ~MetaRow() { delete[] this->row_data; }


    int getRowSize() { return this->row_size;

    TurtleType getType(size_t t);
};


#endif
