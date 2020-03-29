
#include <iostream>
#include <string>
using namespace std;

void movexend(string str, int i)
{

  if (i == str.length())
  {
    return;
  }
  if (str[i] != 'x')
  {
    cout << str[i];
  }
  movexend(str, i + 1);
  if (str[i] == 'x')
  {

    cout << 'x';
  }

  return;
}

///method2
void end(string str, string con)
{
  if (str.length() == 0)
  {
    cout << con << endl;
    return;
  }
  char ch = str[str.size() - 1];
  string ros = str.substr(0, str.size() - 1);
  if (ch != 'x')
  {
    end(ros, ch + con);
  }
  else
  {
    end(ros, con + ch);
  }
}

///method 3
void work(char *s, int n, int j)
{
  if (n == 1)
    return;

  if (j == n - 1)
    return work(s, n - 1, 0);

  if (s[j] == 'x')
  {
    swap(s[j], s[j + 1]);
  }

  work(s, n, j + 1);
}

int main()
{

  string str;
  cin >> str;
  movexend(str, 0);

  return 0;
}
