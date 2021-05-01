// https://practice.geeksforgeeks.org/problems/subarray-with-0-sum-1587115621/0/?track=DSASP-Hashing&batchId=155

/*
Naive

Consider every element as beginning element and find sum of all sub arrays beginning with it.
*/

bool is0Subarray(int a[], int n)
{
	for (int i=0; i<n; i++)
	{
		int cur_sum = 0;
		for (int j=i; j<n; j++)
		{
			cum_sum += a[j];
			if (cur_sum==0) return true;
		}
	}
	return false;
}

/*
Efficient: prefix sum + hashing

1. Keep computing prefix sum and store in the hash set
2. If the prefix sum = 0 or prefix sum is already there in the hash set, return true.
*/

bool is0Subarray(int a[], int n)
{
	unordered_set<int> mp;
	int pre_sum = 0;
	for (int i=0; i<n; i++)
	{
		pre_sum += a[i];
		if (mp.count(pre_sum) > 0) return true;
		if (pre_sum==0) return true;
		mp.insert(pre_sum);
	}
	return false;
}
