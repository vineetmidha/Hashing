
// https://www.codechef.com/LTIME95C/problems/BENCHP

#include <bits/stdc++.h>
using namespace std;

#define int long long

void solve(int test=0)
{
    int n, w, wr;
    cin >> n >> w >> wr;

    unordered_map<int, int> mp;

    while (n--)
    {
        int x;
        cin >> x;
        mp[x]++;
    }

    if (wr >= w)
    {
        cout << "YES\n";
        return;
    }

    for (auto pair: mp)
    {
        int wt = pair.first;
        int wt_count = pair.second;

        if (wt_count % 2 != 0)
        {
            wt_count--;
        }

        wr += wt * wt_count; 
    }

    if (wr >= w)
        cout << "YES\n";
    else
        cout << "NO\n";
}


signed main() {
	int t;
	cin >> t;
	
	while (t--) solve();
	
	return 0;
}

