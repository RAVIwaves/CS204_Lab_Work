//Name : Ravi Lahare
//Roll no. : 210101086
//Date : 12-09-2022
//Problem - Connected_components

#include <bits/stdc++.h>
using namespace std ;

int bfs(vector<int> v[],int n,int t,int check[])
{
    check[t] = 1 ;
    for(int i=0 ; i<v[t].size() ; i++)
    {
        if(check[v[t][i]]==0)
            bfs(v,n,v[t][i],check) ;
    }
    return 0 ;
}

int main()
{
    //variables
    int n , t=0 , ans=0 ;
    cin >> n ;
    pair<int,int> p[n*n] ;
    char c ;
    int ch ;

    //taking input
    while(1)
    {
        cin >> c ;
        ch = c ;
        if(ch==36)
            break ;
        else
        {
            p[t].first = ch - 48 ;
            cin >> c ;
            ch = c ;
            p[t].second = ch - 48 ;
            t++ ;
        }
    }

    for(int flow=1 ; flow<=t ; flow++)
    {
        vector<int> v[n] ;
        for(int i=0 ; i<flow ; i++)
        {
            v[p[i].first-1].push_back(p[i].second-1) ;
            v[p[i].second-1].push_back(p[i].first-1) ;
        }
        int check[n] ;
        for(int i=0 ; i<n ; i++)
            check[i] = 0 ;

        //counting 
        for(int i=0 ; i<n ; i++)
            if(check[i]==0)
            {
                bfs(v,n,i,check) ;
                ans++ ;
            }   
            else
                continue ;
            
        cout << ans << endl ;
        ans = 0 ;
    }   
    return 0 ;
}