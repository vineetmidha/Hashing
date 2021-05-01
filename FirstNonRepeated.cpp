// https://www.geeksforgeeks.org/non-repeating-element/

/*
TC: O(n)
SC: (n)

1. Traverse and create frequency map
2. Traverse string again and check first character whose frequency is 1.
*/
    
char firstNonRepeated(string &str)
{
    if (str.size()==0) return '%';
        
    map<char, int> freq;
    
    for (int i=0; i<str.size(); i++)
    {
        freq[str[i]]++;
    }
    
    for (int i=0; i<str.size(); i++)
    {
        if (freq.count(str[i]) == 1)
            return str[i];
    }
    
    return '%';
}
