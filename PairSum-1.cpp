// https://practice.geeksforgeeks.org/problems/hashing-for-pair-1/0/?track=DSASP-Hashing&batchId=155

/*

Naive: Nested loop
1. Consider all possible pairs one by one and check for sum.
2. If a pair is found, return true else return false

Efficient-1: Sorted array with two-pointers
TC : n log n
Better if the array is already sorted

Efficient-2:
TC: O(n)

1. Before inserting element in the hash table, we check if it forms a pair with any of the existing elements of the hash table
2. If it forms a pair, return True.

*/


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

