#include<bits/stdc++.h>
using namespace std;

class Graph{
    int vertices;
    list<int>* adj;

    public:
    Graph(int V);
    void addEdge(int u, int v);
    bool isReachable(int s, int d);
};

Graph :: Graph(int V){
    this->vertices = V;
    adj = new list<int>[V];
}

void Graph :: addEdge(int u, int v){
    adj[u].push_back(v);
    adj[v].push_back(u);
}

bool Graph :: isReachable(int s, int d){
    if(s == d) return true;

    bool *visited = new bool[vertices];
    queue<int> q;
    q.push(s);
    visited[s] = true;
    while(!q.empty()){
        s = q.front();
        q.pop();
        for(auto itr = adj[s].begin(); itr!=adj[s].end(); itr++){
            if(*itr == d)
                return true;
            if(!visited[*itr]){
                visited[*itr] = true;
                q.push(*itr);
            }
        }
    }
    return false;
}

int main(){
    Graph g(4);

    g.addEdge(0, 1); 
    g.addEdge(0, 2); 
    g.addEdge(1, 2); 
    g.addEdge(2, 0); 
    g.addEdge(2, 3); 
    g.addEdge(3, 3); 

    int s, d;
    cout << "Enter the nodes between which the path is to be checked: ";
    cin >> s >> d;

    bool ans = g.isReachable(s, d);
    if(ans) cout << "True";
    else cout << "False";
    return 0;
}