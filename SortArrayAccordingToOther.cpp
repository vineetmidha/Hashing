// https://practice.geeksforgeeks.org/problems/relative-sorting4323/0/?track=DSASP-Hashing&batchId=155

    vector<int> sortA1ByA2(vector<int> a, int n, vector<int> b, int m) 
    {
        map<int, int> mp;

        for (auto i: a)
        {
            mp[i]++;
        }

        bool found = false;
        
        int k=0;
        
        vector<int> ans(a.size());
        
        for (auto i: b)
        {
            if (mp.count(i) > 0)
            {
                found = true;
                
                for (int j=0; j<mp[i]; j++)
                {
                    ans[k++] = i;
                }
                
                mp.erase(i);
            }
        }
        
        if (!found)
        {
            sort(a.begin(), a.end());
            return a;            
        }
        else 
        {
            for (auto i: mp)
            {
                for (int j=0; j<i.second; j++)
                {
                    ans[k++] = i.first;
                }
            }
            
            return ans;
        }
    } 
