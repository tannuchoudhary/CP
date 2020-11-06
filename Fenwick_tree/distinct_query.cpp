/*
 Distinct Query Problem
Send Feedback
Given a sequence of n numbers a1, a2, ..., an and a number of d-queries. A d-query is a pair (i, j) (1 ≤ i ≤ j ≤ n). For each d-query (i, j), you have to return the number of distinct elements in the subsequence ai, ai+1, ..., aj.
Input

Line 1: n (1 ≤ n ≤ 30000).
Line 2: n numbers a1, a2, ..., an (1 ≤ ai ≤ 10^6).
Line 3: q (1 ≤ q ≤ 200000), the number of d-queries.
In the next q lines, each line contains 2 numbers i, j representing a d-query (1 ≤ i ≤ j ≤ n).

Output

For each d-query (i, j), print the number of distinct elements in the subsequence ai, ai+1, ..., aj in a single line.

Sample Input

5
1 1 2 1 3
3
1 5
2 4
3 5

Sample Output

3
2
3 

*/
#include<bits/stdc++.h>
 
using namespace std;
map<int ,int> mp;
struct Node {
	int l,r;
	int id;
} node[200000 + 5];
int n,m,c[30000 + 5],ans[200000 + 5];
int a[30000 + 5];
int lowbit(int x) {
	return x&-x;
}
void update(int x,int val) {
	while(x<=n) {
		c[x] += val;
		x+=lowbit(x);
	}
}
int query(int x) {
	int res = 0;
	while(x>0) {
		res += c[x];
		x-=lowbit(x);
	}
	return res;
}
bool cmp(const Node & a,const Node & b) {
    return a.r < b.r;
}
int main()
{
	while(~scanf("%d",&n) ) {
		memset(c,0,sizeof c);
		mp.clear();
		for(int i = 1; i<=n; i++) {
			scanf("%d",&a[i]);
		}
		scanf("%d",&m);
		for(int i = 1; i<=m; i++) {
			scanf("%d%d",&node[i].l,&node[i].r);
			node[i].id = i;
		}
		int cur = 1;
		sort(node+1,node+m+1,cmp);
		for(int i = 1; i<=m; i++) {
			while(cur <= node[i].r) {
				if(mp[a[cur] ] == 0) update(cur,1);
				else {
					update(mp[a[cur] ] ,-1);
					update(cur,1);
				}
				mp[a[cur] ] = cur;
				cur++;
			}
			ans[node[i].id] = query(node[i].r) - query(node[i].l - 1);
		}
		for(int i = 1; i<=m; i++) {
            printf("%d\n",ans[i]);
        }
		
	}
	return 0 ;
}
