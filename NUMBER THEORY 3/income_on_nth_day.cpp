/* Income On Nth Day
Send Feedback
Daulat Ram is an affluent business man. After demonetization, IT raid was held at his accommodation in which all his money was seized. He is very eager to gain his money back, he started investing in certain ventures and earned out of them. On the first day, his income was Rs. X, followed by Rs. Y on the second day. Daulat Ram observed his growth as a function and wanted to calculate his income on the Nth day.
The function he found out was FN = FN-1 + FN-2 + FN-1×FN-2
Given his income on day 0 and day 1, calculate his income on the Nth day (yeah Its that simple).
Input:

The first line of input consists of a single integer T denoting number of test cases.

Each of the next T lines consists of three integers F0, F1 and N respectively.

Output:

For each test case, print a single integer FN, as the output can be large, calculate the answer modulo 10^9+7.

CONSTRAINTS:

1 ≤ T ≤ 10^5

0 ≤ F0, F1, N ≤ 10^9

Sample Input :

2
0 1 2
1 2 4

Sample Output:

1
107

Explanation

In the second test case his income on day 0 is 1 and the income on day 1 is 2. We need to calculate his income on day 4.

F0=1

F1=2

F2=1 + 2 + 1×2 = 5

F3=2 + 5 + 2×5 = 17

F4=5 + 17 + 5×17 = 107

*/
    #include<bits/stdc++.h>
    using namespace std;
    #define ll long long
    #define mod 1000000007
     
    void multiply(ll A[2][2],ll F[2][2]){
        ll m = mod-1;
        ll x = ((A[0][0]*F[0][0])%m + (A[0][1]*F[1][0])%m)%m;
        ll y = ((A[0][0]*F[0][1])%m + (A[0][1]*F[1][1])%m)%m;
        ll z = ((A[1][0]*F[0][0])%m + (A[1][1]*F[1][0])%m)%m;
        ll w = ((A[1][0]*F[0][1])%m + (A[1][1]*F[1][1])%m)%m;
        
        A[0][0] = x;
        A[0][1] = y;
        A[1][0] = z;
        A[1][1] = w;
    }
     
    void mpow(ll A[2][2],ll n){
        if(n==1){
            return;
        }
        mpow(A,n/2);
        multiply(A,A);
        
        ll F[2][2] = {{1,1},{1,0}};
        if(n%2==1){
            multiply(A,F);
        }
    }
     
    ll fib(ll n){
    	ll m = mod-1;
        
        if(n==0 || n==1){
            return n;
        }
        ll A[2][2] = {{1,1},{1,0}};
        mpow(A,n-1);
        return (A[0][0])%m;
        
    }
     
    ll power(ll x,ll n){
        ll res = 1;
        x = x%mod;
        if(x==0){
            return 0;
        }
        while(n>0){
            
            if(n%2==1){
                res = (res*x)%mod;
            }
            n = n>>1;
            x = (x*x)%mod;
        }
        
        return res;
    }
     
    int main() {
        
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        int t;
        cin>>t;
        while(t--){
            ll a,b,n;
            cin>>a>>b>>n;
            
            if(n==1){
                cout<<b<<endl;
            }
            else if(n==0){
                cout<<a<<endl;
            }
            else{
            
                ll x = fib(n-1);
                ll y = fib(n);
                
                
                ll fn = power(a+1,x)*power(b+1,y);
                fn--;
                fn = fn%mod;
                if(fn<0){
                    fn = fn+mod;
                }
                cout<<fn<<endl;
            }
        }
    }
