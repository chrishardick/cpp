#include <iostream>
#include <string>
#include <list>
#include <vector>
#include <map>
#include <utility>
#include <sstream>

struct Node
{
    int val = 0;
    Node* left = 0;
    Node* right = 0;

    Node (int v, Node* l=0, Node* r=0) :
        val(v), left(l), right(r)
    { }
};

std::ostream& operator<<(std::ostream& os, const Node& n)
{
    os << n.val;

    return os;
}

void bft (Node* head)
{
    std::list<std::pair<Node*,int>> q;

    std::map<int,std::vector<Node*>> rows;

    if (!head)
        return;

    int row = 0;

    q.push_back(std::make_pair(head,row));
    
    rows[row].push_back(head);

    int max_col = rows[row].size();


    while (!q.empty())
    {
        Node* n = q.front().first;

        row = q.front().second;

        q.pop_front();

        if (n->left)
        {
            q.push_back(std::make_pair(n->left,row+1));
            rows[row+1].push_back(n->left);
        }

        if (n->right)
        {
            q.push_back(std::make_pair(n->right,row+1));
            rows[row+1].push_back(n->right);
        }
            
        if (rows[row+1].size() > max_col)
            max_col = rows[row+1].size();
    }


    //
    // [0] = 1,2,3
    // [1] = 4
    // [2] = 5,6,7
    //

    for (unsigned int c=0; c<max_col; c++)
    {
        std::cout << "col " << c << ": ";

        bool start = true;

        std::ostringstream oss;

        for (auto r=rows.begin(); r!=rows.end(); r++)
        {
            std::vector<Node*>& rr = r->second;

            if (c < rr.size())
            {
                if (oss.str().size())
                {
                    oss << ",";
                }
                oss << *rr[c];
            }
        }

        std::cout << oss.str() << std::endl;
    }
}


int main (int argc, const char* argv[])
{
    Node head (0);

    Node n1 (1);
    Node n2 (2);

    Node n3 (3);
    Node n4 (4);

    head.left = &n1;
    head.right = &n2;

    n1.left = &n3;
    n1.right = &n4;

    bft (&head);

    return 0;
}

