#include <iostream>
#include <cstring>
using namespace std;
void printsubstrings(char *a)
{

  for (int i = 0; a[i] != '\0'; i++)
  {

    for (int j = i; a[j] != '\0'; j++)
    {

      ///  cout<<"{"<<i<<","<<j<<"}"<<" ";
      for (int k = i; k <= j; k++)
      {
        cout << a[k];
      }

      cout << endl;
    }
  }
}
int main()
{

  char s1[100] = "abc";
  ///cin>>s1;
  printsubstrings(s1);
  return 0;
}
