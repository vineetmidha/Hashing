
/*
a=[5,8,-4,-4,9,-2,2]
     |------|  |---|
sum = 0
output: 3

a=[3,1,0,1,8,2,3,6]
   |------|  |--|
sum=5
output: 4

a=[8,3,7]
sum=15
output:0

Naive: Nested Loop
*/

int longestSubarraySum(int a[], int n, int sum)
{
	int res = 0;
	for (int i=0; i<n; i++)
	{
		int cur_sum = 0;
		for (int j=i; j<n; j++)
		{
			cum_sum += a[j];
			if (cur_sum==sum) res = max(res,j-i+1);
		}
	}
	return res;
}

/*
Efficient:

1. Keep computing prefix sum and store it in the map as key and ending index as the value
2. For every point, search for current prefix sum - sum in the hash set. if found, return true
3. Here, if a prefix sum repeats, it means that there is a subarray whose sum is 0 and in such a case we will not update the index of that prefix sum in the map, because that zero sum can contribute to find out a longer subarray with the given sum

Pre_sum2 = pre_sum1 + sum

pre_sum2 = pre_sum1 + sum
|-----------------------------|
a0,a1,a2,......ai,ai+1........aj.......an-1
|---------------| |-----------|
pre_sum1             sum

a = [8,3,1,5,-6,6,2,2]
       |--|  |------|  
sum = 4

i	pre_sum		map
			{}
0	8		(8,0), res=0
1	11		(8,0), (11,1), res=0
2	12		(8,0), (11,1), (12,2), res=2-0=0
3	17		(8,0), (11,1), (12,2), (17,3), res=2
4	11		(8,0), (11,1), (12,2), (17,3), res=2
// here, (11,4) will not be inserted in the map
5	17		(8,0), (11,1), (12,2), (17,3), res=2
// here, (17,5) will not be inserted in the map
6	19		(8,0), (11,1), (12,2), (17,3), (19,6), res=2
7	21		(8,0), (11,1), (12,2), (17,3), (19,6), (21,7), res=7-3=4
*/

int longestSubarraySum(int a[], int n, int sum)
{
	unordered_map<int,int> mp;
	int pre_sum = 0, res=0;
	for (int i=0; i<n; i++)
	{
		pre_sum += a[i];
		if (pre_sum==sum) res = i+1;

		// if pre_sum does not already exist,
		// then only it is inserted in the map 

		if (mp.count(pre_sum) == 0) mp.insert({pre_sum,i});
			
		// if pre_sum already exists,
		// then it is not inserted in the map 
		// because its index would get updated

		if (mp.count(pre_sum-sum) > 0) 
			res = max(res, i-mp[pre_sum-sum]);
	}
	return res;
}

