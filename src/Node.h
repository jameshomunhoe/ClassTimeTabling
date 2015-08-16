#ifndef Node_H
#define Node_H

#include "Structure.h"
#include "LinkedList.h"

typedef struct Node Node;

struct Node{
	Node *left;
	Node *right;
	char color; //Red = 'r', Black = 'b'
	TTPopulation *timeTable;
  LinkedList list;
};

#endif // Node_H
