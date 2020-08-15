#include<bits/stdc++.h>
using namespace std;

bool isBipartite(vector<int> adj[], int v, bool visited[], int color[]){
    for(int u : adj[v]){
        if(!visited[i]){
            visited[i] = true;
            color[i] = !color[v];
            if(!isBipartite[adj, n, i, visited, color])
                return false;
        }
        else if(color[i] == color[v])
            return false;
    }
    return true;
}

int main(){
    Graph g(4); 
    g.addEdge(0, 1); 
    g.addEdge(0, 2); 
    g.addEdge(1, 2); 
    g.addEdge(2, 0); 
    g.addEdge(2, 3); 
    g.addEdge(3, 3);  
  
    vector<int> adj[5]; 
   
    vector<bool> visited(5); 
  
    vector<int> color(5); 

    visited[]
  
    if(isBipartite(adj, v, 0, visited, color))
        cout << "The graph is bipartite";
    else
        cout << "The graph is not bipartite";

    return 0;
}