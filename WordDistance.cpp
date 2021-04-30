// https://www.codingninjas.com/codestudio/problems/word-distance_1229393

#include<bits/stdc++.h>

vector<int> wordDistance(int n, int q, vector<string>& a, vector<vector<string>>& queries){
    map<string, vector<int>> mp;
    vector<int> ans;
    
    for (int i=0; i<n; i++){
        mp[a[i]].push_back(i);
    }
    
    for (auto q: queries){
        if (mp.find(q[0]) == mp.end() || mp.find(q[1]) == mp.end()){
            ans.push_back(n);
            continue;
        }
        
        vector<int> list1 = mp[q[0]];
        vector<int> list2 = mp[q[1]];
        
        if (list1.size()==1 && list2.size()==1){
            ans.push_back(abs(list1[0]-list2[0]));
            continue;
        }
        
        int min_dist = INT_MAX;
        
        for (auto a: list1){
            for (auto b: list2){
                min_dist = min(min_dist, abs(a-b));
            }
        }
        
        ans.push_back(min_dist);
    }
    
    return ans;
}

