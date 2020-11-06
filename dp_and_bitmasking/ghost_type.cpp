/*
 Ghost Type
Send Feedback
Gengar has got an integer N. Now using his ghostly powers, he can create the permutation from 1 to N of this given number.
Since, he's a special kind of Poke'mon, so he thinks he deserves special permutations. He wants to find the total number of special permutations of length N, consisting of the integers from 1 to N

.
A permutation is called special if it satisfies following condition:

If Ap & Aq == Ap, then p < q, where p and q are two distinct indices of permutation and A is the permutation itself. "&" denotes the bitwise and operation.

Help Gengar in finding the number of such permutations.
Input format:

The only line of input will consist of a single integer N denoting the length of the permutation.

Output format:

Output the total number of special permutations of length N

.
Constraints:

1 ≤ N ≤ 20
SAMPLE INPUT

4
SAMPLE OUTPUT

8
Explanation

All the special permutations of length 4 are: 1 2 3 4

1 2 4 3

1 4 2 3

2 1 3 4

2 1 4 3

2 4 1 3

4 1 2 3

4 2 1 3
*/
#include <bits/stdc++.h>
using namespace std;
 
typedef long long ll;
typedef vector<ll> vl;      typedef vector<int> vi;
typedef vector<vl> vvl;     typedef vector<vi> vvi;
typedef pair<ll, ll> pll;   typedef pair<int, int> pii;
#define forn(i,n) for(int i=0;i<n;i++)
#define rforn(i,n) for(int i=n-1;i>=0;i--)
#define forne(i,n) for(int i=1;i<=n;i++)
#define forse(i,s,e) for(int i=s;i<e;i++)
#define rforse(i,s,e) for(int i=e-1;i>=s;i--)
#define all(x) x.begin(),x.end()
#define sz(x) (int)x.size()
#define MOD 1000000007
#define F first
#define S second
#define pb push_back
#define mp make_pair
#define fill(a,x) memset(a,x,sizeof a);
#define trav(a,x) for(auto &a:x)
#define INF ll(1e18)
#ifdef SHUBHAM107
#include "../trace.h"
#else
#define trace(args...)
#endif
 
const int N = 21;
ll dp[1 << N];
int n;
 
ll f(int mask){
    if(dp[mask] != -1){
        return dp[mask];
    } else if(mask == (1 << (n + 1)) - 2){
        return 1;
    }
    ll &ret = dp[mask];
	ret = 0;
    for(int i = 1; i <= n; i++){
        if(mask >> i & 1 ^ 1){
            bool ok = true;
            for(int s = i; s; s = (s - 1) & i){
                if(s == i)
                    continue;
                ok &= (mask >> s & 1);
            }
            if(ok){
                ret += f(mask | (1 << i));
            }
        }
    }
    return ret;
}
void solve() {
	fill(dp, -1);
    cin >> n;
    cout << f(0);
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
#ifdef SHUBHAM107
    freopen("inp.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
    freopen("err.txt", "w", stderr);
#endif
    int t = 1;
    // cin >> t;
    while (t--) {
        solve();
    }
}
