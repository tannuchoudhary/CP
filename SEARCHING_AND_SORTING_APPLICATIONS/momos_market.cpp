/*I AM EXPLAINING BY TAKING EXAMPLE OF INPUT OF QUES I.E 
INPUT

 4
 2 1 6 3
 1 
 11
 
 OUTPUT
 3 2
 */
#include<bits/stdc++.h>
using namespace std;

bool check(int cost_till_now[], int money, int INDEX_OF_SHOP){
    if(cost_till_now[INDEX_OF_SHOP-1]<=money) /*IF THE MONEY IS LESS THAN OR EQUAL TO BUY THE MOMOS FROM SHOPS THEN RETURN TRUE FOR THAT INDEX OF SHOP*/
        return true;
    else
        return false;
}
int main()   /*USE THE CONCEPT OF INVERSION COUNT QUESTION*/
{
    int n;   
    cin>>n; 
    int ar[n];
    int cost_till_now[n];
    int sum=0;
    for(int i=0; i<n; i++){
        cin>>ar[i];
        sum+=ar[i];
        cost_till_now[i]=sum;  /*MAKE AN ARRAY IN WHICH KEEP THE SUM OF THE PRICE OF LAST ALL MOMOS, HERE IT WILL BE [2, 3, 9, 14]*/
    }
    int q;
    cin>>q;
    int b[q];
    for(int i=0; i<q; i++){
        cin>>b[i]; 
        /*IMPLEMENT BINARY SEARCH*/
        
        int start = 0;/*MINIMUM OF 0 MOMOS SHE CAN BUY IN ONE DAY, IF SAVING IS LESS THAN THE PRICE OF FIRST MOMO FROM MOMOS SHOP*/
        int end = n; /*MAXIMUM MOMOS THAT GIRL CAN BUY WILL BE FROM ONE MOMOS FROM EACH SHOP, I.E MAXIMUM OF N MOMOS SHE CAN BUY IN ONE DAY*/
        int ans = -1;
        while(start<=end){
            int mid = start+(end-start)/2;
            if(check(cost_till_now, b[i], mid)){ /*WE'LL CHECK ONE BY ONE THAT HOW MANY MAXIMUM MOMOS SHE CAN BUY FROM HER SAVING*/
                ans=mid;
                start=mid+1;
            }
            else
                end=mid-1;
        }
        cout<<ans<<" "<<b[i]-cost_till_now[ans-1]<<endl;/*PRINT THE INDEX OF THAT SHOP UPTO WHICH SHE CAN BUY MOMOS AND MONEY LEFT*/
    }
    
	return 0;
}
