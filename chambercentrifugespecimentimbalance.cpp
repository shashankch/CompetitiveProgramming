///uva judge problem balance station 410

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{

  int c, s;
  cin >> c >> s;
  vector<int> v;
  int balsum = 0;
  for (int i = 0; i < s; i++)
  {
    int x;
    cin >> x;
    v.push_back(x);
    balsum += x;
  }

  int totalspace = 2 * c;
  int spaceleft = totalspace - s;
  while (spaceleft--)
  {
    v.push_back(0);
  }
  sort(v.begin(), v.end());
  int l = 0;
  int h = v.size() - 1;
  double imbalance = 0.0;
  int cnt = 0;
  while (l <= h)
  {

    int sum = v[l] + v[h];
    imbalance += abs(sum - (balsum / 2));

    cout << cnt << ":" << v[l] << " " << v[h] << endl;
    cnt++;
    l++;
    h--;
  }

  cout << "IMBALANCE = " << imbalance;

  return 0;
}
