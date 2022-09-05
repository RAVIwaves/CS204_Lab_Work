//Name: Ravi Lahare
//Roll no: 210101086
//Date: 05-09-2022
//Que: Problem - 03

#include <bits/stdc++.h>
using namespace std ;

int check(int done[],int n) ;
int findi(vector<int> path[],int done[],int n,int r,queue<int> q) ;

int main()
{
    
    //taking no. of vertex
    int n ;
    cin >> n ;
    vector<int> path[n] ;
    int hash_count = 0 ;

    //taking input
    int edge[n][n] ;
    for(int i=0 ; i<n ; i++)
    {
        for(int j=0 ; j<n ; j++)
        {
            cin >> edge[i][j] ;
            if(edge[i][j]==1)
                path[i].push_back(j) ;
        }
    }

    //logic
    int done[n] ;
    for(int i=1 ; i<n ; i++)
        done[i] = 0 ;
    queue<int> q ;
    findi(path,done,n,0,q) ;
    while(1)
    {
        int t = check(done,n) ;
        if(t==-1)
            break ;
        else
        {
            done[t]= 1 ;
            findi(path,done,n,t,q) ;
        }
    }
    return 0 ;
}

int findi(vector<int> path[],int done[],int n,int r,queue<int> q)
{
    q.push(r) ;
    while(1)
    {
        if(q.size()==0)
            break ;
        cout << q.front() << " ";
        done[q.front()] = 1 ;
        for(int i=0 ; i<path[q.front()].size() ; i++)
            if(done[path[q.front()][i]]==0)
            {
                done[path[q.front()][i]] = 1 ;
                q.push(path[q.front()][i]) ;
            }
        q.pop();
    }
    return 0 ;
}

int check(int done[],int n)
{
    for(int i=0 ; i<n ; i++)
        if(done[i]==0)
            return i ;
    return -1 ;
}
