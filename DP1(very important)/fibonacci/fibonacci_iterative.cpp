#include<bits/stdc++.h>
using namespace std;

int fib_dp(int n){
    int ar[n+1] = {0};
  ar[0] = 1;
  ar[1] = 1;
  for(int i=2; i<=n; i++){
      ar[i] = ar[i-1] + ar[i-2];
  }
  int output = ar[n];
 
  return output;
}
int main(){
    int n;
    cin>>n;
    cout<<fib_dp(n)<<endl;
    return 0;
}
