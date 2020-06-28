#include<bitstdc++.h>
using namespace std;

class trieNode(){
    public:
    trieNode* left;
    trieNode* right;
};

void insertNode(trieNode* head, int n){
    trieNode *current = head;
    for(int i=31; i>=0; i--){
        int b=(n>>i)&1;
        if(b==0){
            if(!current->left){
                current->left = new trieNode();
            }
            current = current->left;
        }
        else{
             if(!current->right){
                current->right= new trieNode();
            }
            current = current->right;
        }
    }
}

int maxXorPossible(trieNode* head, int* arr, int n){
    
    int max_xor=INT_MIN;
    for(int i=0; i<n; i++){
        trieNode* current = head;
        int current_xor=0;
        int element = arr[i];
        for(int j=31; j>=0; j--){
        int b = (element>>j)&1;
        if(b==0){
           if(current->right){
               current_xor += pow(2, j);
               current = current->right;
           } 
           else{
               current = current->left;
           }
        }
        else{
            if(current->left){
               current_xor += pow(2, j);
               current = current->left;
           } 
           else{
               current = current->right;
           }
        }
        }
        if(current_xor>max_xor)
        max_xor = current_xor;
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
    for(int i=0; i,n; i++){
        insertNode(head, arr[i]);
    }
    cout<<maxXorPossible(head, arr, n)<<endl;
    return 0;
}
