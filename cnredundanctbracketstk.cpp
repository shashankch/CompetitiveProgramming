#include <bits/stdc++.h>
using namespace std;
int main()
{

    return 0;
}

bool checkRedundantBrackets(char *input)
{
    // Write your code here
    stack<int> s;
    int n = strlen(input);

    for (int i = 0; i < n; i++)
    {

        if (input[i] != ')')
        {

            s.push(input[i]);
        }
        else
        {

            int count = 0;
            while (s.top() != '(' && !s.empty())
            {

                count++;
                s.pop();
            }

            s.pop();
            if (count == 0)
            {

                return true;
            }
        }
    }

    return false;
}