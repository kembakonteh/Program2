//
//  BinTree.hpp
//  Program2
//
//  Created by Kemba Konteh on 1/27/20.
//  Copyright © 2020 Kemba Konteh. All rights reserved.
//

#ifndef bintree_h
#define bintree_h

#include <stdio.h>
#include "NodeData.h"
#include <string>
#include <iostream>
#include <fstream>
using namespace std;

class BinTree
{
    // Output operator (overload) to help print the binary search tree
    friend ostream& operator<<( ostream &output, const BinTree &b );

public:
    // Default constructor
    BinTree();

    // copy constructor
    BinTree(const BinTree &b);

    // destructor, calls makeEmpty
    ~BinTree();

    // true if tree is empty, otherwise false
    bool isEmpty() const;

    // make the tree empty so isEmpty returns true
    void makeEmpty();

    // assignment operator for two trees
    BinTree& operator=(const BinTree &b);

    // Checks for equality of tree
    bool operator==(const BinTree &b) const;

    // checks for inequality of tree
    bool operator!=(const BinTree &b) const;

    // Inserts new value into the tree
    bool insert(NodeData* value);

    // retrieves a specific value from the tree
    bool retrieve(const NodeData &data,NodeData* &value) const;

    // Display the side view of the tree
    void displaySideways() const;

    // Get height of a specific node.
    int getHeight (const NodeData & value) const;

    //function to fill an array of Nodedata* by using an inorder traversal of the tree.
    void bstreeToArray(NodeData* nodes[]);

    // Converts a sorted array to balanced tree.
    void arrayToBSTree(NodeData* arr[]);

    // Function to print the tree in inorder form.
    //void inorderHelper() const; // void inorderHelper(ostream& output, const Node *start) const;

private:
    struct Node {
        // pointer to data object
        NodeData* data;

        // left subtree pointer
        Node* left;

        // right subtree pointer
        Node* right;
    };

    // root of the tree
    Node* root;
    // Function to print the tree in inorder form.
    void inorderHelper(ostream& output, const Node *start) const;

    // Helper method to copy the tree recursively
    void copyNode(Node *src, Node * &dest);

    // Deallocate the memory starting from a tree node.
    void freeTree(Node *start);

    // Helper function to compare if 2 subtrees are same in values
    // and structure.
    bool compareSubtree(const Node *a, const Node *b) const;

    // Helper function to search the data in the tree, this function returns
    // the value of the max tree depth
    int heightHelper(const NodeData &search, Node* start, int &foundLevel) const;

    // Helper function to fill the array from tree
    void bstreeToArrayHelper(int &index, NodeData* nodes[], Node* start);

    // Create balanced tree from the given array
    // Helper function only considers the data between a limit
    void arrayToBSTreeHelper(Node* &dest, NodeData* nodes[] , int left, int right);

    // Helper function to print Sideways view
    void sideways(Node*, int) const;

    //int numElement;



};
//#endif

#endif /* BinTree_hpp */
