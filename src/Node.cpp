#include "Node.hpp"


Node::Node(NodeType Kind, std::string val) {
    kind = Kind;
    value = val;
}

void Node::print() {
    std::cout << int(kind) << ' ' << value << "\n\n";
}

Node::~Node() {}
