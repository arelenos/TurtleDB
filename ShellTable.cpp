#include <iostream>
#include <Map>
using namespace std;

class ShellTable {
        MetaTable meta_data;
        MetaRow meta_row; 
        Row **rows;
        Column **columns;

        ShellTable(int numCols, String types[], String values[]){
                int numRows = values.size() / numCols+1;
                for(int j = 0; j < numRows; j++){
                      
                        for(int i = 0; i < numCols; ++i){
                        
                        }
        }

        ~ShellTable(){
                delete *rows;
                delete *colums;
        }
        
};
