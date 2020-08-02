/* Given a 2D array, find the maximum sum rectangle in it. In other words find maximum sum over all rectangles in the matrix.
Input

First line contains 2 numbers n and m denoting number of rows and number of columns. Next n lines contain m space separated integers denoting elements of matrix
nxm.

Output

Output a single integer, maximum sum rectangle.

Constraints

1<=n,m<=100

Sample Input

4 5
1 2 -1 -4 -20
-8 -3 4 2 1
3 8 10 1 3
-4 -1 1 7 -6

Sample Output

29*/


#include <bits/stdc++.h>
using namespace std;

long long kadane(long long* ar, long long n){
    long long current_sum=0;
    long long best_sum=0;
    
    for(long long i=0; i<n; i++){
        current_sum += ar[i];
        if(current_sum>best_sum){
            best_sum = current_sum;
        }
        if(current_sum<0)
        current_sum = 0;
    }
   return best_sum;
}
long long max_sum(long long** input, long long m, long long n){
    long long mx=0, i, l, r;
    for(l=0; l<n; l++){
        long long ar[m] = {0};
        for(r=l; r<n; r++){
            for(i=0; i<m; i++){
                ar[i] += input[i][r];
                
            }
            mx = max(kadane(ar, i), mx);
            
        }
    }
    return mx;
}
int main()
{
    long long m, n;
    cin>>m>>n;
    long long **input = new long long*[m];
    for(long long i=0; i<m; i++){
        input[i] = new long long[n];
    }
    
    for(long long i=0; i<m; i++){
        for(long long j=0; j<n; j++){
            long long num;
            cin>>num;
            input[i][j] = num;
        }
    }
    
   
    cout<<max_sum(input, m, n)<<endl;
    return 0;
}


