
void FirstTwoNonRepeatingVowels(string s) {
    cout << s << endl;

    map<char, int> mp;

    for (int i=0; i<s.size(); i++)
    {
        mp[s[i]]++;
    }

    string vowels = "aeiouAEIOU";

    set<char> vowelset(vowels.begin(), vowels.end());

    int c = 0;

    for (int i=0; i<s.size(); i++)
    {
        if (vowelset.count(s[i]) && mp[s[i]] == 1)
        {
            cout << s[i] << " ";
            c++;
            if (c==2) break;
        }
    }

}
