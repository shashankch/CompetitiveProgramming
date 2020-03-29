#include <bits/stdc++.h>
using namespace std;

bool helper2(unordered_map<int, vector<int> *> &adjlist, int sv, int ev, unordered_map<int, bool> &visit)
{

    vector<int> *slist = adjlist[sv];

    for (int i = 0; i < slist->size(); i++)
    {

        if (slist->at(i) == ev)
        {
            return true;
        }
    }

    queue<int> vertices;
    visit[sv] = true;
    vertices.push(sv);

    while (!vertices.empty())
    {

        int front = vertices.front();
        vertices.pop();
        vector<int> *fr = adjlist[front];
        for (int i = 0; i < fr->size(); i++)
        {

            if (visit[fr->at(i)] == false)
            {

                if (fr->at(i) == ev)
                {
                    return true;
                }

                else
                {
                    visit[fr->at(i)] = true;
                    vertices.push(fr->at(i));
                }
            }
        }
    }

    return false;
}

bool helper(unordered_map<int, vector<int> *> &adjlist, int sv, int ev, unordered_map<int, bool> &visit)
{

    vector<int> *slist = adjlist[sv];

    for (int i = 0; i < slist->size(); i++)
    {

        if (slist->at(i) == ev)
        {
            return true;
        }
    }

    visit[sv] = true;

    for (int i = 0; i < slist->size(); i++)
    {

        if (visit[slist->at(i)] == false)
        {

            bool res = helper(adjlist, slist->at(i), ev, visit);
            if (res)
            {
                return true;
            }
        }
    }

    return false;
}

bool haspath(unordered_map<int, vector<int> *> &adjlist, int sv, int ev)
{

    unordered_map<int, bool> visit;
    return helper2(adjlist, sv, ev, visit);
}

int main()
{

    int n, e;
    cin >> n >> e;

    unordered_map<int, vector<int> *> adjlist;

    for (int i = 0; i < n; i++)
    {

        vector<int> *v = new vector<int>;
        adjlist[i] = v;
    }
    int count = e;
    while (e--)
    {

        int source, dest;
        cin >> source >> dest;
        adjlist[source]->push_back(dest);
        adjlist[dest]->push_back(source);
    }

    int sv, ev;
    cin >> sv >> ev;

    if (haspath(adjlist, sv, ev))
    {

        cout << "true" << endl;
    }
    else
    {
        cout << "false" << endl;
    }

    return 0;
}