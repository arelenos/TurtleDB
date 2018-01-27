#ifndef _NODE_H
#define _NODE_H

template<typename ObjectType>
class Node {
	TurtleRow *parent_row;
	ObjectType data;
	public:
	Node(size_t size, TurtleRow *p);
};

#endif
