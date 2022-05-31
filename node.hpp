#include <iostream>
#include <vector>
#include <string>
class node{
    private:
        std::string _name;
        std::vector<node*> _children;
    public:
        node(std::string name);
        ~node();

        void AddChild(node* child);
        
        std::string GetName() const;
        std::vector<node*> GetChildren() const;
        node* GetChildAt(unsigned int i) const;
        unsigned int size();

        void ChangeName(std::string name);
        friend std::ostream& operator<<(std::ostream& os, node* n);
        friend std::ostream& operator<<(std::ostream& os, node& n);
};