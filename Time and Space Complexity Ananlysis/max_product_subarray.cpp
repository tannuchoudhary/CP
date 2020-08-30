#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int max_product_sub(int* ar, int n){
    int ans = 1;
    int max_ending_here=1;
    int min_ending_here = 1;
    for(int i=0; i<n; i++){
        if(ar[i]>0){
            max_ending_here = max_ending_here*ar[i];
            min_ending_here = min(1, (min_ending_here*ar[i]));
            ans = max(ans, max_ending_here);
        }
        else if(ar[i]>0){
            int temp = max_ending_here;
            max_ending_here = max(1, (min_ending_here*ar[i]));
            min_ending_here = temp*ar[i];
            ans = max(ans, max_ending_here);
        }
        else if(ar[i] == 0){
            max_ending_here = 1;
            min_ending_here = 1;
        }
    }
    return ans;
}


int main(){
    int n;
    cin>>n;
    int ar[n];
    for(int i=0; i<n; i++){
        cin>>ar[i];
    }
    cout<<max_product_sub(ar, n)<<endl;
    return 0;
}
