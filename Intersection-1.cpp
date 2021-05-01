
// https://practice.geeksforgeeks.org/problems/intersection-of-two-arrays2404/0/?track=DSASP-Hashing&batchId=155

a =[10,15,20,5,30]
b = [30,5,30,80]
Output: 2

Naive
1. initialize res=0
2. Traverse through every element of a[]
........ Check if it is has not appeared already
........ If a new element and also present in b[], do res++
3. Return res

void printFreq(int a[], int n)
{
	for (int i=0; i<n; i++)
	{
		bool flag = false;

		for (int j=0; j<i; j++){
			if (a[i]==a[j]) {flag = true; break;}
		}

		if (flag==true) 
			continue;

		// if not found in left, find element in b[]

		int freq=1;
		for (int j=0; j<n; i++)
		{
			if a[i]==b[j]) { res++; break; }
		}
		
		cout << a[i] << " " << freq << endl;	
	}

	return res;
}

Efficient-1:

1. Insert all elements of a[] in a set (unordered)
2. Insert all elements of b[] in another set (unordered)
3. Traverse through set A and increment count for elements that are present in set B also.

Efficient-2:

1. Insert all elements of a[] in a set (unordered)
2. Traverse through b[] and seaerch for every element b[i]:
........ Increment count if element is found in set A.
........ Remove b[i] from set A.

    int NumberofElementsInIntersection (int a[], int b[], int n, int m )
    {
        unordered_set<int> seta(a, a+n);

        int res = 0;
        for (int i=0; i<m; i++)
        {
            if (seta.find(b[i])!=seta.end())
            {
                res++;
                seta.erase(b[i]);
            }
        }   
        
        return res;
    }
