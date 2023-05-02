#ifndef _NODE

#define _NODE

//#include "/Users/1/Desktop/Вуз/Programm progect/GitHub/cpp_compiler_example/Includes.cpp"
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
        std::cout << int(kind) << ' ' << value << "\n\n";
    }

    ~Node() {}

};

#endif