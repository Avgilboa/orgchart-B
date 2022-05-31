#include "node.hpp"
class Tree{
    public:
        enum iter {non,bf,rvrse,prordr};
    private:
        node* _root;
        std::vector<node*> _order;
        iter it;
    public:
        Tree();
        ~Tree();

        node* GetRoot();
        std::vector<node*> GetOrder();
        iter IsIter();


        Tree& add_root(std::string name);
        Tree& add_sub(std::string parent , std::string child);
        void change_iter(iter situation);

        node* FindNode(std::string name);
        void CheckIllegalNames(std::string name);

        std::vector<node*> bfs();
        std::vector<node*> reverse();
        //std::vector<node*> PreOrder();


};