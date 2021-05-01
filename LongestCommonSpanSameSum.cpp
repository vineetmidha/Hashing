/*
a=[0,1,0,0,0,0]
     |------|
b=[1,0,1,0,0,1]
output:4

a=[0,1,0,1,1,1,1]
    |-----------|
b=[1,1,1,1,1,0,1]
output:6

a=[0,0,0]
b=[1,1,1]
output:0

a=[0,0,1,0]
      |-|
b=[1,1,1,1]
output:1

Naive

1. Traverse all the sub-arrays in both the arrays.
2. Find sum of sub-arrays in both the arrays.
3. If sum is same, compare
*/

int maxCommon(int a[], int b[], int n)
{
	int res = 0;
	for (int i=0; i<n; i++)
	{
		int sum1 = 0, sum2 = 0;
		for (int j=i; j<n; j++)
		{
			sum1 += a[j];
			sum2 += b[j];
			if (sum1==sum2) res = max(res,j-i+1);
		}
	}
	return res;
}

/*
Efficient

Reduce the problem of longest subarray with 0 sum in an array

1. Compute a difference array

int temp[n];
for (int i=0; i<n; i++)
	temp[i] = a[i] - b[i];

a = [0,1,0,0,0,0]
b = [1,0,1,0,0,1]
t = [-1,1,-1,0,0,-1]

2. Return the length of the longest subarray with 0 sum in temp

(i) we get 0 when values are same in both
(ii) we get 1 when a[i]=1 and b[i]=0
(iii) we get -1 when a[i]=0 and b[i]=1

*/

