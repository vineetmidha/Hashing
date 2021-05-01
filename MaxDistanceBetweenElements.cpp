// https://practice.geeksforgeeks.org/problems/max-distance-between-same-elements/1/?track=dsa-workshop-1-hashing&batchId=308

    int maxDistance(int a[], int n)
    {
        unordered_map<int, int> mp;
        
        int ans = 0;
        
        for (int i=0; i<n; i++)
        {
            if (mp.count(a[i]) == 0)
                mp[a[i]] = i;
            else
            {
                int cur_distance = i - mp[a[i]];
                ans = max(ans, cur_distance);
            }
        }
        
        return ans;
    }
