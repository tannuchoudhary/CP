#include<bits/stdc++.h>
using namespace std;

void printDFS(int** edges, int n, int sv, bool* visited){
    cout<<sv<<endl;
    visited[sv] = true;
    for(int i=0; i<n; i++){
        if(edges[sv][i] == 1){
            if(visited[i]){
            continue;
            }
            printDFS(edges, n, i, visited);
        }
    }
}

void printBFS(int** edges, int n, int sv, bool* visited){
    queue<int>pendingVertices;
    for(int i=0; i<n; i++){
        visited[i] = false;
    }
    pendingVertices.push(sv);
    visited[sv]=true;
    while(!pendingVertices.empty()){
        int currentVertex = pendingVertices.front();
        pendingVertices.pop();
        cout<<currentVertex<<endl;
        for(int i=0; i<n; i++){
            if(i==currentVertex)
            continue;
            if(edges[currentVertex][i]==1 && visited[i] == false){
                pendingVertices.push(i);
                visited[i] = true;
            }
        }
    }
}

int main(){
    int n, e;
    cin>>n>>e;
    int**edges = new int*[n];
    for(int i=0; i<n; i++){
        edges[i] = new int[n];
        for(int j=0; j<n; j++){
            edges[i][j]=0;
        }
    }
    
    for(int i=0; i<e; i++){
            int f, s;
            cin>>f>>s;
            edges[f][s]=1;
            edges[s][f]=1;
    }
    
    bool* visited = new bool[n];
    for(int i=0; i<n; i++){
        visited[i] = false;
    }
    cout<<"DFS"<<endl;
    printDFS(edges, n, 0, visited);
    cout<<"BFS"<<endl;
    printBFS(edges, n, 0, visited);
    for(int i=0; i<n; i++){
        delete [] edges[i];
    }
    delete [] edges;
    return 0;
}
