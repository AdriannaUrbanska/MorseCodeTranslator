#pragma once
#include <iostream>
#include <memory>

class Tree
{
    char letter;
    Tree * left;
    Tree * right;

public:
    Tree(char letter);

    ~Tree();

    Tree * GetLeft();

    Tree * GetRight();

    void Node(char left_letter, char right_letter);
};
