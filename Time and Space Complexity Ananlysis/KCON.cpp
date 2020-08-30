#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

ll kadanes(int arr[], int n){
    ll current_sum = 0;
    ll max_sum = INT_MIN;
    
    for(int i=0; i<n; i++){
        current_sum += arr[i];
        
            if(current_sum>max_sum)
            max_sum = current_sum;
        
        
        
        if(current_sum<0){
            current_sum = 0;
        }
    }
    return max_sum;
}

ll maxSum(int* arr, int n, int k){
    ll max_sum_sub = kadanes(arr, n);
    if(k == 1)
    return max_sum_sub;
    ll curr_pref = 0, curr_suf = 0;
    ll best_prefx_sum = INT_MIN;
    ll best_sufx_sum = INT_MIN;
    ll total_sum=0;
    
     for(int i=0; i<n; i++){
	        curr_pref += arr[i];
	        if(curr_pref>best_prefx_sum)
	        best_prefx_sum  = curr_pref;
	    }
	    total_sum = curr_pref;
	    for(int i=n-1; i>=0; i--){
	        curr_suf += arr[i];
	        if(curr_suf>best_sufx_sum)
	        best_sufx_sum = curr_suf;
	    }
	    ll ans;
	    if(total_sum<0){
	         ans = max((best_prefx_sum + best_sufx_sum), max_sum_sub);
	        
	    }
	    else if(total_sum>=0){
	        ans = max((best_prefx_sum+best_sufx_sum+(total_sum*(k-2))), max_sum_sub);
	        
	    }
	    return ans;
}
int main(){
    int t;
    cin>>t;
    while(t--){
        int n, k;
        cin>>n>>k;
        int arr[n];
        for(int i=0; i<n; i++){
            cin>>arr[i];
        }
        ll ans = maxSum(arr, n, k);
        cout<<ans<<endl;
    }
    return 0;
}
