#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int spanningTree(int V, vector<vector<int>> adj[]) {
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    
    int span = 0;
    pq.push({0, 0});  // {weight, node}

    vector<bool> visited(V, false);

    while (!pq.empty()) {
        auto it = pq.top();
        pq.pop();

        int wt = it.first;
        int node = it.second;

        if (visited[node]) continue;

        visited[node] = true;
        span += wt;

        for (auto edge : adj[node]) {
            int adjnode = edge[0];
            int edn = edge[1];
            if (!visited[adjnode]) {
                pq.push({edn, adjnode});
            }
        }
    }

    return span;
}

int main() {
    int V, E;
    cout << "Enter number of vertices and edges: ";
    cin >> V >> E;

    vector<vector<int>> adj[V];

    cout << "Enter edges (u v weight): " << endl;
    for (int i = 0; i < E; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        adj[u].push_back({v, w});
        adj[v].push_back({u, w}); // Because it's an undirected graph
    }

    int minSpanningTreeWeight = spanningTree(V, adj);
    cout << "Minimum Spanning Tree Weight: " << minSpanningTreeWeight << endl;


//     Intuition Behind the Algorithm (Prim’s Algorithm)

// What is Prim’s Algorithm?

// It is a greedy algorithm used to find the Minimum Spanning Tree (MST) of a connected graph.
// The MST is a subset of the edges that connects all nodes with the minimum total edge weight and no cycles.

// How it Works?

// Start with any node (usually node 0).
// Use a min heap (priority queue) to always pick the edge with the smallest weight.
// Add that edge to the MST and mark the connected node as visited.
// Continue adding the smallest available edges until all nodes are included in the MST.

// Time Complexity Analysis

// Prim’s algorithm using a priority queue and an adjacency list has a complexity of:

// O(E log V) where:

// V = Number of vertices (nodes).
// E = Number of edges.
// Breaking it Down:
// Pushing edges into priority queue →

// Each node is processed once → O(V)
// Each edge can be pushed once into pq → O(E)
// Priority Queue Operations →

// Insertion/deletion in min-heap (priority queue) takes O(log V)
// Since there are at most E insertions, this contributes O(E log V)

// Final Complexity →

// Overall, it takes O(E log V), which is efficient for large graphs.

// Space Complexity Analysis

// Adjacency List Storage → O(V + E)
// Visited Array → O(V)
// Priority Queue → O(E) in the worst case
// Total Space → O(V + E)

// Why Prim’s Algorithm Works Efficiently?
// It always picks the smallest available edge, ensuring that no extra weight is added.
// The priority queue (min-heap) helps efficiently find the minimum-weight edge in O(log V).
// Works well for dense graphs with many edges.


    return 0;
}
