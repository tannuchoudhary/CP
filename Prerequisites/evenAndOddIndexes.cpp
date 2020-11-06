/* Even and Odd Indexes
Send Feedback
Given an array of integers, print two integer values:
First, the sum of all numbers which are even as well as whose index are even.
Second, the sum of all numbers which are odd as well as whose index are odd.
Print the two integers space separated. (Arrays is 0-indexed)
Input:

Given an integer denoting the size of array.
Next line will have a line containing ‘n’ space separated integers.

Constraints:

1<=n<=10^5
1 <= Ai <= 10^6 

Output:

Two space separated integers denoting even and odd sums respectively.

Sample Input:

5
2 3 5 1 4

Sample Output:

6 4
*/


/*#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n, sume=0, sumo=0;
    cin>>n;
    for(int i=0; i<n; i++){
        int num;
        cin>>num;
       // if((i==0)&&(num%2==0))
         //   sume+=num;
        if((i%2==0)&&(num%2==0)){
         sume+=num;   
        }
        if((i%2==1)&&(num%2==1)){
         sumo+=num;   
        }
    }
    
    cout<<sume<<" "<<sumo<<endl;
    
	return 0;
}*/

#include<bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cin>>n;
    int sum_e=0, sum_o=0;
    for(int i=0; i<n; i++){
      int a; 
        cin>>a;
       
        if((i%2==0)&&(a%2==0))
            sum_e += a;
        else if((i%2==1)&&(a%2==1))
            sum_o += a;
    }
    cout<<sum_e<<" "<<sum_o<<endl;
    return 0;
}

