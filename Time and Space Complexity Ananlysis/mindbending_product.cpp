#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

void mindbending_product_sub(int* ar, int n){
    int ans[n];
    ans[0] = 1;
    for(int i=1; i<n; i++){
        ans[i] = ans[i-1]*ar[i-1];
    }
    
    int right = 1;
    for(int j=n-2; j>=0; j--){
        right *= ar[j+1];
        ans[j] *= right;
    }
    
    for(int i=0; i<n; i++){
        cout<<ans[i]<<" ";
    }
}


int main(){
    int n;
    cin>>n;
    int ar[n];
    for(int i=0; i<n; i++){
        cin>>ar[i];
    }
    mindbending_product_sub(ar, n);
    return 0;
}
