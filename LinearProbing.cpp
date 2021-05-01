// https://practice.geeksforgeeks.org/problems/linear-probing-in-hashing-1587115620/0/?track=DSASP-Hashing&batchId=155

    vector<int> linearProbing(int hashSize, int a[], int sizeOfArray)
    {
        vector<int> hashTable(hashSize, -1);
        
        for (int i=0; i<sizeOfArray; i++)
        {
            int hashIndex = a[i] % hashSize;
            
            int start = hashIndex;
            
            int isDuplicate = false;
            
            while (hashTable[hashIndex] != -1)
            {
                if (hashTable[hashIndex] == a[i])
                {
                    isDuplicate = true;
                    break;
                }
                    
                hashIndex = (hashIndex + 1) % hashSize;
                
                if (hashIndex == start) 
                    return hashTable;
            }

            if (!isDuplicate)
                hashTable[hashIndex] = a[i];
        }
        
        return hashTable;
    }
