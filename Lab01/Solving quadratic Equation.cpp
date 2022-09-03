//Name: Ravi Lahare
//Roll no: 210101086
//Date: 01-08-2022
//Que: Solving quadratic Equation => find roots of a quadratic equation ax + bx + c ; a,b,c are given  

#include <bits/stdc++.h>
using namespace std ;
int main()
{
    double a , b , c ;
    cin >> a >> b >> c ;
    if(b*b-4*a*c<0)
    {
        cout << "No Real Roots" ;
    }
    else
    {
        //using quadratic formula
        cout << ((-1)*b + sqrt(b*b-4*a*c))/(2*a) << " " << ((-1)*b - sqrt(b*b-4*a*c))/(2*a) ;
    }
    return 0 ;
}