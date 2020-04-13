#include "tree.h"

Tree::Tree(char letter)
    : letter{letter}, left{nullptr}, right{nullptr} {}

Tree::~Tree()
{
    delete left;
    delete right;
}

Tree * Tree::GetLeft() {return left;}

Tree * Tree::GetRight() {return right;}

void Tree::Node(char left_letter, char right_letter)
{
    if(left_letter != '\0')
        left = new Tree(left_letter);
    if(right_letter != '\0')
        right = new Tree(left_letter);
}
