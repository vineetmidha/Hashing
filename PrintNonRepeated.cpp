
// https://practice.geeksforgeeks.org/problems/print-distinct-elements-1587115620/0/?track=DSASP-Hashing&batchId=155

vector<int> printNonRepeated(int a[],int n)
    {
        unordered_map<int,int> mp;
        
        for (int i=0; i<n; i++)
        {
            mp[a[i]]++;
        }

        vector<int> res;
        
        for (int i=0; i<n; i++)
        {
            if (mp[a[i]]==1)
                res.push_back(a[i]);
        }
        
        return res;        //Your code here
    }

