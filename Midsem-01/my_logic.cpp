//Name : Ravi Lahare
//Roll no. : 210101086
//Date : 10-10-2022
//Problem - 01
//Algorithm - finding min element from (min elements of all sorted array)

#include <bits/stdc++.h>
#include <stdio.h>
#include <stdlib.h>
using namespace std ;
int main()
{
    //taking input and storing them into a array of vector arr[k]
    //-----------------------------------------------------------------------------
        FILE *f1 , *f2 ;
        f1 = fopen("input.txt","w") ;
        vector<int> data ;
        char c ;
        int count = 1 ;
        while(1)
        {
            c = getchar() ;
            if(c=='$')
            {
                data.push_back(count-1) ;
                count = 0 ;
            }
            else if(c=='\n')
            {
                data.push_back(count) ;
                break ;
            }
            else if(c==' ')
            {
                fprintf(f1,"%c",c) ;
                count++ ;
            }
            else
                fprintf(f1,"%c",c) ;
        }
        fclose(f1) ;

        int k = data.size() ; //total no. of sorted array

        f2 = fopen("input.txt","r") ;
        vector<int> arr[k] ;
        for(int i=0 ; i<k ; i++)
        {
            for(int j=0 ; j<data[i] ; j++)
            {
                int t ;
                fscanf(f2,"%d",&t) ;
                arr[i].push_back(t) ;
            }
        }
        for(int i=0 ; i<k ; i++)
        {
            arr[i].push_back(INT_MAX) ;  
        }
        fclose(f2) ;
    //------------------------------------------------------------

    //Calculating total no. of numbers
    int total_num = 0 ;
    for(int i=0 ; i<k ; i++)
        total_num += data[i] ;
    
    int ans[total_num] ;
    int index[k] = {0} ;

    //merging all sorted array
    //------------------------------------------------------
        for(int i=0 ; i<total_num ; i++)
        {
            int min_index = 0 ;
            int min_data = arr[0][index[0]] ;
            for(int j=0 ; j<k ; j++)
            {
                if(min_data>arr[j][index[j]])
                {
                    min_data = arr[j][index[j]] ;
                    min_index = j ;
                }
            }
            ans[i] = min_data ;
            index[min_index]++ ;
        }
    //-------------------------------------------------------

    for(int i=0 ; i<total_num ; i++)
        cout << ans[i] << " " ;
    return 0 ;
}