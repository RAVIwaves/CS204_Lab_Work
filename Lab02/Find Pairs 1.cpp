//Name: Ravi Lahare
//Roll no: 210101086
//Date: 08-08-2022
//Que: Find Pairs
//Time Complexity: O(n^2)
//using brute force

#include <bits/stdc++.h>
using namespace std ;
int find(int t,int arr[],int n)
{
    for(int i=0 ; i<n-1 ; i++)
        for(int j=i+1 ; j<n ; j++)
            if(arr[i]+arr[j]==t)
            {
                cout << i << " " << j << endl ;
                return 0 ;
            }
    cout << "0" << endl ;
    return 0 ;
}
int main()
{
    int n , m ;
    cin >> n ;
    int arr[n] ;
    for(int i=0 ; i<n ; i++)
        cin >> arr[i] ;
    cin >> m ;
    int t[m] ;
    for(int i=0 ; i<m ; i++)
    {
        cin >> t[i] ;
        find(t[i],arr,n) ;
    }
    return 0 ;
}