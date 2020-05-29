/*#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n, sum=0;
    cin>>n;
    int a[n][n];
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            cin>>a[i][j];
             if((i==0)||(j==0)||(i==(n-1))||(j==(n-1))||(i==j)||(i+j==(n-1)))
        sum+=a[i][j];
        }
    }
    
   
  
    cout<<sum<<endl;
	return 0;
}*/

#include<bits/stdc++.h>
using namespace std;
int main(){
    int n, sum=0;
    cin>>n;
    int** m = new int*[n];
    for(int i=0; i<n; i++){
        m[i] = new int[n];
        for(int j=0; j<n; j++){
            cin>>m[i][j];
            
            
        }
    }
    
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            if(i==j)//diagonal
                sum+= m[i][j];
            else if(i==0 || i==(n-1))
                sum += m[i][j];
            else if(j==0 || j==(n-1))
                sum+= m[i][j];
            
            else if(i+j == n-1)
                sum += m[i][j];
        }
    }
    cout<<sum<<endl;
    return 0;
}

