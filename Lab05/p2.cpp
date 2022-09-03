//Name : Ravi Lahare
//Roll no. : 210101086
//Date : 29-08-2022
//Problem - 02

#include <bits/stdc++.h>
using namespace std ;
int main()
{
    //taking no. of vertex
    int n ;
    cin >> n ;

    //taking input + logic + output
    int hash_count = 0 ;
    int edge_count = 0 ;
    int having_odd_vertex = 0 ;
    char edge ;
    while(hash_count<n)
    {
        cin >> edge ;
        if(edge=='#')
        {
            hash_count++ ;
            if(edge_count%2==1) //found a odd vertex
            {
                having_odd_vertex = 1 ;
                edge_count = 0 ;
                cout << hash_count - 1 << endl ;
            }
        }
        else
        {
            edge_count++ ;
        }
    }
    if(having_odd_vertex==0)
    {
        cout << "-1" ;
    }
    return 0 ;
}