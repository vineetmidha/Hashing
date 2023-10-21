/*

k <= n

Total windows = n-k+1

a=[10,20,20,10,30,40,10]
k=4
output: 2 3 4 3

a=[10,10,10,10]
k=3
output: 1 1
If all elements are same, 1 is printed n-k+1 times.

a=[10,20,30,40]
k=3
output: 3 3
If all elements are distinct, then k is printed n-k+1 times.

Naive
O((n-k)*k*k)
It can be cubic if k=n-1 or k = n

1. Consider starting point of every window.
2. Traverse through n-k+1 windows.
3. Outer loop runs n-k times.
4. Check each element of the window if it is unique or not. [nested loop]
*/

void printDistinct(int a[], int n, int k)
{
	for (int i=0; i<=n-k; i++)
	{
		int count=0;
		for (int j=0; j<k; j++)
		{
			bool flag = false;
			for (p=0; p<j; p++)
			{
				if (a[i+j]==a[i+p])
				{
					flag = true;
					break;
				}
			}
			if (flag==false)
				count++;
		}
		cout << count << " ";
	}
}

/*
Efficient

maintain frequency map of elements of each window

1. Create frequency map of 1st window.
2. Traverse all the windows one by one. 
3. Create the frequency map of current window using the frequency map of previous window.

Implementation:
1. Create frequency map of 1st window.
2. Print the size of the frequency map.
3. Traverse all the windows.
(i) Decrease frequency of a[i-k]
(ii) If the frequency of a[i-k] becomes 0, remove it from the map.
(iii) If the element does not exist in the map, insert the element frequency in the map. 
(iv) Print the size of frequency map.

So, we need to process the first item of the previous window and the last item of the current window. 
*/

void printDistinct(int a[], int n, int k)
{
	unordered_map<int,int> mp;

	for (int i=0; i<k; i++)
	{
		mp[a[i]]++;
	}

	cout << mp.size() << " ";

	for (int i=k; i<n; i++)
	{
		mp[a[i-k]]--;

		if (mp[a[i-k]]==0) mp.erase(mp[a[i-k]]);

		mp[a[i]]++;

		cout << mp.size() << " ";
	}
}

# Python Code

def count_distinct(a, k):
    d = {}
    
    for i in range(len(a)):
        d[a[i]] = d.get(a[i], 0) + 1
        if i >= k-1:
            print(len(d), end=' ')
            d[a[i+1-k]] -= 1
            if d[a[i+1-k]] == 0:
                d.pop(a[i+1-k])

a = [1, 2, 4, 4]; k = 2
count_distinct(a, k)
	

