
/*
Naive: Nested Loop
*/

bool isSumSubarray(int a[], int n, int sum)
{
	for (int i=0; i<n; i++)
	{
		int cur_sum = 0;
		for (int j=i; j<n; j++)
		{
			cum_sum += a[j];
			if (cur_sum==sum) return true;
		}
	}
	return false;
}

/*
Efficient:

1. Keep computing prefix sum and store in the hash set
2. For every point, search for current prefix sum - sum in the hash set. if found, return true

Pre_sum2 = pre_sum1 + sum

pre_sum2 = pre_sum1 + sum
|-----------------------------|
a0,a1,a2,......ai,ai+1........aj.......an-1
|---------------| |-----------|
pre_sum1             sum

a = [5,8,6,13,3,-1]
sum = 22

i	pre_sum		hash
0	5		5
1	13		5, 13
2	19		5, 13, 19
3	32		5, 13, 19, 32
4	35		35-22 = 13 is present in the hash

*/

bool isSumSubarray(int a[], int n, int sum)
{
	unordered_set<int> mp;
	int pre_sum = 0;
	for (int i=0; i<n; i++)
	{
		pre_sum += a[i];
		if (pre_sum==sum) return true;
		if (mp.count(pre_sum-sum) > 0) return true;
		mp.insert(pre_sum);
	}
	return false;
}

