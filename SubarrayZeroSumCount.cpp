
// https://practice.geeksforgeeks.org/problems/zero-sum-subarrays1825/0/?track=DSASP-Hashing&batchId=155

    ll findSubarray(vector<ll> a, int n ) {
        ll ans = 0;
        
        unordered_map<ll, ll> mp;
        
        int presum = 0;
        
        for (int i=0; i<n; i++)
        {
            presum += a[i];
            
            if (presum==0) ans++;
            
            if (mp.count(presum) > 0)
                ans += mp[presum];
                
            mp[presum]++;
        }
        
        return ans;
    }

