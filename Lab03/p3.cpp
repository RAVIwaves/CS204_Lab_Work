//Name : Ravi Lahare
//Roll no. : 210101086
//Date : 22-08-2022
//Problem - 03

#include <bits/stdc++.h>
using namespace std ;
long long findpos(long long b[],long long t,long long n)
{
    long long ans = 0 ;
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
long long find(long long b[],long long q,long long n)
{
    long long ans=0 ;
    for(long long i=0 ; i<n ; i++)
    {
        if(b[i]==-1)
        {
            continue ;
        }
        if(ans==q)
        {
            long long temp = b[i] ;
            b[i] = -1 ;
            return temp ; 
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

//returns ans of problem 2
long long p2(long long a[],long long n)
{
    long long ans = 0 ;
    long long  b[n] ;
    for(long long i=0 ; i<n ; i++)
    {
        b[i] = a[i] ;
    }
    sort(b,b+n) ;
    for(long long i=0 ; i<n ; i++)
    {
        long long t = findpos(b,a[i],n) ;
        ans += t*fact(n-i-1) ;
    } 
    return ans ;
}

int main()
{
    long long n , k ;
    cin >> n >> k ;
    long long a[n] , b[n] ;
    for(long long i=0 ; i<n ; i++)
    {
        cin >> a[i] ;
        b[i] = a[i] ;
    }
    k += p2(a,n) ;
    k-- ;
    if(k>fact(n)-1)
    {
        cout << "-1" ;
        exit(0) ;
    }
    sort(b,b+n) ;
    for(long long i=n-1 ; i>0 ; i--)
    {
        long long q = k/fact(i) ;
        k -= q*fact(i) ;
        cout << find(b,q,n) << endl ;
    }
    long long q = k/fact(0) ;
    cout << find(b,q,n) ;
    return 0 ;
}