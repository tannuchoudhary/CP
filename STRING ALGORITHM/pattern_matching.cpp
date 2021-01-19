/*Return true if second string is present in the first string else return false
e.g string1 = "abcdefghtyu"
    string 2 = "tyu"
    o/p = true
*/
#include<bits/stdc++.h>
using namespace std;

bool matching(string s, string p){
    int m = s.length();
    int n = p.length();
    
    for(int i=0; i<=(m-n); i++){
        bool found = true;
        for(int j=0; j<n; j++){
            if(s[i+j]!=p[j]){
                found = false;
                break;
            }
        }
        if(found == true)
        return true;
    }
    return false;
}

int main(){
   string s, p;
   cin>>s>>p;
   cout<<matching(s, p)<<endl;
    return 0;
}
