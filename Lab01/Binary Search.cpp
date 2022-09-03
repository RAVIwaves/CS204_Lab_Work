//Name: Ravi Lahare
//Roll no: 210101086
//Date: 01-08-2022
//Que: Binary Search => Finding a number in a sorted array using binary search

// N -> size of array
// nums[] -> arry
// K -> No. of questions
// T[] -> numbers we have to check

#include <bits/stdc++.h>
using namespace std ;
int find(int a,int arr[],int x,int y) ;
int main()
{
    int N , K ;
    cin >> N >> K ;
    int nums[N] , T[K] ;
    for(int i=0 ; i<N ; i++)
    {
        cin >> nums[i] ;
    }
    for(int i=0 ; i<K ; i++)
    {
        cin >> T[i] ;
    }
    for(int i=0 ; i<K ; i++)
    {
        cout << find(T[i],nums,0,N-1) << endl ;
    }
    return 0 ;
}

int find(int a,int arr[],int x,int y)
{
    if(arr[(y+x)/2]==a)
    {
        return 1 ;
    }
    else if(x>y)
    {
        return 0 ;
    }
    else if(arr[(y+x)/2]<a)
    {
        return find(a,arr,((y+x)/2)+1,y) ;
    }
    else
    {
        return find(a,arr,x,((y+x)/2)-1) ;
    }
}