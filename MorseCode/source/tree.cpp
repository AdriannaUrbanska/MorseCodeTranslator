#include "tree.h"

Tree::Tree(char letter)
    : letter{letter}, left{nullptr}, right{nullptr} {}

Tree::~Tree()
{
    if(left != nullptr)
        delete left;
    if(right != nullptr)
        delete right;
}

void Tree::Node(char left_letter, char right_letter)
{
    if(left_letter != '\0')
        left = new Tree(left_letter);
    if(right_letter != '\0')
        right = new Tree(right_letter);
}

Tree * Tree::GetLeft() { return left; }

Tree * Tree::GetRight() { return right; }

char Tree::GetLetter() { return letter; }
