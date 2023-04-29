#ifndef _NODE

#define _NODE

#include <vector>
#include <iostream>
#include <string>
#include "enums/NodeTypes.cpp"

//узел дерева парсера
class Node
{
public:
    std::string value;
    NodeType kind;
    std::vector<Node> operators;

    Node(NodeType Kind = NodeType::EMPTY, std::string val = "") {
        kind = Kind;
        value = val;
    }

    void print() {
        std::cout << int(kind) << ' ' << value;
    }

    ~Node() {}

};

#endif