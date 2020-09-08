/*
Given a random integer array and a number x. Find and print the triplets of elements in the array which sum to x.
While printing a triplet, print the smallest element first.
That is, if a valid triplet is (6, 5, 10) print "5 6 10". There is no constraint that out of 5 triplets which have to be printed on 1st line. You can print triplets in any order, just be careful about the order of elements in a triplet.
Input format :

Line 1 : Integer N (Array Size)
Line 2 : Array elements (separated by space)
Line 3 : Integer x

Output format :

Line 1 : Triplet 1 elements (separated by space)
Line 2 : Triplet 3 elements (separated by space)
Line 3 : and so on

Constraints :
1 <= N <= 1000
1 <= x <= 100
Sample Input:

7
1 2 3 4 5 6 7 
12

Sample Output ;

1 4 7
1 5 6
2 3 7
2 4 6
3 4 5

*/
#include<bits/stdc++.h>
// arr - input array
// size - size of array
// x - sum of triplets

void FindTriplet(int arr[], int size, int x) {
    /* Don't write main().
     * Don't read input, it is passed as function argument.
     * Print output and don't return it.
     * Taking input is handled automatically.
     */
    int ans[3];
   for(int i=0; i<size-1; i++){
       unordered_set<int>s;
       for(int j=i+1; j<size; j++){
           int y = (-(arr[i]+arr[j])+x);
           if(s.find(y)!=s.end()){
               ans[0]=y;
               ans[1]=arr[i];
               ans[2]=arr[j];
               sort(ans, ans+3);
               cout<<ans[0]<<" "<<ans[1]<<" "<<ans[2]<<endl;
           }
           else
               s.insert(arr[j]);
           
       }
   }
}
