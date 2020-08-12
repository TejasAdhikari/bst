#include<bits/stdc++.h>
using namespace std;

class Graph{
    int vertices;
    list<int>* adj;

    public:
    Graph(int V);
    void addEdge(int u, int v);
    void DFS_visit(int s, bool* visited);
    void DFS();
};

Graph :: Graph(int V){
    this->vertices = V;
    adj = new list<int>[V];
}

void Graph :: addEdge(int u, int v){
    adj[u].push_back(v);
    adj[v].push_back(u);
} 

void Graph :: DFS_visit(int s, bool* visited){
    stack<int> st;
    st.push(s); visited[s] = true;
    while(!st.empty()){
        int v = st.top(); st.pop();
        cout << v << " ";
        for(auto itr = adj[v].begin(); itr != adj[v].end(); itr++)
            if(!visited[v]){
                visited[v] = true;
                st.push(v);
            }
    }
    cout << endl;
}

void Graph ::  DFS(){
    bool* visited = new bool[vertices];
    for(int i = 0; i < vertices; i++)
        visited[i] = false;
    for(int i = 0; i < vertices; i++)
        if(!visited[i])
            DFS_visit(i, visited);
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
  
    cout << "Following is Depth First Traversal\n"; 
    g.DFS(); 
    return 0;
}