#include <iostream>
#include <unordered_map>
#include <string>
#include <vector>
using namespace std;
vector<int> removeDuplicates(int *a, int size)
{
    vector<int> output;
    unordered_map<int, bool> seen;
    for (int i = 0; i < size; i++)
    {
        if (seen.count(a[i]) > 0)
        {
            continue;
        }
        seen[a[i]] = true;
        output.push_back(a[i]);
    }
    return output;
}
int main()
{

    int a[] = {1, 2, 3, 3, 2, 1, 4, 3, 6, 5, 5};
    vector<int> output = removeDuplicates(a, 11);
    for (int i = 0; i < output.size(); i++)
    {
        cout << output[i] << endl;
    }
    unordered_map<string, int> ourmap;

    // insert
    pair<string, int> p("abc", 1);
    ourmap.insert(p);
    ourmap["def"] = 2;

    // find or access
    cout << ourmap["abc"] << endl;
    cout << ourmap.at("abc") << endl;

    //cout << ourmap.at("ghi") << endl;
    cout << "size : " << ourmap.size() << endl;
    cout << ourmap["ghi"] << endl;
    cout << "size : " << ourmap.size() << endl;

    // check Presense
    if (ourmap.count("ghi") > 0)
    {
        cout << "ghi is present" << endl;
    }

    // erase
    ourmap.erase("ghi");
    cout << "size : " << ourmap.size() << endl;
    if (ourmap.count("ghi") > 0)
    {
        cout << "ghi is present" << endl;
    }

    unordered_map<string, int> ourmap;
    ourmap["abc"] = 1;
    ourmap["abc1"] = 2;
    ourmap["abc2"] = 3;
    ourmap["abc3"] = 4;
    ourmap["abc4"] = 5;
    ourmap["abc5"] = 6;

    unordered_map<string, int>::iterator it = ourmap.begin();
    while (it != ourmap.end())
    {
        cout << "Key : " << it->first << " Value: " << it->second << endl;
        it++;
    }

    // find
    unordered_map<string, int>::iterator it2 = ourmap.find("abc");
    ourmap.erase(it2, it2 + 4);

    vector<int> v;
    v.push_back(1);
    v.push_back(2);
    v.push_back(3);
    v.push_back(4);
    v.push_back(5);

    vector<int>::iterator it1 = v.begin();
    while (it1 != v.end())
    {
        cout << *it1 << endl;
        it1++;
    }
}
