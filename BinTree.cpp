//
//  BinTree.cpp
//  Program2
//
//  Created by Kemba Konteh on 1/27/20.
//  Copyright © 2020 Kemba Konteh. All rights reserved.
//
#include "BinTree.h"
using namespace std;

/*
 * class to represent Binary Tree
*/

//------------------------------------------------ Default Constructor ------------------------------------------------
// default constructor creates and empty tree with root initialized to NULL.
//---------------------------------------------------------------------------------------------------------------------
BinTree::BinTree() {
    root = NULL;
}

//----------------------------------------------------- Copy Node -----------------------------------------------------
// Helper method to copy Node. The copy constructor and the assignment operator make use of this method.
// @param src Node deep copying from
// @param dest Node deep copying to
//---------------------------------------------------------------------------------------------------------------------
void BinTree::copyNode(Node *src, Node* &dest)
{
    if(src != NULL)
    {
        dest = new Node;
        dest->data = new NodeData(*(src->data));
        copyNode(src->left, dest->left);
        copyNode(src->right, dest->right);
//        delete dest;
//        dest = NULL;
    } else
    {
        dest = NULL;
    }
}

//----------------------------------------------- Copy Constructor ---------------------------------------------------
// calls the copyNode function. Takes a reference to an existing node of a tree and copies all Nodes within that tree
// to created tree (deep) copy
// // @param other tree object copying from
//--------------------------------------------------------------------------------------------------------------------
BinTree::BinTree(const BinTree& other)
{
    copyNode(other.root, root);

}

//------------------------------------------ Destructor ---------------------------------------------------------------
// Destructor calls the makeEmpty method to clean up memory allocated for binary trees.
//---------------------------------------------------------------------------------------------------------------------
BinTree::~BinTree()
{
    makeEmpty();
}

//----------------------------------------------- isEmpty -------------------------------------------------------------
// check if tree is empty or not.
// @return true if root equals NULL, false otherwise
//---------------------------------------------------------------------------------------------------------------------
bool BinTree::isEmpty() const
{
    return (root == NULL);
}

//-------------------------------------------------- freeTree ---------------------------------------------------------
// Helper to free tree. It recursively frees the memory on the nodes of tree. By calling this method, you free or destroy all
// nodes within a given tree.
//@param start node utilized
//----------------------------------------------------------------------------------------------------------------------
void BinTree::freeTree(Node *start)
{
    if(start != NULL)
    {
        freeTree(start->left);
        freeTree(start->right);
        delete start->data;
        delete start;
    }
}

//----------------------------------------------- makeEmpty -----------------------------------------------------------
// Frees the memory for tree. Makes use of freeTree method to make the tree empty.
//---------------------------------------------------------------------------------------------------------------------
void BinTree::makeEmpty()
{
    freeTree(root);
    root = NULL;
}



//---------------------------------------------- operator = ------------------------------------------------------------
// Make LHS the same as RHS by a Deep copy of RHS
// @param rhs tree copying from
//---------------------------------------------------------------------------------------------------------------------
BinTree& BinTree::operator=(const BinTree& rhs)
{

    // Check if we are not trying to copy the same tree.
    if (this != &rhs)
    {

        freeTree(root);
        root = NULL;

        // copy data on current node.
        copyNode(rhs.root, root);
    }
    return *this;
}

//----------------------------------------------- CompareSubtree ------------------------------------------------------
// Helper function to compare if 2 subtrees are same in value and structure. It is a recursive method called by the
// equality (==) operator to check whether two nodes are the same or equal.
// // @param a node within the tree on the left side of comparison
// // @param b a node within the tree on the right side of comparison
// // @return true if Node data contents are the same, false otherwise
//----------------------------------------------------------------------------------------------------------------------
bool BinTree::compareSubtree(const Node *a, const Node *b) const
{
    if(a == NULL && b == NULL)
    {
        return true;
    }
    if(a == NULL || b == NULL || (*(a->data) != *(b->data)))
    {
        return false;
    }
    return compareSubtree(a->left, b->left) && compareSubtree(a->right, b->right);
}


//---------------------------------------------- operator== -----------------------------------------------------------
//tests whether two trees are exactly the same by comparing their NodeData on each move within a traversal of both trees
// @param rhs the tree object that is compared with the this object
// @return true if both trees are the same, false otherwise.
//---------------------------------------------------------------------------------------------------------------------
bool BinTree::operator==(const BinTree& rhs) const
{
    if(this == &rhs)
    {
        return true;
    }

    return compareSubtree(root, rhs.root);
}

