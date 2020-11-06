 /*OrderSet - Problem
Send Feedback
In this problem, you have to maintain a dynamic set of numbers which support the two fundamental operations

INSERT(S,x): if x is not in S, insert x into S
DELETE(S,x): if x is in S, delete x from S

and the two type of queries

K-TH(S) : return the k-th smallest element of S
COUNT(S,x): return the number of elements of S smaller than x

Input Format

Line 1: Q (1 ≤ Q ≤ 200000), the number of operations
In the next Q lines, the first token of each line is a character I, D, K or C meaning that the corresponding operation is INSERT, DELETE, K-TH or COUNT, respectively, following by a whitespace and an integer which is the parameter for that operation.

If the parameter is a value x, it is guaranteed that ≤ |x| ≤ 10^9. If the parameter is an index k, it is guaranteed that 1 ≤ k ≤ 10^9.`

Output

For each query, print the corresponding result in a single line. In particular, for the queries K-TH, if k is larger than the number of elements in S, print the word 'invalid'.

Input Format

8
I -1
I -1
I 2
C 0
K 2
D -1
K 1
K 2

Output Format

1
2
2
invalid

*/
#include <iostream>
#include <algorithm>
#include <cstdio>
using namespace std;
#define MAX 200010

static long in[MAX]; char C[MAX];
static int BIT[MAX+1], N, x=0, I=0, s, e;
struct el{long v; int c;} A[MAX], tmp[MAX];

int cmp(el const& l, el const& r){return l.v<r.v;}
int bsearch(long v){
    s=1; e=I;
    while(s<=e){
        int m=(s+e)>>1;
        if(A[m].v>=v)e=m-1;
        else s=m+1;
    }
    return s;
}
inline void update(int i, int v){
    for(; i<=MAX; i+=(i&-i))BIT[i]+=v;
}
inline int query(int i){
    int ans=0;
    for(; i>0; i-=(i&-i)) ans+=BIT[i];
    return ans;
}

int main()
{
    cin >> N;
    for(int i=1; i<=N; ++i){
        cin>>C[i] >> in[i];
        if(C[i]=='I') tmp[++x].v=in[i];
    }
    sort(tmp+1, tmp+x+1, cmp);
    for(int i=1; i<=x; ++i){
        if(tmp[i-1].v!=tmp[i].v) {A[++I].v=tmp[i].v; A[I].c=0;}
    }
    for(int i=1; i<=N; ++i){
        if(C[i]=='I'){
            int y=bsearch(in[i]); A[y].c+=1;
            if (A[y].c==1) update(y, 1);
        }
        else if(C[i]=='D'){
            int y=bsearch(in[i]);
            if(A[y].c>0 && A[y].v==in[i]){update(y, -1); A[y].c=0;}
        }
        else if(C[i]=='C'){
            int y=bsearch(in[i]);
            int ans=query(y-1);
            cout << ans << '\n';
        }
        else if(C[i]=='K'){
            s=1; e=I;
            while(s<=e){
                int m=(s+e)>>1;
                if(query(m)>=in[i])e=m-1;
                else s=m+1;
            }
            if(s>I) cout << "invalid\n";
            else cout << A[s].v << '\n';
        }
    }
    return 0;
}
