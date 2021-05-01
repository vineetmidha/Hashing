
// https://practice.geeksforgeeks.org/problems/hashing-for-pair-2/0/?track=DSASP-Hashing&batchId=155

int sumExists(int a[], int n, int sum)
{
   unordered_set<int> mp;
   
   for (int i=0; i<n; i++)
   {
        int target = sum - a[i];
        
        if (mp.count(target) > 0)
            return 1;
            
        mp.insert(a[i]);
   }
   
   return 0;
}
