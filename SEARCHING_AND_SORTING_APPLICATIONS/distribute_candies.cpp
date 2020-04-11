#include<bits/stdc++.h>
using namespace std;

bool check(int students, int ar[], int n, int chocolate){
    int count=0;
    
    for(int i=0; i<n; i++){
        count += (ar[i]/chocolate);
        if(count == students)
        return true;
    }
    
    return false;
    
}
int main() {

	// Write your code here
    int t;
    cin>>t;
    while(t--){
        int n, students;
        cin>>n>>students;
        int ar[n];
        int max=0;
        for(int i=0; i<n; i++){
            cin>>ar[i];
            if(ar[i]>max)
                ar[i]=max;
        }
       int start = 0;
        int end = max;
        int ans =-1;
        while(start<=end){
           int mid = start + (end-start)/2;
            if(check(students, ar, n, mid)){
                ans = mid;
                start = mid+1;
            }
            else{
                end=mid-1;
            }
        }
        cout<<ans<<endl;
    }
          return 0;
}
