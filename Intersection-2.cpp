// https://leetcode.com/problems/intersection-of-two-arrays-ii/

    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        map<int, int> mp;
        for (int i: nums1)
        {
            mp[i]++;
        }
        
        vector<int> ans;
        
        for (int i: nums2)
        {
            if (mp.count(i))
            {
                mp[i]--;
                ans.push_back(i);
                if (mp[i]==0)
                    mp.erase(i);
            }
        }
        
        return ans;
    }
