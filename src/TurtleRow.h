#ifndef _TURTLE_ROW_H
#define _TURTLE_ROW_H

class TurtleRow {
	RowNode *data;
	static MetaRow *metainfo;

	TurtleRow(size_t size, TurtleRow * tRow);
}; 
#endif
