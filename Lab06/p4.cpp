//Name: Ravi Lahare
//Roll no: 210101086
//Date: 05-09-2022
//Que: Problem - 04

#include <bits/stdc++.h>
using namespace std ;

int num(char edge) ;
int check(int done[],int n) ;
int findi(vector<int> path[],int done[],int n,int r,queue<int> q) ;

int main()
{
    //taking no. of vertex
    int n ;
    cin >> n ;

    //taking input
    vector<int> path[n] ;
    int hash_count = 0 ;
    char edge ;
    while(hash_count<n)
    {
        cin >> edge ;
        if(edge=='#')
        {
            hash_count++ ;
        }
        else
        {
            path[hash_count].push_back(num(edge)) ;
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

int num(char edge)
{
    switch(edge)
    {
        case '0' :
            return 0 ; break ;
        case '1' :
            return 1 ; break ;
        case '2' :
            return 2 ; break ;
        case '3' :
            return 3 ; break ;
        case '4' :
            return 4 ; break ;
        case '5' :
            return 5 ; break ;
        case '6' :
            return 6 ; break ;
        case '7' :
            return 7 ; break ;
        case '8' :
            return 8 ; break ;
        case '9' :
            return 9 ; break ;
        default :
            return -1 ;
    }
}