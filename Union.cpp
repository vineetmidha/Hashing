// https://practice.geeksforgeeks.org/problems/union-of-two-arrays3538/0/?track=DSASP-Hashing&batchId=155

Naive
1. res=0
2. Create an auxiliary array, d[]
3. Traverse through a[]. For every element in a[], check if it is in b[]
.......(a) If no, res++
.......(b) Append element in d[]
4. Repeat step 3 for every element in b[]

Efficient
1. Create hash set
2. Insert all elements of a[]
3. Insert all elements of b[]
4. return set.size()

    int doUnion(int a[], int n, int b[], int m)  {
        unordered_set<int> ans(a,a+n);
    
        for (int i=0; i<m; i++)
        {
            ans.insert(b[i]);
        }    
        
        return ans.size();
    }
