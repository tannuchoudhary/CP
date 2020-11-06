/*
 Fibonacci Sum
Send Feedback
The fibonacci sequence is defined by the following relation:

 F(0) = 0
 F(1) = 1
 F(N) = F(N - 1) + F(N - 2), N >= 2

Your task is very simple. Given two non-negative integers N and M (N <= M), you have to calculate and return the sum (F(N) + F(N + 1) + ... + F(M)) mod 1000000007.
Input Format :

Two non-negative integers N and M. (N <= M)

Output Format :

A single line containing the answer for the task.

Sample Input :

10 
19

Sample Output :

10857

*/
#define MOD 1000000007
#define ULL unsigned long long 
void mul(ULL a[][2] , ULL b[][2])
{
    ULL res[2][2];
    memset(res , 0 , sizeof res);
    for(int i = 0 ; i < 2 ; i ++)
        for(int j = 0 ; j < 2 ; j++)
            for(int k = 0 ; k < 2 ; k++)
                res[i][j] = (res[i][j] + a[i][k]*b[k][j]) % MOD;
    for(int i = 0 ; i < 2 ; i++)
        for(int j = 0 ; j < 2 ; j++)
            a[i][j] = res[i][j];
}
ULL  power( ULL  n)
{
    ULL  fib[2][2] = { {1 , 1} , { 1 , 0}},temp[2][2] = { {1 , 0 } , { 0 , 1}};
    while(n)
    {
        if(n&1)
            mul(temp , fib);
        mul(fib , fib);
        n>>=1;
    }
    return temp[0][1];
}
unsigned long long fiboSum(unsigned long long l,unsigned long long r)
{
	return((power(r+2) - power(l+1) + MOD)%MOD);
}

