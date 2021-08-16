#include <bits/stdc++.h>

using namespace std; 

double myPow(double x, int n) {
    double result=1;
    double a=x;
    int b=abs(n);
    while(b>0){
        if(b%2==1) result*=a;
        a*=a;
        b/=2;
    }
    if(n<0) return 1/result;
    return result;
}