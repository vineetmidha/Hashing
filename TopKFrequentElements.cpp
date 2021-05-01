// https://practice.geeksforgeeks.org/problems/top-k-frequent-elements-in-array/0/?track=dsa-workshop-1-hashing&batchId=308

/*
Example 1:

Input:
nums = {1,1,1,2,2,3},
k = 2
Output: {1, 2}
Example 2:

Input:
nums = {1,1,2,2,3,3,3,4},
k = 2
Output: {3, 2}
Explanation: Elements 1 and 2 have the
same frequency ie. 2. Therefore, in this
case, the answer includes the element 2
as 2 > 1.
*/

   vector<int> topK(vector<int>& a, int k) {
        unordered_map<int, int> mp1;

        // Create frequency map
        
        for (int i=0; i<a.size(); i++)
        {
            mp1[a[i]]++;
        }
        
        // Create map with frequency as key and elements as values
        
        map<int, vector<int>, greater<int>> mp2;
        
        for (auto pair: mp1)
        {
            mp2[pair.second].push_back(pair.first);
        }
        
        int c = 0;
        vector<int> ans;
        
        for (auto pair: mp2)
        {
            vector<int> v = pair.second;
            
            sort(v.begin(), v.end(), greater<int>());

            if (c < k)
            {
                for (auto ele: v)
                {
                    ans.push_back(ele);
                    c++;
                    if (c==k) break;
                }
            }
        }
        
        return ans;
    }

