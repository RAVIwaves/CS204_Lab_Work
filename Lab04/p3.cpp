//Not Completed

//Name : Ravi Lahare
//Roll no. : 210101086
//Date : 27-08-2022
//Problem - 03

#include <bits/stdc++.h>
using namespace std ;
int main()
{
    //taking input
    int n , ans = 0 ;
    cin >> n ;
    int edge[n][n] ;
    for(int i=0 ; i<n ; i++)
    {
        for(int j=0 ; j<n ; j++)
        {
            cin >> edge[i][j] ;
        }
    }

    //storing odd vertex and counting the no. of odd vertex
    int odd_vertex[n] ;
    int odd_vertex_count = 0 ;
    for(int i=0 ; i<n ; i++)
    {
        int edge_count = 0 ;
        for(int j=0 ; j<n ; j++)
        {
            if(edge[i][j]==1)
            {
                edge_count++ ;
            }
        }
        if(n%2==0 && edge_count==n-1)
        {
            cout << "-1" ;
            return 0 ;
        }
        if(edge_count%2==1) //found a odd vertex
        {
            odd_vertex[odd_vertex_count] = i ;
            odd_vertex_count++ ;
        }
    }

    //logic + output
    if(odd_vertex_count==0)
    {
        cout << "0" ;
        return 0 ;
    }
    else if(odd_vertex_count%2==1)
    {
        cout << "-1" ;
        return 0 ;
    }
    else
    {
        int can_be_solve[odd_vertex_count] ;
        for(int i=0 ; i<odd_vertex_count ; i++)
        {
            can_be_solve[i] = 0 ;
        }

        //1st try to solve
        for(int i=0 ; i<odd_vertex_count ; i++)
        {
            for(int j=0 ; j!=i && j<odd_vertex_count ; j++)
            {
                if(can_be_solve[i]==0 && can_be_solve[j]==0 && edge[odd_vertex[i]][odd_vertex[j]]==0)
                {
                    can_be_solve[i]=1 ;
                    can_be_solve[j]=1 ; 
                    edge[odd_vertex[i]][odd_vertex[j]]=1 ;
                    edge[odd_vertex[j]][odd_vertex[i]]=1 ;
                    ans++ ;
                }
            }
        }
        int all_one = 1 ;
        for(int i=0 ; i<odd_vertex_count ; i++)
        {
            if(can_be_solve[i]==0)
            {
                all_one = 0 ;
                break ;
            }
        }
        if(all_one==1)
        {
            cout << ans ;
            return 0 ;
        }
        else
        {
            //2nd try to solve
            for(int i=0 ; i<odd_vertex_count ; i++)
            {
                for(int j=0 ; j!=i && j<odd_vertex_count ; j++)
                {
                    if(can_be_solve[i]==0 && can_be_solve[j]==0)
                    {
                        for(int k=0 ; k<n && k!=odd_vertex[i] && k!=odd_vertex[j] ; k++)
                        {
                            if(edge[k][odd_vertex[i]]==0 && edge[k][odd_vertex[j]]==0)
                            {
                                can_be_solve[i]=1 ;
                                can_be_solve[j]=1 ; 
                                edge[k][odd_vertex[j]]=1 ;
                                edge[k][odd_vertex[i]]=1 ;
                                edge[odd_vertex[i]][k]=1 ;
                                edge[odd_vertex[j]][k]=1 ;
                                ans+= 2 ;
                            }
                        }
                    }
                }
            }
            int all_one = 1 ;
            for(int i=0 ; i<odd_vertex_count ; i++)
            {
                if(can_be_solve[i]==0)
                {
                    all_one = 0 ;
                    break ;
                }
            }
            if(all_one==1)
            {   
                cout << ans ;
                return 0 ;
            }
            else
            {
                //3rd try to solve
                for(int i=0 ; i<odd_vertex_count ; i++)
                {
                    for(int j=0 ; j!=i && j<odd_vertex_count ; j++)
                    {
                        if(can_be_solve[i]==0 && can_be_solve[j]==0)
                        {
                            for(int k=0 ; k<n && k!=odd_vertex[i] && k!=odd_vertex[j] ; k++)
                            {
                                for(int k2=0 ; k2<n && k2!=odd_vertex[i] && k2!=odd_vertex[j] && k2!=k ; k++)
                                {
                                    if(edge[k][k2]==0 && edge[k][odd_vertex[i]]==0 && edge[k2][odd_vertex[j]]==0)
                                    {
                                        can_be_solve[i]=1 ;
                                        can_be_solve[j]=1 ; 
                                        edge[k2][odd_vertex[j]]=1 ;
                                        edge[odd_vertex[j]][k2]=1 ;
                                        edge[k][odd_vertex[i]]=1 ;
                                        edge[odd_vertex[i]][k]=1 ;
                                        edge[k][k2]=1 ;
                                        edge[k2][k]=1 ;
                                        ans+= 3 ;
                                    }
                                }
                            }

                        }
                    }
                    int all_one = 1 ;
                    for(int i=0 ; i<odd_vertex_count ; i++)
                    {
                        if(can_be_solve[i]==0)
                        {
                            all_one = 0 ;
                            break ;
                        }
                    }
                    if(all_one==1)
                    {   
                        cout << ans ;
                        return 0 ;
                    }
                    else
                    {
                    cout << "-1" ;
                    return 0 ;
                    }
                }
            }
        }
    }
}