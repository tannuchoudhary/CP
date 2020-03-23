#include<bits/stdc++.h>
using namespace std;

int max_product(int ar[], int n){
    int maxm = INT_MIN;
    int max_ending_here=1;
    int min_ending_here=1;
    for(int i=0; i<n; i++){
    if(ar[i]>0){
        max_ending_here *= ar[i];
        min_ending_here = min(1, min_ending_here*ar[i]);
        
        }
        
        if(ar[i]<0){
            int temp=max_ending_here;
            max_ending_here = max(1, min_ending_here*ar[i]);
            min_ending_here = temp*ar[i];
             
        }
        
        if(ar[i]==0){
            max_ending_here = 1;
            min_ending_here = 1;
            
        }
        
        if(max_ending_here>maxm)
        maxm=max_ending_here;
    }
    return maxm;
}
int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        int ar[n];
        for(int i=0; i<n; i++){
            cin>>ar[i];
        }
        int ans = max_product(ar, n);
        cout<<ans;
    }
    return 0;
}
