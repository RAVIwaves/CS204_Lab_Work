//Name : Ravi Lahare
//Roll no. : 210101086
//Date : 22-08-2022
//Problem - 01

#include <iostream>
#include<algorithm>
using namespace std ;

//function for swaping two numbers in a array
void swap(int a[],int i,int j)
{
    int temp = a[i] ;
    a[i] = a[j] ;
    a[j] = temp ;
    return ;
}

//function for finding number for swaping
int find(int a[],int s,int n)
{
    int ans = s ;
    for(int j=s ; j<n ; j++)
    {
        if(a[j]>a[s-1]&&a[j]<a[s])
        {
            ans = j ;
        }
    }
    return ans ;
}

//main function
int main()
{
    int n ;
    cin >> n ;
    int a[n] ;
    for(int i=0 ; i<n ; i++)
    {
        cin >> a[i] ;    
    }
    for(int i=n-1 ; i>0 ; i--)
    {
        if(a[i-1]<a[i])
        {
            int start = find(a,i,n) ;
            swap(a,i-1,start) ;
            sort(a+i,a+n) ;
            for(int i=0 ; i<n-1 ; i++)
            {
                cout << a[i] << endl ;
            }
            cout << a[n-1] ;
            return 0 ;
        }
    }
    cout << -1 ;
    return 0 ;
}