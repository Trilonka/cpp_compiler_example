#ifndef _NODE

#define _NODE

#include <vector>
#include <iostream>
#include <string>
#include "enum/NodeTypes.hpp"

//узел дерева парсера
class Node
{
public:
    std::string value;
    NodeType kind;
    std::vector<Node> operators;

    Node(NodeType Kind = NodeType::EMPTY, std::string val = "");

    void print();

    ~Node();

};

#endif