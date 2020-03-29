
#include <iostream>
#include <stack>
using namespace std;

/// three methods to reverse stack:
///I- using 2 stacks;
///II- using 1 stack;
///III- using recursion;

/// method 1

void transfer(stack<char> &s1, stack<char> &s2)
{

    while (!s1.empty())
    {

        s2.push(s1.top());
        s1.pop();
    }
}

/// method II--->>>>>>>>>>>> in this first extract top element and then insert rem.elements in
/// in another stack (n-i-1) elements.. now push extracted element in the original stack
/// then push back all the rem... elements back to the original stack ..do this for all stack.size..

void transfern(stack<char> &s1, stack<char> &s2, int n)
{

    for (int i = 0; i < n; ++i)
    {

        s2.push(s1.top());
        s1.pop();
    }
}

void reversestack(stack<char> &s1)
{

    stack<char> s2;
    int n = s1.size();
    for (int i = 0; i < n; ++i)
    {

        int top = s1.top();
        s1.pop();

        transfern(s1, s2, n - i - 1);
        s1.push(top);
        transfern(s2, s1, n - i - 1);
    }
}

///method III ---reverse using recursion..
/// in this first if empty then return . else pop the element now recur reverse for rest of the elements
/// and insert popped element at the bottom.-->for this if empty insert element else pop element call recur..then push the popped element..
///

void insertatbottom(stack<char> &s1, char x)
{

    if (s1.empty())
    {
        s1.push(x);
        return;
    }

    int y = s1.top();
    s1.pop();
    insertatbottom(s1, x);
    s1.push(y);
}

void reversestackrecur(stack<char> s1)
{

    if (s1.empty())
    {

        return;
    }
    char x = s1.top();
    s1.pop();
    reversestackrecur(s1);
    insertatbottom(s1, x);
}

////////////////////////////////////////////////////////////

int main()
{

    ////////////////////////////////method 1/////////////////////////
    ///stack <char>s1,s2,s3;
    ///s1.push('A');
    ///s1.push('B');
    ///s1.push('C');
    ///s1.push('D');
    ///transfer(s1,s2);
    ///transfer(s2,s3);
    ///transfer(s3,s1);
    ///while(!s1.empty()){

    /// cout<<s1.top()<<" ";
    /// s1.pop();
    ///}

    ///////////////////////////////////////////method 2 ///////
    stack<char> s1;
    s1.push('A');
    s1.push('B');
    s1.push('C');
    s1.push('D');
    reversestack(s1);

    while (!s1.empty())
    {

        cout << s1.top() << " ";
        s1.pop();
    }

    return 0;
}
