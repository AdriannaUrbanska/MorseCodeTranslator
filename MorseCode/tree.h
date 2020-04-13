#pragma once

class Tree
{
    char letter;    /** Value of the node. */
    Tree * left;    /** Left child node. */
    Tree * right;   /** Right child node. */

public:

    /**
    *   Constructor which asigns parametr to letter value
    *   and sets left and right child node to nullptr.
    */
    Tree(char letter);

    /**
    *   Destructor which frees memory after left and right child nodes.
    */
    ~Tree();

    /**
    *   Method which sets values of left and right child nodes.
    */
    void Node(char left_letter, char right_letter);

    /**
    *   Method which returns pointer to the left child node.
    */
    Tree * GetLeft();

    /**
    *   Method which returns pointer to the right child node.
    */
    Tree * GetRight();

    /**
    *   Method which returns value of the node.
    */
    char GetLetter();
};
