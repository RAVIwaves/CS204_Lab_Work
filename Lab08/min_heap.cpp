//Name : Ravi Lahare
//Roll no. : 210101086
//Date : 26-09-2022
//Problem - Min_Heap

#include <bits/stdc++.h>
using namespace std ;

int distance(int x,int y) ;
void heapify(int heap[],int d[],int n,int i) ;
void min_heap(int heap[],int d[],int n) ;

int main()
{
    //taking no. of points
    int n ;
    cin >> n ;

    //taking coordinates
    pair<int,int> coordinate[n] ;
    for(int i=0 ; i<n ; i++)
    {
        cin >> coordinate[i].first ;
        cin >> coordinate[i].second ;
    }

    //storing square of distance
    int d[n] ;
    for(int i=0 ; i<n ; i++)
        d[i] = distance(coordinate[i].first,coordinate[i].second) ;

    //creating heap
    int heap[n] ;
    for(int i=0 ; i<n ; i++)
        heap[i] = i ;
    min_heap(heap,d,n) ;

    //printing points
    while(n>0)
    {
        cout << coordinate[heap[0]].first << " " << coordinate[heap[0]].second << "\n" ;
        swap(heap[0],heap[n-1]) ;
        n-- ;
        heapify(heap,d,n,0) ;
    }
    return 0 ;
}

// function for calculating square of distance from origin
int distance(int x,int y)
{
    return x*x + y*y ;
}

//function for heapify for min heap
void heapify(int heap[],int d[],int n,int i)
{
    if(i>(n/2-1))
        return ;
    int child1 = 2*i+1 , child2 = 2*i+2 ;
    if(2*i+2>=n)
        child2 = 2*i+1 ;
    int swap_index = child1 ;
    if(d[heap[child2]]<d[heap[child1]])
        swap_index = child2 ;
    if(d[heap[swap_index]]<d[heap[i]])
    {
        swap(heap[swap_index],heap[i]) ;
        heapify(heap,d,n,swap_index) ;
    }
    return ;
}

//function for creating min heap
void min_heap(int heap[],int d[],int n)
{
    for(int i=n/2-1 ; i>=0 ; i--)
        heapify(heap,d,n,i) ;
    return ;
}
