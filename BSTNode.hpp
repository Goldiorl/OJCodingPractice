/**
 * A binary tree node implemtation for CSE 100
 * P1 CSE 100 2012
 * Author: Ian Foster: idfoster and Dan Neumann: daneuman
 */

#ifndef BSTNODE_HPP
#define BSTNODE_HPP
#include <iostream>
#include <iomanip>
#include <stdio.h>

template<typename Data>
class BSTNode {

public:

  /** Constructor.  Initialize a BSTNode with the given Data item,
   *  no parent, and no children.
   */
  BSTNode(const Data & d) : data(d) {
    left = right = parent = 0;
  }

  BSTNode<Data>* left;
  BSTNode<Data>* right;
  BSTNode<Data>* parent;
  Data const data;   // the const Data in this node.

  /** Return the successor of this BSTNode in a BST, or 0 if none.
   ** PRECONDITION: this BSTNode is a node in a BST.
   ** POSTCONDITION:  the BST is unchanged.
   ** RETURNS: the BSTNode that is the successor of this BSTNode,
   ** or 0 if there is none.
   */
  BSTNode<Data>* successor() {
    BSTNode<Data>* current = this;
    
    /* first check to see if the successor is in the right child */
    if (this->right != NULL)
    {
      //RM printf("Right node exists and is %d, so setting to current.\n",current->right->data);
      // move right 1
      current = current->right;
      // then move left as far as you can
      while (current->left != NULL )
      {
      //RM printf("Left node  exists and is %d, so setting to current.\n",current->left->data);
        current = current->left;
      }
      return current;
    }
    /* alternativly the next node could be in a parent */
    BSTNode<Data>* parent = this->parent;
    // look for a parent that matches
    while (current != NULL && parent != NULL && parent->right == current )
    {
      //RM printf("Parent exists and is %d, current is the right node of it and is %d\n",parent->data,current->data);
      current = parent;
      parent = current->parent;
      //RM printf("Setting current to %d, and parent to the new current's parent %d\n",current->data,parent->data);
    }
    return parent;
  }

}; 

/** Overload operator<< to print a BSTNode's fields to an ostream. */
template <typename Data>
std::ostream & operator<<(std::ostream& stm, const BSTNode<Data> & n) {
  stm << '[';
  stm << std::setw(10) << &n;                 // address of the BSTNode
  stm << "; p:" << std::setw(10) << n.parent; // address of its parent
  stm << "; l:" << std::setw(10) << n.left;   // address of its left child
  stm << "; r:" << std::setw(10) << n.right;  // address of its right child
  stm << "; d:" << n.data;                    // its data field
  stm << ']';
  return stm;
}

#endif // BSTNODE_HPP
