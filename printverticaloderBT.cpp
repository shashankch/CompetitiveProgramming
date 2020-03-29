#include <iostream>
#include <queue>
#include <map>
using namespace std;

class node
{

public:
    int data;
    node *left;
    node *right;

    node(int d)
    {

        data = d;
        left = NULL;
        right = NULL;
    }
};

node *buildtree()
{

    queue<node *> q;
    int d;
    cin >> d;
    node *root = new node(d);
    q.push(root);
    while (!q.empty())
    {

        node *temp = q.front();
        q.pop();
        int l, r;
        cin >> l >> r;

        if (l != -1)
        {

            temp->left = new node(l);
            q.push(temp->left);
        }
        if (r != -1)
        {

            temp->right = new node(r);
            q.push(temp->right);
        }
    }

    return root;
}

void vop(node *root, map<int, vector<int>> &m, int d = 0)
{

    if (root == NULL)
    {
        return;
    }

    m[d].push_back(root->data);

    vop(root->left, m, d - 1);
    vop(root->right, m, d + 1);
}

int main()
{

    int level;
    cin >> level;
    node *root = NULL;
    root = buildtree();

    /// here unordered map is not taken because not sorted but map is sorted(based on key) based on bst...
    /// here using unordered map can also be done using linear search..

    map<int, vector<int>> m;
    vop(root, m);

    for (auto it = m.begin(); it != m.end(); it++)
    {

        //cout<<it->first<<"-> ";

        for (int j = 0; j < it->second.size(); j++)
        {

            cout << it->second[j] << " ";
        }
        cout << endl;
    }

    return 0;
}
