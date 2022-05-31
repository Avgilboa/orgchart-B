#include <iostream>
#include <vector>
#include <string>
class Node{
    public:
        std::string _name;
        std::vector<Node> childrens;

        Node(std::string name);
        Node();
};