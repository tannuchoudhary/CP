#include<bits/stdc++.h>
using namespace std;
class triplet{
    public:
    
    int x;
    int y;
    int gcd;
};

triplet extendedEuclid(int a, int b){
    if(b==0){
        triplet ans;
        ans.x = 1;
        ans.y = 0;
        ans.gcd = a;
        return ans;
    }
    triplet smallAns = extendedEuclid(b, a%b);
    triplet ans;
    ans.gcd = smallAns.gcd;
    ans.x = smallAns.y;
    ans.y = smallAns.x - (a/b)*smallAns.y;
    return ans;
}
int mmInverse(int a, int m){
  triplet ans = extendedEuclid(a,m);
  return ans.x;
}

int main(){
    int a = 5;
    int m= 12;
    int ans = mmInverse(a,m);
    cout<<"Multiplicative modulo inverse is "<<ans<<endl;
    return 0;
}
