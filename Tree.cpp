#include "Tree.hpp"
using std::string;
using std::vector;
Tree::Tree(){
    it = non;
    this->_root = new node("");
};
Tree::~Tree(){
    delete(_root);
}

node* Tree::GetRoot(){
    return this->_root;
}
vector<node*> Tree::GetOrder(){
    return this->_order;
}
Tree::iter Tree::IsIter(){
    return this->it;
}
Tree& Tree::add_root(string name){
    if(name.size()==0){
        throw std::runtime_error("the name is empty");
    }
    if(this->_root->GetName().size()!=0){
        this->_root->ChangeName(name);
    }
    if(this->_root->GetName()==""){
        this->_root->ChangeName(name);
    }
    return *this;
}

Tree& Tree::add_sub(string parent, string child){
    
    node* p =FindNode(parent);
    node* c =FindNode(child);
    if(p==nullptr || c!=nullptr || child.size()==0 || parent.size()==0){
        throw std::runtime_error("the names are illigeal");
    }
    p->AddChild(new node(child));
    return *this;
}

void Tree::change_iter(Tree::iter situation){
    this->it = situation;
}

node* Tree::FindNode(string name){
    CheckIllegalNames(name);
    this->_order = this->bfs();
    for(node* it : this->_order){
        if(it->GetName() == name){
            return it;
        }
    }
    return nullptr;
}
void Tree::CheckIllegalNames(string name){
    string temp;
    for(size_t i=0; i<name.size();i++){temp.push_back(' ');}
    if(name == "" || name =="\n" || name ==temp){
        throw std::runtime_error ("the string is illigeal");}
}

vector<node*> Tree::bfs(){
    unsigned int index =0;
    vector<node*> NewOreder;
    NewOreder.push_back(this->_root);
    while(index+1 <=NewOreder.size()){
        for(node* it : NewOreder.at(index)->GetChildren()){
            NewOreder.push_back(it);
        }
        index++;
    }
    return NewOreder;
}

vector<node*> Tree::reverse(){
    unsigned int index =0;
    vector<node*> NewOreder;
    NewOreder.push_back(this->_root);
    while(index+1 <=NewOreder.size()){
        vector<node*> temp;
        for(node* it : NewOreder.at(index)->GetChildren()){
            temp.push_back(it);
        }
        for(unsigned int i=0; i<temp.size();i++){
            NewOreder.push_back(temp.at(temp.size()-1-i));
        }
        index++;
    }
    vector<node*> NewOrede(NewOreder.rbegin(), NewOreder.rend());
    return NewOrede;
}
