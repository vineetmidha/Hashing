// https://practice.geeksforgeeks.org/problems/count-subarrays-with-equal-number-of-1s-and-0s-1587115620/0/?track=DSASP-Hashing&batchId=155


    long long int countSubarrWithZeroSum(int a[], int n)
    {
        long long int ans = 0;
        
        long long int presum = 0;
        
        unordered_map<long long int, long long int> mp;
        
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
    
    long long int countSubarrWithEqualZeroAndOne(int a[], int n)
    {
        for (int i=0; i<n; i++)
            if (a[i]==0) a[i]=-1;
            
        return countSubarrWithZeroSum(a, n);
    }


