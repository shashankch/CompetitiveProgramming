

#include <iostream>
using namespace std;

void tohrecur(int n, char s, char d, char h)
{

  /// if(n=0) return;          this also can be used

  if (n == 1)
  {

    cout << "Move" << n << "-->" << s << "from" << d << endl;
    return;
  }

  tohrecur(n - 1, s, h, d);
  cout << "Move" << n << "-->" << s << "from" << d << endl;
  tohrecur(n - 1, h, d, s);
}

int main()
{

  int n;

  cin >> n;

  tohrecur(n, 'A', 'C', 'B');

  return 0;
}
