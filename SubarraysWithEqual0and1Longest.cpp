
/*
     |--|  |-----|
a = [1,0,1,1,1,0,0]
       |----------|
output: 6

a=[1,1,1,1]
output: 0

a=[0,0,0]
output: 0

a=[0,0,1,1,1,1,1,0]
   |------|    |--|
output: 4

a=[0,0,1,0,1,1]
       |--|
     |------|
   |----------|
output: 6

Naive:

1. Consider all subarrays.
2. Count 0s and 1s.
3. Compare
*/

int longestSub(int a[], int n)
{
	int res=0;
	for (int i=0; i<n; i++)
	{
		int c0=0, c1=0;
		for (int j=i; i<n; i++)
		{
			if (a[i]==0) c0++;
			else c1++;

			if (c0==c1) res = max(res, c0+c1);
		}
	}
	return res;
}

/*
Efficient:
TC: theta(n)
SC: O(n)

1. Replace every 0 with -1  	--> theta(n)
	
	for (int i=0; i<n; i++)
	{	
		if (a[i]==0) a[i]=-1;
	}

2. Call the function to find length of the longest subarray with 0 sum.

	--> theta(n)
*/



