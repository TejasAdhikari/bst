#include<bits/stdc++.h>
using namespace std;

class Graph{
    int vertices;
    list<int>* adj;

    public:
    Graph(int V);
    void addEdge(int u, int v);
    void BFS(int s);
};

Graph :: Graph(int V){
    this->vertices = V;
    adj = new list<int>[V];
}

void Graph :: addEdge(int u, int v){
    adj[u].push_back(v);
    adj[v].push_back(u);
}

void Graph :: BFS(int s){
    int* parent = new int[vertices];
    int* level = new int[vertices];
    bool* visited = new bool[vertices];

    for(int i = 0; i < vertices; i++)
        visited[i] = false;

    visited[s] = true;
    parent[s] = -1;
    level[s] = 0;
    queue<int> q; q.push(s);
    cout << "BFS Traversal is:\n";
    while(!q.empty()){
        int u = q.front();
        cout<< u << " ";
        q.pop();
        for(auto itr = adj[u].begin(); itr!=adj[u].end(); itr++)
            if(!visited[*itr]){
                visited[*itr] = true;
                level[*itr] = level[u] + 1;
                parent[*itr] = u;
                q.push(*itr);
            }
    }
    cout << endl;
    cout << "Level of each node is:\n";
    for(int i = 0; i < vertices; i++)
        cout << level[i] << " ";
    cout << endl;
    
    cout << "Parent of each node is:\n";
    for(int i = 0; i < vertices; i++)
        cout << parent[i] << " ";
    cout << endl;
} 

int main(){
    // int vertices, edges;
    // cin >> vertices >> edges;
    // Graph g(vertices);
    // int a, b;
    // for(int i = 0; i < edges; i++){
    //     cin >> a >> b;
    //     g.addEdge(a, b);
    // }
    Graph g(4); 
    g.addEdge(0, 1); 
    g.addEdge(0, 2); 
    g.addEdge(1, 2); 
    g.addEdge(2, 0); 
    g.addEdge(2, 3); 
    g.addEdge(3, 3); 
  
    cout << "Following is Breadth First Traversal\n"; 
    g.BFS(0); 
    return 0;
}