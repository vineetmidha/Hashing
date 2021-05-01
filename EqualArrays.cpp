
// https://practice.geeksforgeeks.org/problems/check-if-two-arrays-are-equal-or-not3847/1/?track=DSASP-Hashing&batchId=155

    bool check(vector<ll> a, vector<ll> b, int N) {
        unordered_map<int, int> mp;
        
        for (auto i: a){
            mp[i]++;
        }
        
        for (auto i: b){
            if (mp.count(i)==0)
                return false;
                
            mp[i]--;
            if (mp[i]==0) mp.erase(i);
        }
        
        return mp.size()==0;
    }
