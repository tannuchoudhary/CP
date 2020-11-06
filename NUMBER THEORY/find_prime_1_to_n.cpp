 /*Find Prime Numbers From 1 to N
Send Feedback
Given a number N, find number of primes in the range [1,N].
Input:

The only line of input consists of a number N

Output:

Print the number of primes in the range [1,N].`

Constraints:

1≤N≤1000000

Sample Input :

3 

Sample Output -

2
*/
#include<bits/stdc++.h>
#include<cmath>
using namespace std;
/*bool checkPrime(int n){
    int count = 0;
    int root = sqrt(n);
    for(int i=1; i<=root; i++){
        if(n%i==0){
            if(i*i == n)
                count++;
            else
                count+=2;
        }
    }
    if(count>2)
        return false;
    else
        return true;
}
int main(){
	// Write your code here
    
    int n;
    cin>>n;
    int count = 0;
    for(int i=1; i<=n; i++){
        
        int num = i;
        if(num==1)
            continue;
        if(checkPrime(n))
         count++;   
    }
    cout<<count;
	return 0;
    
}*/
//===========================SIEVE OF ERATOSTHENES===============================================


/* int sieveOfErat(int n){
     int count=0;
     bool* ar = new bool[n+1];
    // memset(ar, true, sizeof(ar));
     for(int i=0; i<=n; i++){
         ar[i] = true;
     }
     ar[0] = false;
     ar[1] = false;
     
     for(int i=2; (i*i)<=n; i++){
         for(int j=i*i; j<=n; j+=i){
            
                 ar[j]=false;
         }
     }
     for(int i=0; i<=n; i++){
         if(ar[i] == true)
             count++;
     }
     return count;
 }*/
int sieveOfErat(int n){
    bool* ar = new bool[n+1];
    int count=0;
    for(int i=0; i<=n; i++){
        ar[i] = true;
    }
    ar[0] = false;
    ar[1] = false;
    for(int i=2; i*i<=n; i++){
        for(int j=(i*i); j<=n; j+=i){
            ar[j] = false;
        }
    }
    for(int i=0; i<=n; i++){
        if(ar[i] == true)
            count++;
    }
    return count;
}
int main(){
    int n;
    cin>>n;
    cout<<sieveOfErat(n)<<endl;
    return 0;
}

