
// https://practice.geeksforgeeks.org/problems/count-distinct-elements-1587115620/0/?track=DSASP-Hashing&batchId=155


    int countNonRepeated(int a[], int n)
    {
        unordered_map<int,int> ans;
        
        for (int i=0; i<n; i++)
        {
            ans[a[i]]++;
        }

        int res = 0;
        
        for (auto i: ans)
        {
            if (i.second==1)
                res++;
        }
        
        return res;
    }
