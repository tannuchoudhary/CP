/*
 Sehwag And ETF
Send Feedback
Sehwag has been solving a lot of mathematical problems recently. He was learning ETF (Euler Totient Function) and found the topic quite interesting. So, he tried solving a question on ETF. He will be given two numbers L and R. He has to find the probability that the ETF of a number in the range [L, R] is divisible by a number K.
Input:

The first line contains the number of test cases i.e. T.
The next T lines will contain three integers L, R and K.

Output:

Print the answer in a new line after rounding off the first 6 digits after the decimal place.

Constraints:

1 <= T <= 10
1 <= L <= R <= 10^12
0 <= R - L <= 10^5
1 <= K <= 10^6

Sample Input:

3
1 4 2
2 5 2
3 10 4

Sample Output:

0.500000
0.750000
0.375000

*/
#include <bits/stdc++.h>
using namespace std;
#define mod 1000000007
#define ll long long int
#define pb push_back
#define mk make_pair
ll power(ll a, ll b) {
ll x = 1, y = a;
    while(b > 0) {
        if(b%2 == 1) {
            x=(x*y);
            if(x>mod) x%=mod;
        }
        y = (y*y);
        if(y>mod) y%=mod;
        b /= 2;
    }
    return x;
}
ll prime[1000002];
vector<ll>x;
void sieve()
{
    ll i,j;
    for(i = 1LL; i <= 1000000LL; i++) {
        prime[i] = i;
    }
    for(i = 2LL; i <= 1000000LL; i++) {
        if(prime[i] == i) {
            for(j = 2; j*i <= 1000000LL; j++) {
                prime[j*i] = (i-1)*prime[j*i]/i;   
            }
            prime[i] = i-1;
            x.push_back(i);
        }
    }
}
ll arr[100005],brr[100005];
int main() 
{
	//freopen("Sample Input.in","r",stdin);
	//freopen("Sample Output.out","w",stdout);
    sieve();
   	int t;
   	cin>>t;
   	ll l = x.size();
   	while(t--) {
    	ll a,b,c,i,j,y,k;
    	cin>>a>>b>>k;
    	c = 0;
    	if(b <= 1000000) {
        	for(i = a; i <= b; i++) {
        		if(prime[i]%k == 0) {
        			c++;
        		}
        	}
    		printf("%.6lf\n",(double)(c)/(double)(b-a+1));
        	continue;
    	}
    	for(i = a; i <= b; i++) {
        	arr[i-a] = i;
        	brr[i-a] = i;
    	}
    	for(i = 0; i < l; i++) {
        	y = (a/x[i])*x[i];
        	for(j = y; j <= b; j += x[i]) {
            	if(j < a) {
                	continue;
            	}
            	while(brr[j-a]%x[i] == 0) {
                	brr[j-a] /= x[i];
            	}
            	arr[j-a] /= (x[i]);
            	arr[j-a] *= (x[i]-1);
        	}
    	}
    	for(i = a; i <= b; i++) {
        	if(arr[i-a] == i) {
            	arr[i-a] = i-1;
            	if(arr[i-a]%k == 0) {
            		c++;
            	}
            	continue;
        	}
        	else if(brr[i-a] != 1) {
            	arr[i-a] /= brr[i-a];
            	arr[i-a] *= (brr[i-a]-1);
        	}
        	if(arr[i-a]%k == 0) {
        		c++;
        	}
    	}
    	printf("%.6lf\n",(double)(c)/(double)(b-a+1));
   	}
	return 0;
}
