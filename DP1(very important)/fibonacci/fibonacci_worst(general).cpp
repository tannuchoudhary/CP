/*Here i am going to write a general code for fibonacci series*/

#include<bits/stdc++.h>
using namespace std;

int fib(int n){
    if(n==0 || n==1)
    return 1;
    else
    return (fib(n-1)+fib(n-2));
}
int main(){
    int n;
    cin>>n;
    cout<<fib(n)<<endl;
    return 0;
}
