//Name: Ravi Lahare
//Roll no: 210101086
//Date: 05-09-2022
//Que: Problem - 01

#include <bits/stdc++.h>
using namespace std ;

int find(int n,vector<int> path[],int done[]) ;
int check(int done[],int n) ;

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
    done[0] = 1 ;
    cout << "0 " ;
    find(0,path,done) ;
    while(1)
    {
        int t = check(done,n) ;
        if(t==-1)
            break ;
        else
        {
            cout << t <<" " ;
            done[t]= 1 ;
            find(t,path,done) ;
        }
    }
    return 0 ;
}

int find(int n,vector<int> path[],int done[])
{
    sort(path[n].begin(),path[n].end()) ;
    for(int i=0 ; i<path[n].size() ; i++)
    {
        if(done[path[n][i]]==0)
        {
            done[path[n][i]] = 1 ;
            cout << path[n][i] << " " ;
            find(path[n][i],path,done) ;
        }
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
