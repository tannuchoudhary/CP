#include<bits/stdc++.h>
using namespace std;




class trieNode{
    public:
    trieNode* left;
    trieNode* right;
};
void insert(trieNode* head, int n){
    trieNode* current = head;
    for(int i=31; i>=0; i--){
        int b = (n>>i)&1;
        if(b==0){
            if(!current->left){
                current->left = new trieNode();
                
            }
            
                current = current->left;
            
        }
        else{
            if(!current->right){
                current->right = new trieNode();
            }
            
                current = current->right;
        }
    }
}
int max_xor_sub(trieNode* head, int* arr, int n){
   
    int max_xor= INT_MIN;
    int cur_xor=0;
    int prev=0;
   for(int i=1; i<n; i++){
       int element = prev^arr[i];
       prev = element;
       trieNode* current = head;
       cur_xor = 0;
       
       for(int j=31; j>=0; j--){
           int b = (element>>j)&1;
           if(b==0){
               if(current->right){
                   cur_xor += pow(2, j);
                    current = current->right;
               }
               else{
                   current = current->left;
               }
           }
           else{
                if(current->left){
                   cur_xor += pow(2, j);
                    current = current->left;
               }
               else{
                   current = current->right;
               }
           }
       }
       insert(head, element);
       if(cur_xor>max_xor)
           max_xor = cur_xor;
   }  
    return max_xor;
}

int main(){
    int n;
    cin>>n;
    int* arr = new int[n];
    for(int i=0; i<n; i++){
        cin>>arr[i];
    }
    trieNode* head = new trieNode();
    insert(head, arr[0]);
    cout<<max_xor_sub(head, arr, n)<<endl;
    return 0;
}
