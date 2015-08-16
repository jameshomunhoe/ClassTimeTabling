#include <stdio.h>
#include "Rotations.h"
#include "Node.h"

/**
*	Important notes / information
*
*	exampleFunction(Node **nodePtr)
*	(**nodePtr).data //This is same
*	(*nodePtr)->data //with this
*
*	change root method
*	*nodePtr=&node5;
*/


/**
*	Name: 			leftRotate
*	Input: 			Node **nodePtr (root node)
*	Output:			NULL
*	Description:	To rotate the tree to left, right child of root will be used as pivot
*/
void leftRotate(Node **nodePtr){

	Node *tempRoot = *nodePtr;						//original root
	Node *tempRightLeft = tempRoot->right->left;	//original right left child
	
	*nodePtr = (*nodePtr)->right;
	(*nodePtr)->left = tempRoot;
	(*nodePtr)->left->right = tempRightLeft;

}

/**
*	Name: 			rightRotate
*	Input: 			Node **nodePtr (root node)
*	Output:			NULL
*	Description:	To rotate the tree to right, left child of root will be used as pivot
*/
void rightRotate(Node **nodePtr){
  
	Node *tempRoot = *nodePtr;						//original root
	Node *tempLeftRight = tempRoot->left->right;	//original left right child
	
	*nodePtr = (*nodePtr)->left;
	(*nodePtr)->right = tempRoot;
	(*nodePtr)->right->left = tempLeftRight;

}

/**
*	Name: 			leftRightRotate
*	Input: 			Node **nodePtr (root node)
*	Output:			NULL
*	Description:	To rotate the left child's portion to left, using left child's right child as pivot,
*					& rotate right again at root node, left child of root will be used as pivot
*/
void leftRightRotate(Node **nodePtr){
	
	leftRotate(&((*nodePtr)->left));
	rightRotate(&(*nodePtr));

}

/**
*	Name: 			rightLeftRotate
*	Input: 			Node **nodePtr (root node)
*	Output:			NULL
*	Description:	To rotate the right child's portion to right, using right child's left child as pivot,
*					& rotate left again at root node, right child of root will be used as pivot
*/
void rightLeftRotate(Node **nodePtr){

	rightRotate(&((*nodePtr)->right));
	leftRotate(&(*nodePtr));
	
}