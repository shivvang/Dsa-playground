#include<iostream>
#include<queue>
#include<vector>
using namespace std;

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
        adj[v].push_back(u);  
    }

    int src;
    cin>>src;

    int n = adj.size();
    vector<int> dis(n, 1e9); // Distance array with "infinity" initially
    dis[src] = 0;           // Distance to the source is 0
    queue<int> q;
    q.push(src);

    while (!q.empty()) {
        int node = q.front();
        q.pop();

        for (auto it : adj[node]) {
            if (dis[node] + 1 < dis[it]) {  // Relax the edge with weight 1
                dis[it] = 1 + dis[node];
                q.push(it);
            }
        }
    }

    // Replace 1e9 (infinity) with -1 for unreachable nodes
    for (int i = 0; i < n; i++) {
        if (dis[i] == 1e9) {
            dis[i] = -1;
        }
    }

    for(int i=0;i<n;i++){
        cout<<dis[i]<<",";
    }

//     Time Complexity
       // BFS Traversal:

       // Each node is visited once, and all its neighbors (edges) are processed.
      // Complexity: 
      // O(V+E), where 
     // V is the number of nodes, and  E is the number of edges.

     // Final Adjustment:
     // A single loop through 
     // V nodes to replace unreachable distances.
    // Complexity: 
    // O(V).


// Overall time complexity: 
// O(V+E).


// The algorithm uses BFS to find the shortest path in an unweighted graph:

// BFS Level Traversal:

// Each edge has a weight of 1, so BFS ensures nodes are processed in increasing order of distance.
// When visiting a node, we update its distance if a shorter path is found.
// Queue for Exploration:

// The queue processes nodes level by level, ensuring that the shortest distance is calculated first.
// Relaxation:

// For every neighbor, if the current path is shorter, update the distance and add the neighbor to the queue.
// BFS works because it guarantees the shortest path in unweighted graphs by exploring all nodes at distance d before moving to  d+1.

    return 0;
}