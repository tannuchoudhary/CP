/*
 Find the good sets!
Send Feedback
You are given array a consisting of n distinct integers. A set s of numbers is called good if you can rearrange the elements in such a way that each element divides the next element in the order, i.e. 'si' divides 'si + 1', such that i < |s|, where |s| denotes size of set |s|.
Find out number of distinct good sets that you can create using the values of the array. You can use one value only once in a particular set; ie. a set cannot have duplicate values. Two sets are said to be different from each other if there exists an element in one set, which does not exist in the other.
As the answer could be large, print your answer modulo 10^9 + 7.
Input

First line of the input contains an integer T denoting the number of test cases. T test cases follow.

First line of each test case contains an integer n denoting number of elements in array a.

Next line contains n space separated integers denoting the elements of array a.

Output

For each test case, output a single line containing the corresponding answer.

Constraints

1 ≤ T ≤ 3

1 ≤ n ≤ 7.5 * 10^5

1 ≤ ai ≤ 7.5 * 10^5

All the elements of array a are distinct.

Example
Input

2
2
1 2
3
6 2 3

Output:

3
5

Explanation

Test case 1. There are three sets which are good {1}, {2}, {1, 2}.

Test case 2. There are five sets which are good {6}, {2}, {3}, {6 2}, {6, 3}.

*/
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <iostream>
#include <ctime>
#include <cmath>
#include <utility>
#include <cassert>
#include <complex>
#include <algorithm>

#include <vector>
#include <queue>
#include <set>
#include <map>
#include <bitset>
#include <string>

using namespace std;

typedef unsigned int uint;
typedef long long ll;
typedef unsigned long long ull;
#define sz(x) (int)((x).size())
#define X first
#define Y second
#define sqr(x) ((x) * (x))
#define bit(i) (1 << (i))
#define FOR(i,a,b) for(int i=(a);i<(b);i++)
#define rep(i,n) for(int i=0;i<(n);i++)
#define all(a) (a).begin(),(a).end()
#define mset(m,v) memset(m,v,sizeof(m))
#define mp make_pair
#define pb push_back
 #define MOD 1000000007
#define cnb(x) __builtin_popcount(x)
#define cnlz(x) __builtin_clz(x)
#define cnlzll(x) __builtin_clzll(x)
#define cntz(x) __builtin_ctz(x)
#define cntzll(x) __builtin_ctzll(x)

typedef double DB;
typedef long long LL;
typedef vector<int> VI;
typedef vector<LL> VL;
typedef vector<DB> VDB;
typedef pair<int, int> PII;
typedef pair<double, int> PDI;
typedef pair<LL, LL> PLL;
typedef pair<int, LL> PIL;

template <class T> inline void chkmax(T &a, T b) {
    if (a < b) a = b;
}
template <class T> inline void chkmin(T &a, T b) {
    if (b < a) a = b;
}

#define MN 100004
long long ans[1000010];
long long arr[1000010];
bool f[1000010];
int main()
 {
  int t;
  cin>>t;
  while(t--) 
  {
   for(int i=0;i<=1000002 ;i++)
   {    
         ans[i]=0;
         f[i]=0;
   }
    int n;
    cin>>n;
    for(int i=0;i<n;i++)
     {
              cin>>arr[i];
              ans[arr[i]]=1;
              f[arr[i]]=true;
     }
     for(long long i=1;i<=1000000;i++) 
      {
               if(f[i]==1)
                   for(long long j=i*1LL*2;j<=1000000;j+=i) 
                  {
                      ans[j] = (ans[j]+1LL*ans[i])%MOD;
                   }
      }
    long long res=0;
    for(int i=1;i<=1000000;i++) 
    {
           if(f[i])    
                res=(res+ans[i])%MOD;
    }
    if(ans[0]==1)
    {
        res*=2;
        res++;
    }
    cout<<res<<endl;
  }
  return 0;
}
