/*
 Code : Get Path - DFS
Send Feedback
Given an undirected graph G(V, E) and two vertices v1 and v2(as integers), find and print the path from v1 to v2 (if exists). Print nothing if there is no path between v1 and v2.
Find the path using DFS and print the first path that you encountered.
V is the number of vertices present in graph G and vertices are numbered from 0 to V-1.
E is the number of edges present in graph G.
Print the path in reverse order. That is, print v2 first, then intermediate vertices and v1 at last.
Note : Save the input graph in Adjacency Matrix.
Input Format :

Line 1: Two Integers V and E (separated by space)
Next E lines : Two integers a and b, denoting that there exists an edge between vertex a and vertex b (separated by space)
Line (E+2) : Two integers v1 and v2 (separated by space)

Output Format :

Path from v1 to v2 in reverse order (separated by space)

Constraints :
2 <= V <= 1000
1 <= E <= 1000
0 <= v1, v2 <= V-1
Sample Input 1 :

4 4
0 1
0 3
1 2
2 3
1 3

Sample Output 1 :

3 0 1

Sample Input 2 :

6 3
5 3
0 1
3 4
0 3

Sample Output 2 :
*/
#include<bits/stdc++.h>
using namespace std;
vector<int>ans;


int getpath(int** edges, int v, int v1, int v2, bool* visited){
  int result;
    if(v1==v2){
        ans.push_back(v2);
        return 1;
    }
    else{
        visited[v1]=true;
        for(int i=0; i<v; i++){
            if(edges[v1][i]==1 && !visited[i]){
                
                result = getpath(edges, v, i, v2, visited);
                
                if(result==1){
                    ans.push_back(v1);
                return 1;
                }
            }
        }
    }
    
}




int main(){
    int v, e;
    cin>>v>>e;
    
    int**edges = new int*[v];
    for(int i=0; i<v; i++){
        edges[i] = new int[v];
        for(int j=0; j<v; j++){
            edges[i][j]=0;
        }
    }
    for(int i=0; i<e; i++){
        int sv, ev;
        cin>>sv>>ev;
        edges[sv][ev]=1;
        edges[ev][sv]=1;
    }
    bool* visited = new bool[v];
    for(int i=0; i<v; i++){
        visited[i]=false;
    }
    int v1, v2;
    cin>>v1>>v2;
    vector<int>::iterator it;
    if(getpath(edges, v, v1, v2, visited)){
        for(it=ans.begin(); it!=ans.end(); it++){
            cout<<*it<<" ";
        }
    }
    return 0;
}



