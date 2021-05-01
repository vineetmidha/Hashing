
/*
Given an array having both positive and negative integers. The task is to compute the length of the largest subarray with sum 0.

Example 1:

Input:
N = 8
A[] = {15,-2,2,-8,1,7,10,23}
Output: 5
Explanation: The largest subarray with
sum 0 will be -2 2 -8 1 7.
Your Task:
You just have to complete the function maxLen() which takes two arguments an array A and n, where n is the size of the array A and returns the length of the largest subarray with 0 sum.
*/

int maxLen(int a[], int n)
{
    unordered_map<int, int> mp;
    
    int presum = 0;
    
    int ans = 0;
    
    for (int i=0; i<n; i++)
    {
        presum += a[i];
        
        if (presum==0) ans = i+1;
        
        if (mp.count(presum) > 0)
        {
            int cur_len = i - mp[presum];
            ans = max(ans, cur_len);
        }
        else 
        {
            mp[presum] = i;
        }
    }
    
    return ans;
}


