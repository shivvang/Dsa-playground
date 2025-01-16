#include <iostream>
#include <vector>
#include <stack>
#include <climits> // For INT_MAX
using namespace std;

// Function for topological sort using DFS
void toposort(vector<vector<pair<int, int>>>& adj, vector<bool>& vis, stack<int>& st, int node) {
    vis[node] = true;

    for (auto it : adj[node]) {
        if (!vis[it.first]) {
            toposort(adj, vis, st, it.first);
        }
    }

    st.push(node);
}

int main() {
    int V, E;
    cin >> V >> E;

    // Adjacency list representation for graph
    vector<vector<pair<int, int>>> adj(V);

    // Input edges
    for (int i = 0; i < E; i++) {
        int u, v, wt;
        cin >> u >> v >> wt;
        adj[u].push_back({v, wt});
    }

    // Topological sorting
    vector<bool> vis(V, false);
    stack<int> st;

    
    for (int i = 0; i < V; i++) {
        if (!vis[i]) {
            toposort(adj, vis, st, i);
        }
    }

    // Initialize distances with infinity
    vector<int> dis(V, INT_MAX);
    dis[0] = 0; // Assuming source node is 0



    

    // Process nodes in topological order
    while (!st.empty()) {
        int topNode = st.top();
        st.pop();

        if (dis[topNode] != INT_MAX) {
            for (auto it : adj[topNode]) {
                int neighbor = it.first;
                int weight = it.second;

                if (dis[topNode] + weight < dis[neighbor]) {
                    dis[neighbor] = dis[topNode] + weight;
                }
            }
        }
    }

    // Print distances
    for (int i = 0; i < V; i++) {
        if (dis[i] == INT_MAX) {
            cout << "-1 ";
        } else {
            cout << dis[i] << " ";
        }
    }
    cout << endl;


//     Time Complexity
// Topological Sort:

// Each node is visited once, and each edge is processed once.
// Complexity: 
// O(V+E).


// Relaxation of Edges:
// Each edge is processed at most once (in topological order).
// Complexity: 
// O(E).

// Overall time complexity: 
// O(V+E).

// Space Complexity

// Adjacency List:
// Requires 
// O(V+E) space.

// Visited Array:
// Requires 
// O(V) space.


// Stack:
// Requires 
// O(V) space.


// Distance Array
// Requires 
// O(V) space.


// Overall space complexity: 
// O(V+E).



// The algorithm works because it combines topological sorting and edge relaxation to find the shortest paths in a Directed Acyclic Graph (DAG):

// Topological Sorting:

// Ensures nodes are processed in an order where every node's dependencies are processed before itself.
// This allows us to calculate the shortest paths in a single pass without revisiting nodes.

// Relaxation of Edges:

// For each node in topological order, we update the shortest path to its neighbors if passing through the current node offers a shorter path.
// Since the graph is a DAG, there are no cycles, and each edge is relaxed only once.

// This works because the topological order guarantees that we process a node only after all possible shorter paths to it are determined.

    return 0;
}
