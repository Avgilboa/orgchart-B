#include "Node.hpp"

Node::Node(std::string name){
    this->_name = std::move(name);
}

Node::Node(){
    this->_name ="";
}