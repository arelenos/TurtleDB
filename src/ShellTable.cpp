#include "ShellTable.h"
#include "MetaRow.h"
#include "String.h"

#include <iostream>

typedef std::vector<std::string> VectorStr;


TurtleTable::TurtleTable(VectorStr datatypes, VectorStr labels) {
	if (datatypes.size() != labels.size()) throw InvalidTableInput();
	num_cols = datatypes.size();
	
}



TurtleTable::~TurtleTable() {

	for (std::size_t i = 0; i < this->num_rows; ++i) {
		delete this->row_data[i]; // Delete objects that row points to
	}
	delete[] this->row_data;
	delete[] this->col_data;
}


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



// void readfromCSV(const char *file_name) {

// 	this->num_rows = csvRowCount(file_name);
// 	this->num_cols = csvColumnCount(file_name);
// 	this->allocateData();


// 	FILE *fp = fopen(file_name, "r");
// 	if (! fp) throw FileNotFound();

// 	std::size_t buff_size = (this->num_cols * sizeof(double) + 1) * TYPE_SIZE;
// 	for (std::size_t row = 0; row < this->num_rows; ++row) {
// 		char *row_data = new char[buff_size];
// 		if (not fgets(row_data, buff_size, fp)) throw InvalidRead();

// 		char *token;
// 		token = std::strtok(row_data, SEP);
// 		for (std::size_t col = 0; col < this->num_cols; ++col) {
// 			this->data[row]->set(col, ATOT(token));
// 			token = std::strtok(nullptr, SEP);
// 		}
// 		delete[] row_data;
// 	}

// 	fclose(fp);
// }

// Incomplete
// void TurtleTable::allocateData(std::size_t num_rows, std::size_t num_cols, MetaRow metarowdata) {


// 	// What do we want to do in this case
// 	if (num_rows == 0 or num_cols == 0) {
// 		return;
// 	} else if (num_rows > MAX_ROW_SIZE or num_cols > MAX_COL_SIZE) {
// 		throw AllocationTooLargeException();
// 	}

// 	this->num_rows = num_rows;
// 	this->num_cols = num_cols;

// 	this->row_data = new TurtleRowPtr[this->num_rows];
// 	for (std::size_t row = 0; row < this->num_rows; ++row) {
// 		this->data.emplace_back(new TurtleRow(num_cols));
// 	}
// }

// void TurtleTable::constructTableFromCSV(const char *file_name) {

// 	this->num_rows = csvRowCount(file_name);
// 	this->num_cols = csvColumnCount(file_name);

// 	MetaRow rowinfo; // How to obtain from CSV? guess column types?

// 	this->allocateData(this->num_rows, this->num_cols, rowinfo);


// 	FILE *fp = fopen(file_name, "r");
// 	if (! fp) throw FileNotFound();
// 	std::map<TurtleTypes, void (*)()> method_map = { 
// 		{TurtleTypes::Integer_TT, Object::NewInteger},
// 		{TurtleTypes::String_TT, Object::NewString},
// 		{TurtleTypes::Char_TT, Object::NewChar},
// 		{TurtleTypes::Double_TT, Object::NewDouble}}
// 	}
// 	std::size_t buff_size = (this->num_cols * sizeof(double) + 1) * TYPE_SIZE;
// 	for (std::size_t row = 0; row < this->num_rows; ++row) {
// 		char *row_data = new char[buff_size];
// 		if (not fgets(row_data, buff_size, fp)) throw InvalidRead();

// 		char *token;
// 		token = std::strtok(row_data, SEP);
// 		for (std::size_t col = 0; col < this->num_cols; ++col) {
// 			this->data[row]->set(col, ATOT(token));
// 			token = std::strtok(nullptr, SEP);
// 		}
// 		delete[] row_data;
// 	}

// 	fclose(fp);
// }

