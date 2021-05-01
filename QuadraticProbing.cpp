// https://practice.geeksforgeeks.org/problems/quadratic-probing-in-hashing-1587115621/0/?track=DSASP-Hashing&batchId=155

    void QuadraticProbing(vector <int>&hashTable, int hashSize, int a[], int n)
    {
        for (int i=0; i<hashSize; i++)
        {
            hashTable[i] = -1;
        }
        
        for (int i=0; i<n; i++)
        {
            int hashIndex = a[i] % hashSize;
            
            int collision = 1;
            
            while (hashTable[hashIndex] != -1)
            {
            
                hashIndex = (a[i] + collision*collision) % hashSize;

                collision++;
            }

            hashTable[hashIndex] = a[i];
        }
    }
