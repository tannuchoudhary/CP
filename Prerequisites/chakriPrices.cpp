#include<bits/stdc++.h>
using namespace std;
int main() {

	// Write your code here
    int n, diff;
    cin>>n;
    int a[n], m=0;
    for(int i=0; i<n; i++){
        cin>>a[i];
    }
    for(int j=0; j<(n-1); j++){
        for(int k=(j+1); k<n; k++){
            diff = a[k]-a[j];
            if(diff>m)
                m=diff;
        }
    }
    cout<<m;
    return 0;
}
