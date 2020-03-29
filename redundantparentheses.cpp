
#include <iostream>
#include <cstring>
#include <stack>

using namespace std;

int main()
{

        int t;

        cin >> t;
        while (t--)
        {
                stack<char> s;
                int cnt = 0;
                string str;
                cin >> str;
                int i;
                for (i = 0; i < str.length(); i++)
                {

                        if (str[i] != ')')
                        {
                                s.push(str[i]);
                        }
                        else
                        {

                                if (s.top() == '(')
                                {
                                        cout << "Duplicate" << endl;
                                        break;
                                }
                                else
                                {

                                        while (s.top() != '(')
                                        {
                                                cnt += 1;
                                                s.pop();
                                        }
                                        s.pop();
                                }
                        }
                }
                if (s.empty())
                {
                        cout << "Not Duplicates" << endl;
                }
        }

        return 0;
}
