#include <iostream>
#include <vector>
using namespace std;

// Depth-First Search (DFS) function
void dfs(vector<vector<int>>& adj, int node, vector<int>& result, vector<bool>& visited) {
    visited[node] = true;  // Mark the current node as visited
    result.push_back(node);  // Add the current node to the result

    // Traverse all neighbors of the current node
    for (auto neighbor : adj[node]) {
        if (!visited[neighbor]) {
            dfs(adj, neighbor, result, visited);  // Recursive DFS call
        }
    }
}

int main() {
    int n, e; // Number of nodes and edges
    cout << "Enter number of nodes and edges: ";
    cin >> n >> e;

    vector<vector<int>> adj(n);  // Adjacency list for graph representation
    cout << "Enter edges (u v):" << endl;
    for (int i = 0; i < e; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);  // Assuming an undirected graph
    }

    vector<int> result;  // To store the DFS traversal
    vector<bool> visited(n, false);  // To track visited nodes

    cout << "\nStarting DFS from node 0:" << endl;
    dfs(adj, 0, result, visited);  // Start DFS from node 0

    // Print the result
    cout << "DFS Traversal: ";
    for (int node : result) {
        cout << node << " ";
    }
    cout << endl;

//     Complexity Analysis
// Time Complexity:
// O(V + E)
// Each node (V) is visited once.
// Each edge (E) is considered twice in an undirected graph.
// Space Complexity:
// O(V) for visited array.
// O(V) for result array.
// O(V) for recursion stack space (in the worst case of a skewed graph).
// Overall: O(V)

    return 0;
}
