
///spoj busy man

#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

bool compare(pair<int, int> a, pair<int, int> b)
{

  if (a.second == b.second)
  {
    return a.first < b.first;
  }
  return a.second < b.second;
}

int main()
{

  vector<pair<int, int>> v;
  int t;
  cin >> t;
  while (t--)
  {

    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {

      int st, et;
      cin >> st >> et;
      v.push_back(make_pair(st, et));
    }

    sort(v.begin(), v.end(), compare);

    int fin = v[0].second;
    int res = 0;
    for (int i = 1; i < v.size(); i++)
    {

      if (v[i].first >= fin)
      {

        fin = v[i].second;
        res++;
      }
    }

    cout << "Total no.of activites possible: " << res << endl;
  }

  return 0;
}
