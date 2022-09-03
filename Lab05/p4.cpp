//Name : Ravi Lahare
//Roll no. : 210101086
//Date : 29-08-2022
//Problem - 04

#include <bits/stdc++.h>
using namespace std ;
int find_max(int d1[],int d2[],int n1,int n2)
{
    if(n1>n2)
    {
        return 1 ;
    }
    else if(n2>n1)
    {
        return 0 ;
    }
    else
    {
        for(int i=0 ; i<n1 ; i++)
        {
            if(d1[i]>d2[i])
            {
                return 1 ;
            }
            else if(d1[i]<d2[i])
            {
                return 0 ;
            }
        }
        return -1 ;
    }
}
int main()
{
    int n1 , n2 ;
    cin >> n1 >> n2 ;
    int d1[n1] , d2[n2] ;
    for(int i=0 ; i<n1 ; i++)
    {
        cin >> d1[i] ;
    }
    for(int i=0 ; i<n2 ; i++)
    {
        cin >> d2[i] ;
    }
    int is_d1_max = find_max(d1,d2,n1,n2) ;
    if(is_d1_max==-1)
    {
        cout << "0" ;
    }
    else if(is_d1_max==1)
    {
        reverse(d1,d1+n1) ;
        reverse(d2,d2+n2) ;
        int ans[max(n1,n2)] ;
        for(int i=0 ; i<min(n1,n2) ; i++)
        {
            if(d1[i]>=d2[i])
            {
                ans[i] = d1[i] - d2[i] ;
            }
            else
            {
                ans[i] = d1[i] - d2[i] + 10 ;
                d1[i+1]-- ;
            }
        }
        for(int i=min(n1,n2) ; i<max(n1,n2) ; i++)
        {
           ans[i] = d1[i] ;
        }
        reverse(ans,ans+max(n1,n2)) ;
        int start ;
        for(start=0 ; start<max(n1,n2) ; start++)
        {
            if(ans[start]!=0)
            {
                break ;
            }
        }
        for( ; start<max(n1,n2) ; start++)
        {
            cout << ans[start] ;
        }
    }
    else
    {
        reverse(d1,d1+n1) ;
        reverse(d2,d2+n2) ;
        int ans[max(n1,n2)] ;
        for(int i=0 ; i<min(n1,n2) ; i++)
        {
            if(d2[i]>=d1[i])
            {
                ans[i] = d2[i] - d1[i] ;
            }
            else
            {
                ans[i] = d2[i] - d1[i] + 10 ;
                d2[i+1]-- ;
            }
        }
        for(int i=min(n1,n2) ; i<max(n1,n2) ; i++)
        {
           ans[i] = d2[i] ;
        }
        reverse(ans,ans+max(n1,n2)) ;
        int start ;
        for(start=0 ; start<max(n1,n2) ; start++)
        {
            if(ans[start]!=0)
            {
                break ;
            }
        }
        for( ; start<max(n1,n2) ; start++)
        {
            cout << ans[start] ;
        }
    }
    return 0 ;
}