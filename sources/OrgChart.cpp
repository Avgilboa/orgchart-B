#include "OrgChart.hpp"
using std::string;
using std::vector;
namespace ariel{
    OrgChart::OrgChart(){
        this->_root._name = " ";
    }
    OrgChart& OrgChart::add_root(string const& name){
        CheckIlligal(name);
        this->_root._name=name;
        return *this;
    }

    OrgChart& OrgChart::add_sub(string const& __parent, string const& __child){
        CheckIlligal(this->_root._name);
        CheckIlligal(__parent);
        CheckIlligal(__child);
        Node* child = FindNode(__child);
        Node* parent = FindNode(__parent);
        if(parent!=nullptr && parent==child){
            return *this;
        }
        if(parent!= nullptr)
        {
            parent->childrens.push_back(Node(__child));
            return *this;
        }

        throw std::runtime_error("employer doesn't exist");
    }



    string* OrgChart::begin_level_order(){
        CheckIlligal(this->_root._name);
        InsertLevelOrder();
        return &this->_orderLevel[0];
    }
    string* OrgChart::end_level_order(){
        CheckIlligal(this->_root._name);
        return &this->_orderLevel[this->_orderLevel.size()];
    }




    string* OrgChart::begin_reverse_order(){
        CheckIlligal(this->_root._name);
        InsertReverseOrder();
        return &this->_orderReverse[0];
    }
    string* OrgChart::reverse_order(){
        CheckIlligal(this->_root._name);
        return &this->_orderReverse[this->_orderReverse.size()];
    }




    string* OrgChart::begin_preorder(){
        CheckIlligal(this->_root._name);
        this->_orderPreorder.clear();
        InsertPreOrder(this->_root);
        return &this->_orderPreorder[0];
    }

    string* OrgChart::end_preorder(){
        CheckIlligal(this->_root._name);
        return &this->_orderPreorder[this->_orderPreorder.size()];
    }



    string* OrgChart::begin(){
        return this->begin_level_order();
    }
    string* OrgChart::end(){
        return this->end_level_order();
    }

    void OrgChart::CheckIlligal(string const& name){
        string temp;
        for(unsigned int i=0; i<name.size();i++){
            temp.push_back(' ');
        }

        if(name == temp || name.find('\n') != string::npos ||name.find('\t') != string::npos || name.find('\r') != string::npos){
            throw std::invalid_argument("this is illeagal name");
        }

    }

    Node* OrgChart::FindNode(string const& name){
        this->InsertLevelOrder();
        unsigned int index =0;
        vector<Node*> NewOreder;
        NewOreder.push_back(&this->_root);
        if(this->_root._name==name){ return &this->_root;}
            while(index+1 <=NewOreder.size()){

                    for(auto it= NewOreder.at(index)->childrens.begin();
                        it!= NewOreder.at(index)->childrens.end();it++){
                            if(it->_name == name){
                                return &(*it);}
                        NewOreder.push_back(&(*it));
                    }
                index++;
            }
        return nullptr;
    }

    void OrgChart::InsertPreOrder(Node& node){
        this->_orderPreorder.push_back(node._name);
        for(unsigned int i=0; i<node.childrens.size();i++){
            InsertPreOrder(node.childrens.at(i));
        }
    }

    void OrgChart::InsertReverseOrder(){
        this->_orderReverse.clear();
        unsigned int index =0;
        vector<Node*> NewOreder;
        NewOreder.push_back(&this->_root);
        while(index+1 <=NewOreder.size()){
            vector<Node*> temp;
            for(auto it= NewOreder.at(index)->childrens.begin();
                it!= NewOreder.at(index)->childrens.end();it++){
                    temp.push_back(&(*it));
            }
            for(unsigned int i=0; i<temp.size();i++){
                NewOreder.push_back(temp.at(temp.size()-1-i));
            }
            index++;
        }
        vector<Node*> NewOrede(NewOreder.rbegin(), NewOreder.rend());
        for(unsigned int i=0; i<NewOreder.size();i++){
            this->_orderReverse.push_back(NewOrede.at(i)->_name);
        }       
    }






    void OrgChart::InsertLevelOrder(){
        unsigned int index =0;
        vector<Node*> NewOreder;
        NewOreder.push_back(&this->_root);
            while(index+1 <=NewOreder.size()){

                    for(auto it= NewOreder.at(index)->childrens.begin();
                        it!= NewOreder.at(index)->childrens.end();it++){
                        NewOreder.push_back(&(*it));
                    }
                index++;
            }

        this->_orderLevel.clear();
        for(size_t i=0; i<NewOreder.size();i++){
            this->_orderLevel.push_back(NewOreder.at(i)->_name);}
    }

    std::ostream& operator<< (std::ostream & os, OrgChart& other){
        os<< "this gonna work!!";
        return os;
    }

}