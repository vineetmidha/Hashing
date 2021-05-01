// https://practice.geeksforgeeks.org/problems/longest-consecutive-subsequence2449/0/?track=DSASP-Hashing&batchId=155

/*
Length of the longest subsequence s.t. the subsequence has consecutive elements. Such elements may appear in any order in the array.
Individual elements are one-length elements.
Duplicates are ignored.

a=[1,9,3,4,2,20]
output: 4 --> 1, 2, 3, 4

a=[8,20,7,30]
output:2 --> 7, 8

a=[20,30,40]
output:1

a=[3,2,3,4]
output: 3 --> 2, 3, 4

Naive: Sorting  TC: O(n log n)
*/

int longestSub(int a[], int n)
{
	sort(a, a+n);
	int res=1, curr=1;

	for (int i=1; i<n; i++)
	{
		if (a[i] == a[i-1]+1) 
			curr++;
		else if (a[i] != a[i-1]) // exclude duplicates
		{
			res = max(res, curr);
			curr = 1;
		}

	}
	return max(res, curr);
}

/*
Efficient -> TC: O(n)

1. First insert all elements in a hash table.

2. Then, with 2n lookups, we find the result. 

3. For every element x in the hash, we will look for x-1 value in the hash. If x-1 is not available, it means x is the beginning of the sequence. In this case, we search for x+1, then for x+2 ..... till the search fails. 

4. If x-1 is available then it means x cannot be the beginning of the subsequence. Hence, it is ignored. And, next element in the hash is searched.
*/

int longestSub(int a[], int n)
{
	unordered_set<int> mp (a,a+n);  // theta(n)

	int res=0;

	for (auto x: mp)
	{
		if (mp.count(x-1) == 0)
		{
			int curr = 1;
			while (mp.count(a[i]+1) > 0)
			{
				curr++;
			}
			res = max(res, curr);
		}
	}

	return res;
}

/*
Number of lookups is twice the size of the hash table.

h = [1,3,4,2]
x = 1
curr=1
curr=2
curr=3
curr=4
Total=5

x = 3
Total = 1

x = 4
Total = 1

x = 2
Total = 1

Total=8


h = [8,20,4]

x=8:
curr=1, Total=2

x=20:
curr=1, Total=2

x=4:
curr=1, Total=2

Total=6

h = [2,4,8,3]

x=2:
curr=1
curr=2
curr=3
Total=4

x=4:
Total=1

x=8:
curr=1, Total=2

x=3:
Total=1

Total = 8 

For the elements which are part of a subsequence but not the first elements, only one lookup is done. 
For the elements which are part of a subsequence and are the first element, 2 + (length-1) lookups are done. 
Here, length is the length of the subsequence beginning with the element.
*
