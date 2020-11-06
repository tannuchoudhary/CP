/* Power
Send Feedback
Write a program to find x to the power n (i.e. x^n). Take x and n from the user. You need to return the answer.
Do this recursively.
Input format :

Two integers x and n (separated by space)

Output Format :

x^n (i.e. x raise to the power n)

Constraints :

1 <= x <= 30
0 <= n <= 30

Sample Input 1 :

 3 4

Sample Output 1 :

81

Sample Input 2 :

 2 5

Sample Output 2 :

32

*/
int power(int x, int n) {
 
   if(n==0){
       return 1;//set for smallest problem i.e base case
   }
    int small_problem = power(x, n-1);
    int output = x*small_problem;
    return output;
}
/*int power(int x, int n) {
   if(n==0){
       return 1;
   }
    int small_output = power(x, n-1);
    int output = x * small_output;
    return output;

}*/
