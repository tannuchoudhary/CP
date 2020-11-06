/*
 Card Game
Send Feedback
Vova again tries to play some computer card game.
The rules of deck creation in this game are simple. Vova is given an existing deck of n cards and a magic number k. The order of the cards in the deck is fixed. Each card has a number written on it; number ai is written on the i-th card in the deck.
After receiving the deck and the magic number, Vova removes x (possibly x = 0) cards from the top of the deck, y (possibly y = 0) cards from the bottom of the deck, and the rest of the deck is his new deck (Vova has to leave at least one card in the deck after removing cards). So Vova's new deck actually contains cards x + 1, x + 2, ... n - y - 1, n - y from the original deck.
Vova's new deck is considered valid iff the product of all numbers written on the cards in his new deck is divisible by k. So Vova received a deck (possibly not a valid one) and a number k, and now he wonders, how many ways are there to choose x and y so the deck he will get after removing x cards from the top and y cards from the bottom is valid?
Input

The first line contains two integers n and k (1 ≤ n ≤ 100 000, 1 ≤ k ≤ 10^9).

The second line contains n integers a1, a2, ..., an (1 ≤ ai ≤ 10^9) — the numbers written on the cards.

Output

Print the number of ways to choose x and y so the resulting deck is valid.

Sample Input 1

3 4
6 2 8

Sample Output 1

4

Sample Input 2

3 6
9 1 14

Sample Output 2

1

*/
#include <iostream>
  #include <cstring>
  #include <cstdio>
  using namespace std;
  int n,m;
  const int Max=1e6;
  long long Arr[Max];
  long long Pos[Max*2];
  #define lson l,mid,rt<<1
 #define rson mid+1,r,rt<<1|1
 void Build(int rt,int l,int r){
     if(l==r){
         Pos[rt]=Arr[l]%m;
         return;
     }
     int mid=(l+r)/2;
     Build(rt*2,l,mid);
     Build(rt*2+1,mid+1,r);
     Pos[rt]=(Pos[rt*2]*Pos[rt*2+1])%m;
 }
 long long query(int L,int R,int l,int r,int rt){
     if(L<=l&&r<=R){
         return Pos[rt];
     }
     long long ans=1;
     int mid=(l+r)/2;
     if(mid>=L){
         ans*=query(L,R,l,mid,rt*2)%m;
     }
     if(mid<R){
         ans*=query(L,R,mid+1,r,rt*2+1)%m;
     }
     return ans%m;
 }
 int main()
 {
     scanf("%d%d",&n,&m);
     for(int i=1;i<=n;i++){
        scanf("%lld",&Arr[i]);
     }
     Build(1,1,n);
     long long Sum=0;
     for(int i=1;i<=n;i++){
         int l=i;
         int r=n;
         int pos=n;
         while(l<r){
             int mid=(l+r)/2;
             if(query(i,mid,1,n,1)%m==0){
                 pos=mid;
                 r=mid;
             }else{
                 l=mid+1;
             }
         }
        if(query(i,pos,1,n,1)%m==0){
             Sum+=(n-pos+1);
         }
    }
     printf("%lld\n",Sum);
     return 0;
 }
