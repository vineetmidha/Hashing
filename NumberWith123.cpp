
// https://practice.geeksforgeeks.org/problems/numbers-containing-1-2-and-32555/0/?track=DSASP-Hashing&batchId=155

bool isValid(int n)
{
    bool flag=true;
    
    while (n) 
    {
        int d = n % 10;
        
        if (d!=1 && d!=2 && d!=3) {
            flag = false;
            break;
        }

        n/=10;
    }
    
    return flag;
}
void findAll() {
    queue<int> q;
    
    q.push(1);
    q.push(2);
    q.push(3);
    
    while (!q.empty())
    {
        int i = q.front();
        
        q.pop();
        
        mp[i] = 1;
        
        if (i < 1e6)
        {
            q.push(i*10+1);
            q.push(i*10+2);
            q.push(i*10+3);
        }
        
        i++;
    }
}
