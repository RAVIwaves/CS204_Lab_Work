//Name : Ravi Lahare
//Roll no. : 210101086
//Date : 29-08-2022
//Problem - 03

#include <bits/stdc++.h>
using namespace std ;
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
    reverse(d1,d1+n1) ;
    reverse(d2,d2+n2) ;
    int sum[max(n1,n2)+1] ;
    int carry = 0 ;
    if(n1==n2)
    {
        for(int i=0 ; i<max(n1,n2) ; i++)
        {
            sum[i] = (d1[i] + d2[i] + carry)%10 ;
            carry = (d1[i] + d2[i] + carry)/10 ;
        }
        if(carry==1)
        {
            sum[max(n1,n2)] = 1 ;
        }
        else
        {
            sum[max(n1,n2)] = 0 ;
        }
        reverse(sum,sum+max(n1,n2)+1) ;
        int start ;
        for(start=0 ; start<max(n1,n2)+1 ; start++)
        {
            if(sum[start]!=0)
            {
                break ;
            }
        }
        for( ; start<max(n1,n2)+1 ; start++)
        {
            cout << sum[start] ;
        }
    }
    else if(n1>n2)
    {
        for(int i=0 ; i<min(n1,n2) ; i++)
        {
            sum[i] = (d1[i] + d2[i] + carry)%10 ;
            carry = (d1[i] + d2[i] + carry)/10 ;
        }
        for(int i=min(n1,n2) ; i<max(n1,n2) ; i++)
        {
            sum[i] = (d1[i] + carry)%10 ;
            carry = (d1[i] + carry)/10 ;
        }
        if(carry==1)
        {
            sum[max(n1,n2)] = 1 ;
        }
        else
        {
            sum[max(n1,n2)] = 0 ;
        }
        reverse(sum,sum+max(n1,n2)+1) ;
        int start ;
        for(start=0 ; start<max(n1,n2)+1 ; start++)
        {
            if(sum[start]!=0)
            {
                break ;
            }
        }
        for( ; start<max(n1,n2)+1 ; start++)
        {
            cout << sum[start] ;
        }
    }
    else
    {
        for(int i=0 ; i<min(n1,n2) ; i++)
        {
            sum[i] = (d1[i] + d2[i] + carry)%10 ;
            carry = (d1[i] + d2[i] + carry)/10 ;
        }
        for(int i=min(n1,n2) ; i<max(n1,n2) ; i++)
        {
            sum[i] = (d2[i] + carry)%10 ;
            carry = (d2[i] + carry)/10 ;
        }
        if(carry==1)
        {
            sum[max(n1,n2)] = 1 ;
        }
        else
        {
            sum[max(n1,n2)] = 0 ;
        }
        reverse(sum,sum+max(n1,n2)+1) ;
        int start ;
        for(start=0 ; start<max(n1,n2)+1 ; start++)
        {
            if(sum[start]!=0)
            {
                break ;
            }
        }
        for( ; start<max(n1,n2)+1 ; start++)
        {
            cout << sum[start] ;
        }
    }
    return 0 ;
}