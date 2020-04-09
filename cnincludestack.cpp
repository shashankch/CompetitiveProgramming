#include <iostream>
using namespace std;
#include "cnstacklinkedlist.h"
#include <stack>

int main(int argc, char const *argv[])
{
    // Stack<int> s;
    // s.getSize();
    // s.push(10);

    stack<int> s;
    s.push(39);
    s.push(39);
    s.pop();
    int t = s.top();
    int s = s.size();
    bool ans = s.empty();

    return 0;
}
