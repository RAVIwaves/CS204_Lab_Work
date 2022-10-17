#include <bits/stdc++.h>
using namespace std ;
int main()
{
   //taking input
   int n ;
   cin >> n ;
   int s[n] , f[n] ;
   for(int i=0 ; i<n ; i++)
   	cin >> s[i] >> f[i] ;
   
   //storing machine changing time
   pair<int,int> time[2*n] ;
   for(int i=0 ; i<n ; i++)
   {
     	time[i*2].first = s[i] ;
     	time[i*2].second = 1 ;
     	time[i*2+1].first = f[i] ;
     	time[i*2+1].second = -1 ;
   }
   sort(time,time+2*n) ;
   
   //finding ans
   int ans=0 , temp_sum=0 ;
   for(int i=0 ; i<2*n ; i++)
   {
      temp_sum += time[i].second ;
      ans = max(ans,temp_sum) ;
   }
   	
   //printing ans
   cout << ans ;
   return 0 ;
}