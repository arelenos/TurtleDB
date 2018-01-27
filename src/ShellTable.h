#include "MetaRow.h"
#include "String.h"

// #include <string>
// #include <vector>
#include <iostream>
#include <map>

// 
#define MAX_ROW_SIZE 1000
#define MAX_COL_SIZE 1000000

enum class FileExtension { CSV, BIN, TXT }; // XLSX? :D



// Instead of recreating this from scratch
//  We can "borrow" from my vector class
class TurtleRow {
    std::size;
    std::capacity;
    Object *row_data;
public:
    TurtleRow(int num_objects) {};
    ~TurtleRow() {};
};

class TurtleCol {};
class MetaTable {};

// Possibly have exceptions inherit from other exceptions?
class NullPointerException {};
class AllocationTooLargeException {};

class InvalidTableInput {};

typedef std::vector<std::string> VectorStr;
typedef TurtleRow* TurtleRowPtr;
typedef TurtleCol* TurtleColPtr;

class TurtleTable {

    std::size_t num_cols;
	std::size_t num_rows;

	TurtleRowPtr *row_data;
	TurtleColPtr *col_data;

	MetaRow meta_row; 
	MetaTable meta_data; // Shouldnt meta table contain meta row?

	void _constructTableFromCSV(std::string fileloc);
	void _constructTableFromBIN(std::string fileloc);
    void _constructTableFromTXT(std::string fileloc);
    

    void allocateData();
    void displayTable();

    MetaRow getMetaRow(FILE file);



public:

    TurtleTable(std::size_t num_rows, std::size_t num_cols, MetaRow row_data); // Reserve space

    TurtleTable(VectorStr types, VectorStr labels);

    TurtleTable(std::string filename);


    // TurtleTable(const TurtleTable &other); // Copy Constructor //  No need if implementing swap function
   
    TurtleTable(TurtleTable &&other); // Move constructor
    friend void swap(TurtleTable &a, TurtleTable &b);
    
    TurtleTable &operator=(TurtleTable other); // Copy assignment

	// May not be necessary to have multiple prototypes...
	// Especially if explicit keyword is NOT used.
	void constructTableFromCSV(std::string filename);
	void constructTableFromCSV(char *filename);
    void writeTable(std::string fileloc, FileExtension ext);

    // We are going to want an iterator that iterates over the columns and rows

	~TurtleTable();

};