//----------------------------------------------- != operator --------------------------------------------------------
// checks for inequality of tree.
//@param rhs tree compared to the this object
// @return true if both trees are not the same, false otherwise
//----------------------------------------------------------------------------------------------------------------------
bool BinTree::operator!=(const BinTree& rhs) const
{
    if(this == &rhs)
    {
        return false;
    }
    return !(*this == rhs);
}

//----------------------------------------------- inOrderHelper -------------------------------------------------------
// Function to print the tree in an inorder form.
//@param output the output to be printed out.
//@param start the node passed into the function
//----------------------------------------------------------------------------------------------------------------------
void BinTree::inorderHelper(ostream& output, const Node *start) const
{
    if(start != NULL)
    {
        inorderHelper(output, start->left);
        output << *(start->data) << " ";
        inorderHelper(output, start->right);
    }
}


//------------------------------------------------- operator<< --------------------------------------------------------
// Output operator (overload) to help print the binary search tree
// @param output output stream
// @param b the tree that provides the output data
//---------------------------------------------------------------------------------------------------------------------
ostream& operator<<(ostream& output, const BinTree& b)
{
    b.inorderHelper(output, b.root);
    output << std::endl;
    return output;
}

//---------------------------------------------------- Insert ----------------------------------------------------------
// inserts a value in the tree, in order. With data ptr pointed to d (the new data item). Returns whether insertion of
// node was successful or not.
// @param newDataItem NodeData item inserted into the tree
//---------------------------------------------------------------------------------------------------------------------
bool BinTree::insert(NodeData *d)
{
    // create a new node.
    Node *newNode = new Node;
    newNode->data = d;
    newNode->left = NULL;
    newNode->right = NULL;

    // if this is the first node.
    if(root == NULL)
    {
        root = newNode;
        return true;
    }

    Node *start = root;
    while(start != NULL)
    {

        // if data value matches
        if(*(start->data) == *d)
        {
            delete newNode;
            return false;

            // we need to go to left subtree
        } else if(*(start->data) > *d)
        {
            if(start->left == NULL)
            {
                start->left = newNode;
                return true;
            } else {
                start = start->left;
            }

            // we need to go to right subtree
        } else
        {
            if(start->right == NULL)
            {
                start->right = newNode;
                return true;
            } else
            {
                start = start->right;
            }
        }
    }

    return true;
}


//--------------------------------------------------------- Retrieve --------------------------------------------------
// retrieves a specific value from the tree. Returns true if searched value is found in the Binary Search Tree and sets
// ret pointing to the location it was found at.
// @param search NodeData Item searching for
// @param ret If searched value is found
// //	@return true if returnData != NULL, false if NULL
bool BinTree::retrieve(const NodeData &search, NodeData* &ret) const
{

    Node *start = root;

    // check in loop for the node, which may contain the value
    while(start != NULL)
    {
        if(*(start->data) == search)
        {
            ret = start->data;
            return true;
        } else if(*(start->data) > search)
        {
            start = start->left;
        } else
        {
            start = start->right;
        }
    }

    return false;
}

//---------------------------------------------------- HeightHelper ---------------------------------------------------
// Helper function to search the data in the tree, this function returns
// the value of the max tree depth.
// @param search  node helper method located at
// @param start value at which the method started at
// @return foundLevel max height of nodes inside of the tree, 0 if not found
//---------------------------------------------------------------------------------------------------------------------
int BinTree::heightHelper(const NodeData &search, Node* start, int &foundLevel) const
{
    if(start == NULL)
    {
        return 0;
    }

    // get depth of left and right subtree.
    int leftHeight = heightHelper(search, start->left, foundLevel);
    int rightHeight = heightHelper(search, start->right, foundLevel);

    // Depth of this node.
    int h = 1 + (leftHeight > rightHeight ? leftHeight : rightHeight);

    // if data matches, then update the foundLevel
    if(*(start->data) == search)
    {
        foundLevel = h;
    }

    // return max of height from here.
    return h;
}

