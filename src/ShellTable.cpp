#include "MetaRow.h"
#include "String.h"

// #include <string>
// #include <vector>
#include <iostream>
#include <map>


struct TurtleRow {};
struct TurtleCol {};
struct MetaTable {};

// Possibly have exceptions inherit from other exceptions?
struct NullPointerException { // No idea if this is correct
	NullPointerException(std::string);
}


class InvalidTableInput {};

typedef std::vector<std::string> VectorStr;

// Please do: file -> preferences -> settings -> set tab size to 4
class ShellTable {
	MetaTable meta_data;
	MetaRow meta_row; 
	TurtleRow **row_data;
	TurtleCol **col_data;
	int num_cols;
	int num_rows;

	ShellTable(VectorStr types, VectorStr labels) {
		if (types.size() != labels.size()) throw InvalidTableInput();
		num_cols = types.size();
		
	}

	// May not be necessary to have multiple prototypes...
	// Especially if explicit keyword is NOT used.
	void constructTableFromCSV(std::string filename) { 
		_constructTableFromCSV(std::string(filename));
	}
	void constructTableFromCSV(char *filename) {
		if (not filename) throw NullPointerException("FileName");
		_constructTableFromCSV(std::string(filename));
	}

	void _constructTableFromCSV(std::string) { 
		// See Below (Matrix read from CSV)
	};


	~ShellTable(){
		for (int i = 0; i < this->num_rows; ++i) {
			delete this->row_data[i]; // Delete objects that row points to
		}
		delete[] this->row_data;
		delete[] this->col_data;
	}

};

static size_t csvRowCount(const char *file_name) {
	FILE *fptr = fopen(file_name, "r");
	if (fptr == nullptr) throw FileNotFound();

	char c;
	std::size_t count = 1; // Assumes #rows >= 1
	while ( ((c = fgetc (fptr))!= EOF) ) {
		if (c == '\n') count++;
	}

	if ( ferror (fptr) ) throw FileReadError();
	fclose(fptr);

	return count;
}


static size_t csvColumnCount(const char *file_name) {
	FILE *fptr = fopen(file_name, "r");
	if (fptr == nullptr) throw FileNotFound();

	char c;
	std::size_t count = 1; // Assumes at least one column (non empty file). 
	while ( (c = fgetc (fptr)) != EOF ) {
		if (c == ',') count++;
		else if (c == '\n') break;
	}

	if ( ferror (fptr) ) throw FileReadError();
	fclose(fptr);

	return count;
}



void readfromCSV(const char *file_name) {

	this->num_rows = csvRowCount(file_name);
	this->num_cols = csvColumnCount(file_name);
	this->allocateData();


	FILE *fp = fopen(file_name, "r");
	if (fp == nullptr) throw FileNotFound();

	std::size_t buff_size = (this->num_cols * sizeof(double) + 1) * TYPE_SIZE;
	for (std::size_t row = 0; row < this->num_rows; ++row) {
		char *row_data = new char[buff_size];
		if (not fgets(row_data, buff_size, fp)) throw InvalidRead();

		char *token;
		token = std::strtok(row_data, SEP);
		for (std::size_t col = 0; col < this->num_cols; ++col) {
			this->data[row]->set(col, ATOT(token));
			token = std::strtok(nullptr, SEP);
		}
		delete[] row_data;
	}

	fclose(fp);
}
