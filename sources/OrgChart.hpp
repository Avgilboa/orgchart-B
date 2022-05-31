#include "Node.hpp"
namespace ariel{
    class OrgChart{
        private:
            Node _root;
            std::vector<std::string> _orderLevel;
            std::vector<std::string> _orderReverse;
            std::vector<std::string> _orderPreorder;
        public: 
            OrgChart();
            OrgChart &add_root(std::string const& name);
            OrgChart& add_sub(std::string const& parent, std::string const& child);

            std::string* begin_level_order();
            std::string* end_level_order();

            std::string* begin_reverse_order();
            std::string* reverse_order();

            std::string* begin_preorder();
            std::string* end_preorder();

            std::string* begin();
            std::string* end();

            static void CheckIlligal(std::string const& name);
            Node* FindNode(std::string const& name);

            friend std::ostream& operator<<(std::ostream&os, OrgChart& other);

            void InsertLevelOrder();
            void InsertReverseOrder();
            void InsertPreOrder(Node& node);

    };
}