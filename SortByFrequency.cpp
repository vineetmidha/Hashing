// https://practice.geeksforgeeks.org/problems/sorting-elements-of-an-array-by-frequency-1587115621/0/?track=DSASP-Hashing&batchId=155

    vector<int> sortByFreq(int a[],int n)
    {
        unordered_map<int,int> mp1;
        
        for (int i=0; i<n; i++) mp1[a[i]]++;
        
        map<int, vector<int>, greater <int>> mp2;

        for (auto i: mp1)
        {
            mp2[i.second].push_back(i.first);
        }

        vector<int> ans;

        for (auto i: mp2)
        {
            vector<int> v = i.second;
            
            sort(v.begin(), v.end());
            
            for (auto j: v)
            {
                for (int k=0; k<i.first; k++)
                    ans.push_back(j);
            }
        }
        
        return ans;
    }

