//Name : Ravi Lahare
//Roll no. : 210101086
//Date : 29-08-2022
//Problem - 01

#include <bits/stdc++.h>
using namespace std ;
int main()
{
    //taking input
    int n ;
    cin >> n ;
    int edge[n][n] ;
    for(int i=0 ; i<n ; i++)
    {
        for(int j=0 ; j<n ; j++)
        {
            cin >> edge[i][j] ;
        }
    }

    //checking odd vertex
    int odd_vertex = 0 ;
    for(int i=0 ; i<n ; i++)
    {
        int edge_count = 0 ;
        for(int j=0 ; j<n ; j++)
        {
            if(edge[i][j]==1)
            {
                edge_count++ ;
            }
        }
        if(edge_count%2==1) //found a odd vertex
        {
            cout << i << endl ;
            odd_vertex++ ;
        }
    }
    if(odd_vertex==0)
    {
        cout << "-1" ;
    }
    return 0 ;
}