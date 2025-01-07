#include<iostream>
#include<vector>
using namespace std;

bool dfs(int start, vector<vector<int>>& adj, vector<bool>& vis, vector<bool>& pathvis) {
    vis[start] = true;
    pathvis[start] = true;

    // Traversing adjacent nodes
    for (auto it : adj[start]) {
        // When node is not visited
        if (!vis[it]) {
            if (dfs(it, adj, vis, pathvis)) 
                return true;
        }
        // If the node is visited and is on the same path
        else if (pathvis[it]) {
            return true;
        }
    }

    pathvis[start] = false; // Backtrack
    return false;
}

int main(){

     int n, e; // Number of nodes and edges
    cout << "Enter number of nodes and edges: ";
    cin >> n >> e;

    vector<vector<int>> adj(n);  // Adjacency list for graph representation
    cout << "Enter edges (u v):" << endl;
    for (int i = 0; i < e; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
    }
     
     vector<vector<int>> adj(n+1);

    vector<bool> vis(n+1, false);
    vector<bool> pathvis(n+1, false);

   
    for (int i = 0; i <= n; i++) {
        if (!vis[i]) {
            if (dfs(i, adj, vis, pathvis)) 
                cout<< true;
        }
    }
    cout<< false;
//Time Complexity → O(v+ E) 

      //Space Complexity → O(N) path visited + O(N)  visited

      //BFS to detect a cycle in a directed graph, but it’s done using the Kahn's Algorithm (Topological Sort) approach,
      // not the traditional BFS traversal.   
    return 0;
}