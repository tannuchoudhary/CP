#include<bits/stdc++.h>
using namespace std;
/*int main() {

	// Write your code here
    int n, target, sum=0, grtr=0, ind, s=0, k;
    bool ans=false;
    cin>>n>>target;
    int a[n], an[n];
    for(int i=0; i<n; i++){
        cin>>a[i];
        if(a[i]<target)
            grtr=1;
        sum+=a[i];
    }
    if((grtr==0)||(sum<target)){
        ans = false;
        cout<<"false";
    }
    else{
       for(int i=0; i<n; i++){
           s=0;
           memset(an, 0, sizeof(an));
            k=0;
           for(int j=i; j<=n; j++){
               s+=a[j];
               an[k] =j;
               k++;
               if(s==target){
                   ans = true;
                   break;
               }
           }
           if(s==target){
                   ans = true;
                   break;
               }
          
       } 
         if(ans == true){
             cout<<"true"<<endl;
         for(int m=0; m<k; m++){
             cout<<a[an[m]]<<" ";
         }
         }
        if(ans==false){
            cout<<"false"<<endl;
        }
    }
   return 0; 
}*/


/*
int main(){
    int n;
    cin>>n;
    int target;
    cin>>target;
    int ar[n];
    for(int i=0; i<n; i++){
        cin>>ar[i];
    }
    int sum, start=0, end=0;
    for(int i=0; i<n; i++){
        
        int j=i;
        sum=0;
        start=i;
        while(sum != target){
            if(sum>target)
                break;
            sum += ar[j];
            end =j;
           
                
        }
        
    }
    
}*/


int main(){
    int n, t;
    string ans="false";
    cin>>n>>t;
    int ar[n];
    for(int i=0; i<n; i++){
        cin>>ar[i];
    }
    int sum=0;
    int start, end, suc=1;
    for(int i=0; i<n; i++){
        sum=0;
        for(int j=i; j<n; j++){
            sum+=ar[j];
            if(sum>t)
                break;
            if(sum==t){
              start=i;
                end=j;
                suc=0;
                ans = "true";
                break;
            }
            if(suc==0)
                break;
        }
    }
   
        cout<<ans<<endl;
     if(suc==0){
    for(int i=start; i<=end; i++){
        cout<<ar[i]<<" ";
     }
    }
    return 0;
}














































