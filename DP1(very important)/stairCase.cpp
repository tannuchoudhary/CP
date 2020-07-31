/*A child is running up a staircase with n steps and can hop either 1 step, 2 steps or 3 steps at a time. Implement a method to count how many possible ways
the child can run up to the stairs. You need to return all possible number of ways.
Time complexity of your code should be O(n).
Input format :

Integer n (No. of steps)

Constraints :

n <= 70

Sample Input 1:

4

Sample Output 1:

7
*/


long staircase(int n){
    
    long ar[n+1] = {0};
    long ans;
    
    
    ar[0] =1;
    ar[1] =1;
    ar[2] = 2;
    
    if(ar[n]>0)
        return ar[n];
    
   for(int i=3; i<=n; i++){
       ar[i] = ar[i-1]+ar[i-2]+ar[i-3];
       
       
   }
    ans = ar[n];
    //delete [] ar;
    return ans;
    
    
}
