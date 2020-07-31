/*You have to calculate the minimum cost recquire to move from starting point to the end point in a 2 dimensional matrix
where each element consists of a number which is the cost to reach that element*/

#include<bits/stdc++.h>
using namespace std;

int min_cost(int** input, int m, int n){
    int **dp = new int*[m];
    for(int i=0; i<m; i++){
         dp[i] = new int[n];
    }
    
    dp[m-1][n-1] = input[m-1][n-1];
    
    for(int i=m-2; i>=0; i--){
        dp[i][n-1] = input[i][n-1]+dp[i+1][n-1];
    }
    
    for(int j=n-2; j>=0; j--){
        dp[m-1][j] = input[m-1][j] + dp[m-1][j+1];
    }
    
    for(int i=m-2; i>=0; i--){
        for(int j=n-2; j>=0; j--){
            dp[i][j] = input[i][j] + min(dp[i+1][j+1], min(dp[i][j+1], dp[i+1][j]));
        }
    }
    int ans = dp[0][0];
    for(int i=0; i<m; i++){
        delete [] dp[i];
    }
    delete [] dp;
    return ans;
}
int main(){
    int m, n;
    cin>>m>>n;
    int** input = new int*[m];
    for(int i=0; i<m; i++){
        input[i] = new int[n];
    }
    for(int i=0; i<m; i++){
        for(int j=0; j<n; j++){
            int num;
            cin>>num;
            input[i][j] = num;
        }
    }
    cout<<min_cost(input, m, n)<<endl;
    return 0;
}
