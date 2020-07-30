#include<bits/stdc++.h>
using namespace std;

int fib_dp(int n, int* ar){
    
    if((n==0)||(n==1))
    return 1;
    if(ar[n]>0) //store the calculated value in array
    return ar[n];
  
        int output = fib_dp(n-1, ar)+fib_dp(n-2, ar);
        ar[n] = output;
        return output;
    
}
int main(){
    int n;
    cin>>n;
    int ar[n+1] = {0};
    cout<<fib_dp(n, ar)<<endl;
    return 0;
}
