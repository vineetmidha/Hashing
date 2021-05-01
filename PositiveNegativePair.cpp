// https://practice.geeksforgeeks.org/problems/positive-negative-pair5209/0/?track=DSASP-Hashing&batchId=155

    vector <int> findPairs(int a[], int n) 
    {
        vector<int> ans;
        
        unordered_map<int, int> mp;
        
        for (int i=0; i<n; i++)
        {
            int target = -a[i];
            
            if (mp.count(target) > 0)
            {
                ans.push_back(a[i] < 0 ? a[i] : target);
                ans.push_back(a[i] > 0 ? a[i] : target);
            }
            else
                mp[a[i]];
        }
        
        return ans;
    }