//----------------------------------------------------- GetHeight -----------------------------------------------------
// Function finds the height of a given value in the tree. Makes use of the helper method to return the max height
//@param search item finding the depth for
//	@return number represented by how deep the Node containing search is, otherwise return 0 if search not found.
//---------------------------------------------------------------------------------------------------------------------
int BinTree::getHeight (const NodeData &search) const
{
    int foundLevel = 0;

    // use helper method to find depth of node with value
    heightHelper(search, root, foundLevel);
    return foundLevel;
}

//------------------------------------------ bstreeToArrayHelper ------------------------------------------------------
// helper function to convert the tree to array recursively in an inorder form.
// @param index the index of insertion into the BST NodeData array
// @param start the starting Node location
// @param bnodes the array that holds the BST NodeData after transfering
//---------------------------------------------------------------------------------------------------------------------
void BinTree::bstreeToArrayHelper(int &index, NodeData* nodes[], Node* start)
{
    if(start != NULL)
    {

        bstreeToArrayHelper(index, nodes, start->left);
        nodes[index++] = new NodeData(*(start->data));
//        start->data = NULL;	//detach data
        bstreeToArrayHelper(index, nodes, start->right);

    }
}


//------------------------------------------------ bstreeToArray ------------------------------------------------------
//function to fill an array of Nodedata* by using an inorder traversal of the tree.
// @param nodes NodeData array that will hold the contents of the tree
//---------------------------------------------------------------------------------------------------------------------
void BinTree::bstreeToArray(NodeData* nodes[])
{
    int index = 0;
    bstreeToArrayHelper(index, nodes, root);
    this->makeEmpty(); // to leave the tree empty
}

//----------------------------------------------- arrayToBSTreeHelper -------------------------------------------------
// helper method to form the tree from the array
// We operate on the given range form left to right
//@param dest the Node to insert to
//@param nodes Array that NodeData* is pulled from
//@param left lower index of binary partition created by helper
//@param right upper index of binary partition created by helper
//---------------------------------------------------------------------------------------------------------------------
void BinTree::arrayToBSTreeHelper(Node* &dest, NodeData* nodes[], int left, int right)
{
    if(left > right)
    {
        return;
    }
    int mid = (left + right) / 2;

    // create new node for mid value

    dest = new Node;
    dest->data = nodes[mid];
    dest->left = NULL;
    dest->right = NULL;

//    delete dest;
//    dest = NULL;


    // check if left subtree needed
    if(mid != left)
    {
        arrayToBSTreeHelper(dest->left, nodes, left, mid-1);
    }

    // check if right subtree is needed
    if(mid != right)
    {
        arrayToBSTreeHelper(dest->right, nodes, mid+1, right);
    }
}

//---------------------------------------------------- arrayToBSTree --------------------------------------------------
// Converts a sorted array to balanced tree. Function to builds a balanced BinTree from a sorted array of NodeData*
// leaving the array filled with NULLs. The root (recursively) is at (low+high)/2 where low is the lowest subscript
// of the array range and high is the highest.
// @param nodes sorted array to pull NodeData* information from
//---------------------------------------------------------------------------------------------------------------------
void BinTree::arrayToBSTree(NodeData* nodes[])
{
    // find number of nodes in the tree
    int size = 0;
    for(int i = 0; i < 100; i++)
    {
        if(nodes[i] == NULL)
        {
            break;
        }
        size++;
    }

    // free old tree
    freeTree(root);
    root = NULL;

    // fill new tree
    arrayToBSTreeHelper(root, nodes, 0, size-1);

}

//-------------------------------------------------- displaySideways --------------------------------------------------
// Displays a binary tree as though you are viewing it from the side;
// hard coded displaying to standard output.
// Preconditions: NONE
// Postconditions: BinTree remains unchanged.
//---------------------------------------------------------------------------------------------------------------------
void BinTree::displaySideways() const
{
    sideways(root, 0);
}

//---------------------------------------------------- Sideways --------------------------------------------------------
// Helper method for displaySideways
// Preconditions: NONE
// Postconditions: BinTree remains unchanged.
//---------------------------------------------------------------------------------------------------------------------
void BinTree::sideways(Node* current, int level) const
{
    if (current != NULL)
    {
        level++;
        sideways(current->right, level);

        // indent for readability, 4 spaces per depth level
        for (int i = level; i >= 0; i--)
        {
            cout << "    ";
        }

        cout << *(current->data) << endl;        // display information of object
        sideways(current->left, level);
    }
}

