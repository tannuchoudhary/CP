

#include<bits/stdc++.h>
using namespace std;




long long merging(int A[], int left, int mid, int right){
   
    int i=left, j=mid, k=0;
    int temp[right-left+1];
    long long count=0;
    while(i<mid && j<=right){
        if(A[i]<A[j]){
            count = count + (right-j+1)*A[i];
            temp[k++] = A[i++];
            
        }
        else{
            temp[k++]=A[j++];
           
        }
    }
    while(i<mid){
        temp[k++] = A[i++];
    }
    while(j<=right){
        temp[k++] = A[j++];
    }
    for(int i=left, k=0; i<=right; i++,k++)
        A[i] = temp[k];
    
    return count;
}

long long merge_sort(int A[], int left, int right){
    long long count=0;
    if(right>left){
        int mid = left + (right-left)/2;
        
        long long left_count = merge_sort(A, left, mid);
        long long right_count = merge_sort(A, mid+1, right);
        long long merge_count = merging(A, left, mid+1, right);
        return left_count + right_count + merge_count;
        
    }
    return count;
}
long long solve(int A[], int n)
{
	// Write your code here.
    int left =0;
    int right = n-1;
    long long ans = merge_sort(A, left, right);
    return ans;
}

int main(){
    int t;
    cin>>t;
    while(t--){
        long long ans;
        int n;
        cin>>n;
        int A[n];
        for(int i=0; i<n; i++){
            cin>>A[i];
        }
        
        ans = solve(A, n);
        cout<<ans<<endl;
    }
}
