#include <iostream>
#include <string>
#include <vector>
#include <list>
#include <utility>

class Node
{
    int m_value { 0 };

    std::vector<Node*> m_children;

    public:
        // constructor
        Node (int value=0) : m_value(value) { }
    
        void add_child (Node& node)
        {
            m_children.push_back(&node);
        }

        int value () const
        {
            return m_value;
        }

        std::vector<Node*>& children()
        {
            return m_children;
        }
};

void bft (Node* root)
{
    std::list<std::pair<Node*,int>> q;

    if (!root)
        return;

    q.push_back(std::make_pair(root,0));

    int prev_lvl = 0;

    while (!q.empty())
    {
        auto nn = q.front();
        
        Node* n = q.front().first;
        int level = q.front().second;

        q.pop_front();
        
        if (level != prev_lvl)
            std::cout << std::endl;

        prev_lvl = level;

        std::cout << n->value() << " ";
   
        for (auto a = n->children().begin(); a != n->children().end(); a++)
        {
            q.push_back(std::make_pair(*a,level+1));
        }
    }
}


int main (int argc, const char* argv[])
{
    Node root(0);

    Node c1(1), c2(2), c3(3);

    root.add_child (c1); 
    root.add_child (c2); 
    root.add_child (c3); 

    Node c11(11), c12(12), c13(13);
    c1.add_child (c11);
    c1.add_child (c12);
    c1.add_child (c13);

    Node c21(21), c22(22), c23(23);
    c2.add_child (c21);
    c2.add_child (c22);
    c2.add_child (c23);

    Node c31(31), c32(32), c33(33);
    c3.add_child (c31);
    c3.add_child (c32);
    c3.add_child (c33);

    bft (&root);

    return 0;
}

