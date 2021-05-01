/*
a=[30,10,20,20,10,20,30,30]
n=8, k=4, n/k = 2
output: 20 30

a=[30,10,20,30,30,40,30,40,30]
n=9, k=2, n/k=4.5
output: 30

Naive
TC: O(n log n) + theta(n) = O(n log n)
*/

void printNbyK(int a[], int n)
{
	sort(a, a+n);

	for (int i=1; i<n; i++)
	{
		int count=1;

		while (i<n && a[i]==a[i-1])
		{
			count++;
			i++;
		}

		if (count > n/k)
			cout << a[i-1] << " ";
	}
}

/*
Efficient-1: hashing
TC: O(n)
SC: O(unique values in the array)
*/

void printNbyK(int a[], int n)
{
	unordered_map<int, int> mp;
	
	for (int i=0; i<n; i++)
		mp[a[i]]++;

	for (auto i: mp)
	{
		if (i.second > n/k)
			cout << i.first << " ";
	}
}

/*
Efficient-2: Extension of Moore's Voting Algorithm

k is very small as compared to n. N is very large. K is very small. 

TC: O(nk)
SC: O(k-1)

a=[30,10,20,20,20,10,20,30,30]
n=9, k=4, n/k = 2.5
output: 20 30

Total number of elements will not more than k-1.

result_count <= k-1

Two phases:

Phase-1
Find out the candidate element.

1. Create an empty map of k-1 size.
2. Traverse
(i) If element exists, frequency is increased by 1.
(ii) If element does not exist and m.size() < k-1, it is inserted with freq=1
(iii) If element does not exist and m.size() >= k-1, decrease all values in map by one. If value becomes zero, remove the element from map.

Phase-2

Validation of output

For all the elements in map, print the elements that actually appear more than n/k times. 
*/

void printNByK(int arr[], int n, int k)
{
    unordered_map<int,int> m;
    
    for(int i=0;i<n;i++){
        if(m.find(arr[i])!=m.end())
            m[arr[i]]++;
        else if(m.size()<k-1)
            m[arr[i]]=1;
        else
            for(auto x:m){
                x.second--;
                if(x.second==0)
                    m.erase(x.first);}
    }
    for(auto x:m){
        int count=0;
        for(int i=0;i<n;i++){
            if(x.first==arr[i])
                count++;
        
       }
        if(count>n/k)
            cout<<x.first<<" ";
    }
}

