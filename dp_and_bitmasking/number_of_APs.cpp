/*
 Number of APs
Send Feedback
Given an array of n positive integers. The task is to count the number of Arithmetic Progression subsequences in the array. As the answer could be very large, output it modulo 100001.
Note: Empty sequence or single element sequence is Arithmetic Progression.
Input Format:

First Line: N (the size of the array)
Second Line: Elements of the array separated by spaces.

Output:

 Print total number of subsequences

Input Constraints:

1 <= arr[i] <= 1000
1 <= sizeof(arr) <= 1000

Sample Input 1 :

3
1 2 3

Sample output:

8

Sample Output Explanation:

Total subsequence are: {}, { 1 }, { 2 }, { 3 }, { 1, 2 }, { 2, 3 }, { 1, 3 }, { 1, 2, 3 }

Sample Input 2:

7
1 2 3 4 5 9 10

Sample Output:

37

*/
#include<bits/stdc++.h> 
#define MAX 1000001 
using namespace std; 
  
int numofAP(int a[], int n) 
{ 
    
    int minarr = INT_MAX, maxarr = INT_MIN; 
    for (int i = 0; i < n; i++) 
    { 
        minarr = min(minarr, a[i]); 
        maxarr = max(maxarr, a[i]); 
    } 
    int dp[n], sum[MAX]; 
    int ans = n + 1; 
    for (int d=(minarr-maxarr); d<=(maxarr-minarr); d++) 
    { 
        memset(sum, 0, sizeof sum); 
        for (int i = 0; i < n; i++) 
        { 
            dp[i] = 1; 
            if (a[i] - d >= 1 && a[i] - d <= 1000000) 
                dp[i] += sum[a[i] - d]; 
  
            ans += dp[i] - 1; 
            sum[a[i]] += dp[i]; 
        } 
    } 
  
    return (ans%100001); 
} 
  
