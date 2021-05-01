// Count Frequency of array elements

Naive: Nested Loop

void printFreq(int a[], int n)
{
	for (int i=0; i<n; i++)
	{
		bool flag = false;
		// check left of element if it is seen or not

		for (int j=0; j<i; j++){
			if (a[i]==a[j]) {flag = true; break;}
		}

		if (flag==true)  // if seen in left, go to next element
			continue;

		// if not found in left, find element in right

		int freq=1;
		for (int j=i+1; j<n; i++)
		{
			if a[i]==a[j]) freq++;
		}
		
		cout << a[i] << " " << freq << endl;	
	}
}

Efficient: hash map

int coutFreq(int a[], int n)
{
	unordered_map<int> mp;
	for (int i=0; i<n; i++)
	{
		mp[a[i]]++;
	}

	for (auto i: mp)
	{
		cout << i.first << " " << i.second << endl;
	}
}

