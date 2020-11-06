/*
 Code : Get Path - BFS
Send Feedback
Given an undirected graph G(V, E) and two vertices v1 and v2(as integers), find and print the path from v1 to v2 (if exists). Print nothing if there is no path between v1 and v2.
Find the path using BFS and print the shortest path available.
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
map<int, int>data;




int getpathbfs(int** edges, int n, int sv, int ev, bool* visited){
    
   queue<int>q;
    q.push(sv);
    int br=0;
    visited[sv]=true;
    while(!q.empty()){
        int current_vertex=q.front();
        q.pop();
    for(int i=0; i<n; i++){
        if(i==current_vertex)
            continue;
        if(edges[current_vertex][i]==1 && !visited[i]){
            visited[i]=true;
            q.push(i);
            
           // cout<<i<<" "<<current_vertex;
                data.insert(pair<int, int>(i, current_vertex));
            
            if(i==ev){
                br=1;
                break;
            }
        }
     }
        if(br==1)
            break;
   }
    
    map<int,int> :: iterator it;
    it = data.find(ev);
    if(it == data.end()){
        return 0;
    }
    else{
       ans.push_back(it->first);
       // cout<<it->first;
        int an=ev;
        while(an!=sv){
        an = it->second;
            ans.push_back(an);
         //   cout<<an;
            it = data.find(an);
        }
        
    }
    return 1;
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
    int sv, ev;
    cin>>sv>>ev;
    bool* visited = new bool[n];
    for(int i=0; i<n; i++){
        visited[i] = false;
    }
    vector<int> :: iterator it;
    if(getpathbfs(edges, n, sv, ev, visited)){
        for(it=ans.begin(); it!=ans.end(); it++){
            cout<<*it<<" ";
        }
    }
    
    for(int i=0; i<n; i++){
        delete [] edges[i];
    }
    delete [] edges;
    
    return 0;
}
