//Name : Ravi Lahare
//Roll no. : 210101086
//Date : 22-08-2022
//Problem - 02

#include <bits/stdc++.h>
using namespace std ;
long long findpos(long long b[],long long t,long long n)
{
    int ans = 0 ;
    for(long long i=0 ; i<n ; i++)
    {
        if(b[i]==-1)
        {
            continue ;
        }
        if(b[i]==t)
        {
            b[i] = -1 ;
            return ans ;
        }
        ans++ ;
    }
    return 0 ;
}

//function for finding factorial
long long fact(long long n)
{
    long long ans = 1 ;
    for(long long i=2 ; i<=n ; i++)
    {
        ans *= i ;
    }
    return ans ;
}

int main()
{
    long long n , ans = 0 ;
    cin >> n ;
    long long a[n] , b[n] ;
    for(long long i=0 ; i<n ; i++)
    {
        cin >> a[i] ;
        b[i] = a[i] ;
    }
    sort(b,b+n) ;
    for(long long i=0 ; i<n ; i++)
    {
        long long t = findpos(b,a[i],n) ;
        ans += t*fact(n-i-1) ;
    } 
    cout << ans+1 ;
    return 0 ;
}