#include "MetaRow.h"


TurtleType::MetaRow(string labels[], Objects **data1):data{data1},labels{labels}{}

TurtleType MetaRow::getType(size_t i){
	return data[i]->getType();
}

std::string MetaRow::getLabel(size_t i){
	return label[i];
}
