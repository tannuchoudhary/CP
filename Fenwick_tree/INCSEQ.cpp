/*
 INCSEQ
Send Feedback
Given a sequence of N (1 ≤ N ≤ 10,000) integers S1, ..., SN (0 ≤ Si < 100,000), compute the number of increasing subsequences of S with length K (1 ≤ K ≤ 50 and K ≤ N); that is, the number of K-tuples i1, ..., iK such that 1 ≤ i1 < ... < iK ≤ N and Si1 < ... < SiK.
Input

The first line contains the two integers N and K. The following N lines contain the integers of the sequence in order.

Output

Print a single integer representing the number of increasing subsequences of S of length K, modulo 5,000,000.

Sample Input

4 3
1
2
2
10

Output:

2

*/
// 2014-10-02
#include <cstdio>
const int MAX = 100000;
const int MOD = 5000000;
int BIT[51][MAX];
int query(int* b, int idx) {
    int res = 0;
    while (idx >= 0) {
        res += b[idx];
        if (res >= MOD) res -= MOD;
        idx = (idx&(idx+1))-1;
    }
    return res;
}
void update(int* b, int idx, int val) {
    while (idx < MAX) {
        b[idx] += val;
        if (b[idx] >= MOD) b[idx] -= MOD;
        idx |= idx+1;
    }
}
int main() {
    int N, K; scanf("%d %d", &N, &K);
    while (N--) {
        int x; scanf("%d", &x);
        update(BIT[1], x, 1);
        for (int i = 2; i <= K; i++) {
            update(BIT[i], x, query(BIT[i-1], x-1));
        }
    }
    printf("%d\n", query(BIT[K], 99999));
    return 0;
}

