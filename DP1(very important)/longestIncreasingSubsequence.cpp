#include<bits/stdc++.h>
using namespace std;

int lis(int* input, int size){
    int* output = new int[size];
    
    output[0] = 1;
    for(int i=1; i<size; i++){
        output[i] =1;
        for(int j=i-1; j>=0; j--){
            if(input[j]>input[i])
            continue;
            
            int possible_ans = output[j]+1;
            if(possible_ans > output[i])
            output[i] = possible_ans;
        }
    }
    int max_length = 0;
    for(int i=0; i<size; i++){
        if(output[i]>max_length)
        max_length = output[i];
    }
    delete [] output;
    return max_length;
}

int main(){
    int n;
    cin>>n;
    int* input = new int[n];
    for(int i=0; i<n; i++){
        cin>>input[i];
    }
    int ans = lis(input, n);
    cout<<ans<<endl;
    delete [] input;
    return 0;
}
