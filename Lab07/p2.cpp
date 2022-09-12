//Name : Ravi Lahare
//Roll no. : 210101086
//Date : 12-09-2022
//Problem - pruferCode

#include <bits/stdc++.h>
using namespace std ;

int main()
{
    //variables
    int n , t=0 ;
    cin >> n ;
    pair<int,int> p[n*n] ;
    vector<int> ans , edge[n] ;
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
            p[t].first = ch - 49 ;
            cin >> c ;
            ch = c ;
            p[t].second = ch - 49 ;
            edge[p[t].first].push_back(p[t].second) ;
            edge[p[t].second].push_back(p[t].first) ;
            t++ ;
        }
    }

    //caculating order
    int order[n] ;
    for(int i=0 ; i<n ; i++)
        order[i] = 0 ;

    for(int i=0 ; i<t ; i++)
    {
        order[p[i].first]++ ;
        order[p[i].second]++ ;
    }

    for(int k=0 ; k<n-2 ; k++)
    {
        for(int i=0 ; i<n ; i++)
        {
            if(order[i]==1)
            {
                order[i] = 0 ;
                for(int j=0 ; j<edge[i].size() ; j++)
                {
                    if(order[edge[i][j]]>1)
                    {
                        ans.push_back(edge[i][j]+1) ;
                        order[edge[i][j]]-- ;
                        break ;
                    }
                }
                break ;
            }
        }
    }
    for(int i=0 ; i<ans.size() ; i++)   
        cout << ans[i] << " " ;
    return 0 ;
}