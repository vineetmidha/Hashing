
void FirstTwoNonRepeated(int a[], int n) {
    map<int, int> mp;

    for (int i=0; i<n; i++)
    {
        mp[a[i]]++;
    }

    int c=0;
    
    for (int i=0; i<n; i++)
    {
        if (mp[a[i]] == 1)
        {
            cout << a[i] << " ";
            c++;
            if (c==2) break;
        }
    }

}
