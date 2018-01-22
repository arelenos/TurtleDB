#ifndef _METAROW_H_
#define _METAROW_H_

class Object;


class MetaRow {

    int row_id;
    int row_size;
    int row_capacity;
    

    Object **row_data;

public:

    MetaRow();
    ~MetaRow() { delete[] this->row_data; }


    int getRowSize() { return this->row_size;


};


#endif
