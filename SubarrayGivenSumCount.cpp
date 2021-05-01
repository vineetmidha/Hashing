// https://practice.geeksforgeeks.org/problems/subarray-range-with-given-sum0128/0/?track=DSASP-Hashing&batchId=155

    int subArraySum(int a[], int n, int sum)
    {
        unordered_map<int, int> mp;
        
        int presum=0;
        
        int res = 0;
        
        for (int i=0; i<n; i++)
        {
            presum += a[i];
            
            if (presum == sum) res++;
            
            int target = presum-sum;

            if (mp.count(presum-sum) > 0)
                res += mp[target];

            mp[presum]++;
        }
        
        return res;
    }
