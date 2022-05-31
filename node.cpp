#include"node.hpp"
using std::string;
using std::vector;
node::node(string name){
    this->_name = name;
}
node::~node(){
    for(auto iter: this->_children){
        delete(iter);
    }
    std::cout << "removing the node: " << this->_name << std::endl;
}

void node::AddChild(node* child){
    this->_children.push_back(child);
}

string node::GetName() const{
    return this->_name;
}

vector<node*> node::GetChildren() const{
    return this->_children;
}

node* node:: GetChildAt(unsigned int i) const{
    if(i<this->_children.size()){
    return this->_children.at(i);}
    throw std::runtime_error ("this index is out of bounds");
}

unsigned int node::size(){
    return this->_name.size();
}

std::ostream& operator<<(std::ostream& os, node* n){
    os << n->GetName();
    return os;
}

std::ostream& operator<<(std::ostream& os, node& n){
    os << n.GetName();
    return os;
}

void node::ChangeName(string name){
    this->_name = name;
}





