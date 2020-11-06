/*
 Kruskal's Algorithm
Send Feedback
Given an undirected, connected and weighted graph G(V, E) with V number of vertices (which are numbered from 0 to V-1) and E number of edges.
Find and print the Minimum Spanning Tree (MST) using Kruskal's algorithm.
For printing MST follow the steps -
1. In one line, print an edge which is part of MST in the format -

v1 v2 w

where, v1 and v2 are the vertices of the edge which is included in MST and whose weight is w. And v1 <= v2 i.e. print the smaller vertex first while printing an edge.
2. Print V-1 edges in above format in different lines.
Note : Order of different edges doesn't matter.
Input Format :

Line 1: Two Integers V and E (separated by space)
Next E lines : Three integers ei, ej and wi, denoting that there exists an edge between vertex ei and vertex ej with weight wi (separated by space)

Output Format :

MST

Constraints :
2 <= V, E <= 10^5
Sample Input 1 :

4 4
0 1 3
0 3 5
1 2 1
2 3 8

Sample Output 1 :

1 2 1
0 1 3
0 3 5

*/
/*
1.Take input of edges
2.sort edges based on weight
3.create output array
4.check whether the edges are making a cycle or not
5.if not making a cycle, add them in output array
*/

#include<iostream>
#include<algorithm>
using namespace std;
class edge{
public:
	int source;
	int dest;
	int weight;
};

bool compare(edge e1, edge e2){
	return(e1.weight<e2.weight);
}

int find(int v, int *parent){
	if(parent[v]==v)
	return v;
	else
	return find(parent[v], parent);
}

void kruskals(edge *input, int v, int e){
	sort(input, input+e, compare); //sort edges on the basis of weight in increasing order

	edge *output = new edge[v-1]; //this array will conatin output edges
	int *parent = new int[v]; //this array will conatin the parent of all vertices

	for(int l=0; l<v; l++)
	parent[l] = l;

	int count =0;
	int i=0;

	while(count!= (v-1)){//add edges in output
		edge currentEdge = input[i];
		int source_parent = find(currentEdge.source, parent);//find the parent of source
		int dest_parent = find(currentEdge.dest, parent);//find the parent of destination

		if(source_parent != dest_parent){//if parent of source and destination are equal therefore they are forming a cycle and if not then they can be added in output array
			output[count] = currentEdge;
			parent[source_parent]=dest_parent; //update the  parent
			count++;
		}
		i++;
	}
//print the output
for(int k=0; k<v-1; k++){
	if(output[k].source<output[k].dest)
	cout<<output[k].source<<" "<<output[k].dest<<" "<<output[k].weight<<endl;
	else
	cout<<output[k].dest<<" "<<output[k].source<<" "<<output[k].weight<<endl;

}



}

int main(){
	int v, e; //v is no. of vertices and e is no of edges
	cin>>v>>e;
	edge *input = new edge[e]; //create an array of type edge and size e to hold all input edges
	for(int i=0; i<e; i++){
		int s, d, w;
		cin>>s>>d>>w;
		input[i].source = s;
		input[i].dest = d;
		input[i].weight = w;
	}

	kruskals(input, v, e);
	return 0;

}
