/*
a = [1,20,20,2,3,40,5,5]
k = 3
Output: 1, 20, 2
*/

void solve(int test=0)
{
    int n, k;
    cin >> n >> k;

    int a[n];

    for (int i=0; i<n; i++)
    {
        cin >> a[i];
    }

    map<int, int> mp;

    for (int i=0; i<n; i++)
    {
        if (mp.size() == k)
            break;

        mp[a[i]]++;
    }    

    for (auto pair: mp)
    {
        cout << pair.first << " " << pair.second << endl;
    }

    cout << "\n";
}
