// https://www.codingninjas.com/codestudio/problems/first-repeated-character_1214646

int firstRepeated(int v[], int n) {
    set<int> s;
    int min = -1;
    for (int i=n-1; i>=0; i--){
        if (s.find(v[i]) != s.end()){
            min = i;
        } else {
            s.insert(v[i]);
        }
    }
    
    if (min != -1)
        return min+1;
    else
        return min;
}

char firstRepeatedCharacter(string &str)
{
    if (str.size()==0) return '%';
    
	set<char> mp;

    int min = -1;
    char ans = '%';
    
    for (int i=str.size()-1; i >= 0; i--)
    {
        if (mp.count(str[i]) > 0){
            min = i;
            ans = str[i];
        }
        else {
            mp.insert(str[i]);
        }
    } 
     
    return ans;
}
