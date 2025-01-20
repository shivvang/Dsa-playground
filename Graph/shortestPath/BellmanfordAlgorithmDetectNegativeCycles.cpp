#include <bits/stdc++.h>
using namespace std;

/**
 * Bellman-Ford Algorithm to find shortest paths from the source node to all other nodes.
 * Handles graphs with negative weights and detects negative weight cycles.
 *
 * @param V     Number of vertices in the graph
 * @param edges List of edges where each edge is represented as {u, v, weight}
 * @param src   Source vertex
 * @return      Shortest distance array or {-1} if a negative weight cycle is detected.
 */
vector<int> bellmanFord(int V, vector<vector<int>>& edges, int src) {
    vector<int> dis(V, 1e8); // Initialize distances with a large number (infinity)
    dis[src] = 0; // Distance from source to itself is 0

    // **Relaxation process** (Run for V-1 iterations)
    // We relax all edges V-1 times to ensure the shortest paths are computed correctly.
    for (int i = 0; i < V - 1; i++) { 
        for (int j = 0; j < edges.size(); j++) { 
            int u = edges[j][0];
            int v = edges[j][1];
            int weight = edges[j][2];

            // If the current path through 'u' is shorter than known distance to 'v'
            if (dis[u] != 1e8 && dis[u] + weight < dis[v]) {
                dis[v] = dis[u] + weight;
            }
        }
    }

    // **Negative Cycle Detection**
    // If we can still relax any edge, then there's a negative weight cycle.
    for (int j = 0; j < edges.size(); j++) {
        int u = edges[j][0];
        int v = edges[j][1];
        int weight = edges[j][2];

        if (dis[u] != 1e8 && dis[u] + weight < dis[v]) {
            return {-1}; // Indicates negative weight cycle
        }
    }

    return dis; // Return shortest distances from source
}

int main() {
    int n, e; // Number of vertices and edges
    cout << "Enter number of nodes and edges: ";
    cin >> n >> e;

    vector<vector<int>> edges; // Edge list representation

    cout << "Enter edges (u v w):" << endl;
    for (int i = 0; i < e; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        edges.push_back({u, v, w});
    }

    int src;
    cout << "Enter source vertex: ";
    cin >> src;

    vector<int> shortestPaths = bellmanFord(n, edges, src);

    if (shortestPaths[0] == -1) {
        cout << "Negative weight cycle detected!" << endl;
    } else {
        cout << "Shortest distances from source " << src << ":\n";
        for (int i = 0; i < n; i++) {
            cout << "To " << i << ": " << (shortestPaths[i] == 1e8 ? "INF" : to_string(shortestPaths[i])) << endl;
        }
    }

//     Time & Space Complexity
// Time Complexity: O(V⋅E)
// The outer loop runs V−1 times.
// The inner loop iterates over all E edges.So, total time complexity: O(VE). Space Complexity: O(V)
// We store only the distance array dis, which takes 
// O(V) space.


// Why do we run the relaxation process for  V−1 times?  there are linear graph like this 1->2->3->4->5  for this distance array to befilled compelety with no negative we have to go through n-1 cycles
// A shortest path in a graph contains at most V−1 edges (in the worst case).
// If a path has more than V−1 edges, it must contain a cycle.

// Since Dijkstra's algorithm doesn't work with negative weights, we use Bellman-Ford to ensure all possible shorter paths are checked.
// Why do we perform an additional 𝑉
// Vth iteration to detect negative cycles?
// After V−1 

// relaxations, all shortest paths (without cycles) are computed.
// If we can still relax an edge, it means there exists a negative weight cycle.
// This is because a negative cycle allows us to infinitely decrease the path weight.
// If such an edge relaxation is possible, we return {-1} to indicate negative cycle presence.


// Why does Bellman-Ford only work for Directed Graphs, not Undirected Graphs?
// In undirected graphs, a negative weight cycle can be counted twice (once in each direction), causing incorrect results.
// Example:
// 1 --- (-5) --- 2
// This cycle would be relaxed twice, making Bellman-Ford unstable for undirected graphs.
// Solution: If using Bellman-Ford on an undirected graph, convert it to a directed graph by adding directed edges (u → v and v → u) carefully.


// Key Takeaways
// ✅ Works for graphs with negative weights
// ✅ Detects negative weight cycles
// ✅ Best for single-source shortest path problems when negative weights exist
// ❌ Slower than Dijkstra (O(VE) vs. O((V+E)logV))
// ❌ Does not work correctly for undirected graphs with negative weights



    return 0;
}
