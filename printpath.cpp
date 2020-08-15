#include <bits/stdc++.h>
using namespace std;

bool getpath(int** adj, int n, int v1, int v2, bool* visited, vector<int> &vec){
    vec.push_back(v1); visited[v1] = true;
    if(v1 == v2) return true;
    for(int i = 0; i < n; i++)
        if(!visited[i] && adj[v1][i] == 1)
            if(getpath(adj, n, i, v2, visited, vec))
                return true;
    vec.pop_back();
    return false;
} 

int main(){
    int v = 4, e;
    // cin >> v >> e;
    int **adj = new int*[v];
    // vector<int> adj[v];
    for(int i = 0; i < v; i++){
        adj[i] = new int[v];
        for(int j = 0; j < v; j++)
            adj[i][j] = 0;
    }
    // int a, b;
    // for(int i = 0; i < e; i++){
    //     cin >> a >> b;
    //     adj[a][b] = 1;
    //     adj[b][a] = 1;
    // }
    adj[0][1] = 1;
    adj[0][2] = 1;
    adj[1][0] = 1;
    adj[1][2] = 1;
    adj[2][3] = 1;
    adj[3][3] = 1;

    int v1, v2;
    cin >> v1 >> v2;
    vector<int> vec;
    bool* visited = new bool[v]();
    if(getpath(adj, v, v1, v2, visited, vec)){
        for(int i = 0; i < vec.size(); i++){
            cout << vec[i] << " ";
        }
    }
    else{
        cout << "No path available";
    }
    return 0;
}