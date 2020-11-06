/*
 Advanced GCD
Send Feedback
Varun explained its friend Sanchit the algorithm of Euclides to calculate the GCD of two numbers. Then Sanchit implements the algorithm

int gcd(int a, int b)
{

    if (b==0)
    return a;
    else
    return gcd(b,a%b);
}

and challenges to Varun to calculate gcd of two integers, one is a little integer and other integer has 250 digits.
Your task is to help Varun an efficient code for the challenge of Sanchit.
Input

The first line of the input file contains a number representing the number of lines to follow. Each line consists of two number A and B (0 <= A <= 40000 and A <= B < 10^250).

Output

Print for each pair (A,B) in the input one integer representing the GCD of A and B..

Sample Input:

2
2 6
10 11

Sample Output:

2
1

*/
#include<bits/stdc++.h>
using namespace std;





long long  gcd(long long  a, long long b){
    if(b>a)
        gcd(b,a);
     if(b==0)
        return a;
    return gcd(b, a%b);
}
int main(){
	// Write your code here
    int t;
    cin>>t;
    while(t--){
    long long a;
    cin>>a; //first number A
    string s;
    cin>>s; //second number B
        if(a==0)
            cout<<s<<endl;
        else{
    int size = sizeof(s);
        
    long long num =0;
        
    for(int i=0; s[i]!='\0'; i++)
    {
        num = (num*10+s[i]-'0')%a;
    }
    cout<<gcd(num,a)<<endl;
    }
    }
	return 0;
}

#include<bits/stdc++.h>
using namespace std;
long long  gcd(long long  a, long long b){
    if(b>a)
        gcd(b,a);
     if(b==0)
        return a;
    return gcd(b, a%b);
}
int main(){
	// Write your code here
    int t;
    cin>>t;
    while(t--){
    long long a;
    cin>>a;
    string s;
    cin>>s;
        
    int size = sizeof(s);
        
    long long num =0;
        
    for(int i=0; s[i]!='\0'; i++)
    {
        num = (num*10+s[i]-'0')%a;
    }
    cout<<gcd(num,a)<<endl;
    }
    
	return 0;
}

