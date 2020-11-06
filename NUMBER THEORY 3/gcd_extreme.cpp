/* GCD Extreme
Send Feedback
Given the value of N, you will have to find the value of G. The meaning of G is given in the following code

G=0;
for(i = 1 ; i < N ; i++)
   for(j = i+1 ; j <= N ; j++) 
       G+=gcd(i,j);

Here gcd() is a function that finds the greatest common divisor of the two input numbers.
Input

The input file contains at most 20000 lines of inputs. Each line contains an integer N (1 < N < 1000001). The meaning of N is given in the problem statement. Input is terminated by a line containing a single zero.

Output

For each line of input produce one line of output. This line contains the value of G for the corresponding N. The value of G will fit in a 64-bit signed integer.

Sample Input:

10
100
200000
0

Sample Output:

67
13015
143295493160

*/
#include <bits/stdc++.h>
using namespace std;
 
#define pb push_back
#define ff first
#define ss second
#define mp make_pair
#define memo(a,b) memset(a,b,sizeof(a))
#define INF 1e9
#define EPS 1e-8
#define PI 3.14159265358979323846
 
typedef long long ll ;
typedef unsigned long long ull ;
 
/* int dx[] = {1,-1,0,0} , dy[] = {0,0,1,-1}; */ // 4 Direction
/* int dx[] = {1,-1,0,0,1,1,-1,-1} , dy[] = {0,0,1,-1,1,-1,1,-1}; */ // 8 Direction
/* int dx[] = {1,-1,1,-1,2,2,-2,-2} , dy[] = {2,2,-2,-2,1,-1,1,-1}; */ // Knight Direction
/* int dx[] = {2,-2,1,1,-1,-1} , dy[] = {0,0,1,-1,1,-1}; */ // Hexagonal Direction

int phi[1000000+10] ;
ll S[1000000+10] ;

void pre_calculation()
{
    phi[1] = 1 ;
    for(int i=2;i<=1000000;i++)
    {
        if(phi[i]==0)
        {
            phi[i] = i-1 ;
            for(int j=i+i;j<=1000000;j+=i)
            {
                if(phi[j]==0) phi[j] = j ;
                phi[j] = phi[j] - phi[j]/i ;
            }
        }
    }
 
    for(int i=1;i<=1000000;i++)
    {
        for(int j=i+i;j<=1000000;j+=i)
        {
            S[j] = S[j] + (ll) (i*phi[j/i]);
        }
    }
 
    for(int i=1;i<=1000000;i++) S[i] = S[i] + S[i-1] ;
}

int main()
{
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    pre_calculation();
    int n ;
    while(scanf("%d",&n)==1&&n!=0) printf("%lld\n",S[n]);
    return 0;
}
