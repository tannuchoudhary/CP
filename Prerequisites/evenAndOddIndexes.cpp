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

