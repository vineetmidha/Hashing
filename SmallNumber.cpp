// https://mycode.prepbytes.com/problems/searching/SMALLNUM

#include <bits/stdc++.h>
using namespace std;

int main()
{
  int n;
  cin >> n;

  map<int, int> mp;
  
  for (int i=0; i<n; i++)
  {
    int x; 
    cin >> x;
    
    mp[x]++;
  }

  int k;
  cin >> k;
  
  for (auto pair: mp)
  {
    if (pair.second == k)
    {
      cout << pair.first << endl;
      break;
    }
  }
  
  return 0;
}
