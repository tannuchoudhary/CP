#include <iostream>
#include<bits/stdc++.h>
using namespace std;

int main() {
	// your code goes here
	long n1, n2, n3;
	cin>>n1>>n2>>n3;
	long total = n1+n2+n3;
	long ar[total];
	for(long i=0; i<total; i++){
	    cin>>ar[i];
	}
	sort(ar, ar+total);
	long kj=0;
	long count=0;
	long last_n=0;
	long output[total];
	for(long j=0; j<total; j++){
	    int n=ar[j];
	    if(n==last_n){
	    count++;
	    }
	    else{
	        if(count>1){
	            output[kj] = last_n;
	            kj++;
	        }
	    count=1;
	    }
	    last_n=ar[j];
	}
	cout<<kj<<endl;
	for(int y=0; y<kj; y++){
	    cout<<output[y]<<endl;
	}
	return 0;
}

