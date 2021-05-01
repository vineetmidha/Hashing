/*
Task Completion
You are given two integers N and M and an array of numbers of length M. Here, N represents the total number of tasks from 1 till N assigned to a group of 5 students. Out of these 5 students, 3 have completed M number of tasks of their choices and have left the group. Tasks completed by these students are represented by the given array. Now, the remaining tasks have to be completed by the remaining two students. They decided to complete the remaining tasks in an alternative way. First of the remaining tasks will be completed by s1. Second will be done by s2 and so on. You have to find out the tasks performed by both of them. 

Input:
N, M
M distinct numbers

Output:
2 lines containing space-separated numbers.
Numbers in the first line represent the tasks completed by s1.
Numbers in the first line represent the tasks completed by s2.

Example:
15 6
2 5 6 7 9 4

Output:
1 => 1 3 11 13 15 
2 => 8 10 12 14 
*/

void displayVector(vector<int> a){
    for (auto i: a){
        cout << i << " ";
    }
    cout << endl;
}

void solve(int test=0)
{
    int n, m;
    cin >> n >> m;

    vector<int> a(m);

    for (int i=0; i<m; i++)
    {
        cin >> a[i];
    }

    set<int> completed (a.begin(), a.end());

    map<int, vector<int>> ans;

    int person = 0;

    for (int i=1; i<=n; i++)
    {
        if (completed.count(i) == 0)
        {
            ans[person+1].push_back(i);
            person = !person;            
        }
    }

    for (auto pair: ans)
    {
        cout << pair.first << " => ";

        displayVector(pair.second);
    }

}



