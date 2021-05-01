// https://practice.geeksforgeeks.org/problems/separate-chaining-in-hashing-1587115621/1/?track=DSASP-Hashing&batchId=155

    vector<vector<int>> separateChaining(int hashSize,int a[],int sizeOfArray)
    {
        vector<vector<int>> hashTable(hashSize);
        
        for (int i=0; i<sizeOfArray; i++)
        {
            int hash_code = a[i] % hashSize;
            hashTable[hash_code].push_back(a[i]);
        }
        
        return hashTable;
    }
