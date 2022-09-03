//Name : Ravi Lahare
//Roll no. : 210101086
//Date : 29-08-2022
//Problem - 05

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
    int ans[n1+n2] ;
    if(n1>=n2)
    {
        int sub_sum[n2][n1+n2] ;
        for(int i=0 ; i<n2 ; i++)
        {
            for(int j=0 ; j<n1+n2 ; j++)
            {
                sub_sum[i][j] = 0 ;
            }
        }
        for(int i=0 ; i<n2 ; i++)
        {
            int carry = 0 ;
            for(int j=0 ; j<n1 ; j++)
            {
                sub_sum[i][j+i] = (d2[i]*d1[j] + carry)%10 ;
                carry = (d2[i]*d1[j] + carry)/10 ;
            }
            sub_sum[i][n1+i] = carry ;
        }
        int carry = 0 ;
        for(int i=0 ; i<n1+n2 ; i++)
        {
            int column_sum = 0 ;
            for(int j=0 ; j<n2 ; j++)
            {
                column_sum += sub_sum[j][i] ;
            }
            ans[i] = (column_sum + carry)%10 ;
            carry =  (column_sum + carry)/10 ;
        }
        reverse(ans,ans+n1+n2) ;
        int start ;
        for(start=0 ; start<n1+n2 ; start++)
        {
            if(ans[start]!=0)
            {
                break ;
            }
        }
        for( ; start<n1+n2 ; start++)
        {
            cout << ans[start] ;
        }
    }
    else
    {
        int sub_sum[n1][n2+n1] ;
        for(int i=0 ; i<n1 ; i++)
        {
            for(int j=0 ; j<n2+n1 ; j++)
            {
                sub_sum[i][j] = 0 ;
            }
        }
        for(int i=0 ; i<n1 ; i++)
        {
            int carry = 0 ;
            for(int j=0 ; j<n2 ; j++)
            {
                sub_sum[i][j+i] = (d1[i]*d2[j] + carry)%10 ;
                carry = (d1[i]*d2[j] + carry)/10 ;
            }
            sub_sum[i][n2+i] = carry ;
        }
        int carry = 0 ;
        for(int i=0 ; i<n2+n1 ; i++)
        {
            int column_sum = 0 ;
            for(int j=0 ; j<n1 ; j++)
            {
                column_sum += sub_sum[j][i] ;
            }
            ans[i] = (column_sum + carry)%10 ;
            carry =  (column_sum + carry)/10 ;
        }
        reverse(ans,ans+n2+n1) ;
        int start ;
        for(start=0 ; start<n2+n1 ; start++)
        {
            if(ans[start]!=0)
            {
                break ;
            }
        }
        for( ; start<n2+n1 ; start++)
        {
            cout << ans[start] ;
        }
    }
    return 0 ;    
}