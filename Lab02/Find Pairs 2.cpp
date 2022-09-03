//Name: Ravi Lahare
//Roll no: 210101086
//Date: 08-08-2022
//Que: Find Pairs
//Time Complexity: O(n.log(n))
//first sort then finding pairs from two ends

#include <bits/stdc++.h>
using namespace std ;

//function for finding original location of element
int find(int arr[],int n,int t)
{
    for(int i=0 ; i<n ; i++)
        if(arr[i]==t)
            return i ;
    return 0 ;
}

int main()
{
    int n , m ;
    cin >> n ;
    int arr[n] , sorted_arr[n] ;

    //making a copy of original array
    for(int i=0 ; i<n ; i++)
    {
        cin >> arr[i] ;
        sorted_arr[i] = arr[i] ;
    }

    sort(sorted_arr,sorted_arr+n) ;
    cin >> m ;
    int t[m] ;
    for(int i=0 ; i<m ; i++)
    {
        pair<int,int> dude[n/2] ; int k=0 ;
        cin >> t[i] ;
        int a=0 , b=n-1 ;

        //finding all pairs
        while(1)
        {
            if(a>=b)
                break ;
            if(sorted_arr[a]+sorted_arr[b]==t[i])
            {
                dude[k].first = sorted_arr[a] ;
                dude[k].second = sorted_arr[b] ;
                a++ ;
                b-- ;
                k++ ;
            }
            else if(sorted_arr[a]+sorted_arr[b]<t[i])
                a++ ;
            else if(sorted_arr[a]+sorted_arr[b]>t[i])
                b-- ;
        }

        if(k==0)
            cout << "0" << endl ;
        else
        {
            //finding original location of these pairs
            for(int s=0 ; s<k ; s++)
            {
                int a1 = find(arr,n,dude[s].first) ;
                int a2 = find(arr,n,dude[s].second) ;
                dude[s].first = min(a1,a2) ;
                dude[s].second = max(a1,a2) ;
            }
            sort(dude,dude+k) ;

            //printing pair with least index
            cout << dude[0].first << " " << dude[0].second << endl ;
        }
    }
    return 0 ;
}