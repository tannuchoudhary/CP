#include<bits/stdc++.h>
#include<string>
#include<map>
#define max 100000

using namespace std;
int main()

{
    string str;
    int suc=0, index=0;
    getline(cin, str);
    string word="";
    vector<string>v;
    for(auto x:str){
        if(x==' '){
            v.push_back(word);
            index++;
            word = "";
        }
        else
            word+=x;
    }
    if(!word.empty()){
        v.push_back(word);
        index++;
    }
  map<string, int>m;
    map<string, int>::iterator it;
    for(int j=0; j<index; j++){
        if(m.find(v[j])==m.end()){
            m.insert(pair<string,int>(v[j], 1));
        }
           else
           m.find(v[j])->second+=1;
    }
    for(it=m.begin(); it!=m.end(); it++){
        if((it->second)>1){
        cout<<it->first<<" "<<it->second<<endl;
            suc=1;
        }
    }
    if(suc==0){
        cout<<"-1"<<endl;
    }
    return 0;
}
