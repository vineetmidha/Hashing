
// https://practice.geeksforgeeks.org/problems/winner-of-an-election-where-votes-are-represented-as-candidate-names-1587115621/0/?track=DSASP-Hashing&batchId=155

    vector<string> winner(string a[],int n)
    {
        vector<string> ans;
        
        map<string, int> mp;
        
        for (int i=0; i<n; i++)
        {
                mp[a[i]]++;
        }
    
        int maxi = 0;
        string winnerName = "";
    
        for (auto i: mp)
        {
            if (i.second > maxi){
                maxi = i.second;
                winnerName = i.first;
            }
            else if (i.second == maxi) {
                winnerName = min(winnerName, i.first);
            }
        }
        
        ans.push_back(winnerName);
        ans.push_back(to_string(maxi)); 
        
        return ans;
    }
    
