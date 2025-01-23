#include <bits/stdc++.h>
using namespace std;

class Solution {
private:
    int timer = 1; // Global timer to track discovery time of nodes

    // Depth First Search (DFS) function to find articulation points
    void dfs(int node, int parent, vector<int> adj[], vector<int>& mark, vector<bool>& visited, int low[], int tin[]) {
        visited[node] = true;  // Mark the current node as visited
        low[node] = tin[node] = timer++;  // Assign discovery time and low-link value
        int child = 0;  // Count the number of children in DFS tree

        for (auto adjNode : adj[node]) {  // Traverse all adjacent nodes
            if (adjNode == parent) continue;  // Skip the parent node

            if (!visited[adjNode]) {  // If the adjacent node is not visited, perform DFS
                dfs(adjNode, node, adj, mark, visited, low, tin);

                // Update the low value of the current node based on the child
                low[node] = min(low[node], low[adjNode]);

                // Articulation Point Condition: If low[adjNode] >= tin[node], node is an articulation point
                if (low[adjNode] >= tin[node] && parent != -1) {
                    mark[node] = 1;  // Mark the node as an articulation point
                }
                child++;  // Increment the child count
            } else {
                // If the adjacent node is already visited, it's a back edge, so update the low value
                low[node] = min(low[node], tin[adjNode]);
            }
        }

        // Special case: If the node is the root and has more than 1 child, it's an articulation point
        if (parent == -1 && child > 1) {
            mark[node] = 1;
        }
    }

public:
    // Function to find all articulation points in the given graph
    vector<int> articulationPoints(int V, vector<int> adj[]) {
        vector<bool> visited(V, false);  // Visited array to track nodes
        int low[V], tin[V];  // Arrays to store low-link values and discovery times
        vector<int> mark(V, 0);  // Mark array to store articulation points

        for (int i = 0; i < V; i++) {
            if (!visited[i]) {
                dfs(i, -1, adj, mark, visited, low, tin);  // Start DFS if node is not visited
            }
        }

        vector<int> ans;
        for (int i = 0; i < V; i++) {
            if (mark[i] == 1) {
                ans.push_back(i);  // Store articulation points
            }
        }

        return ans.empty() ? vector<int>{-1} : ans;  // If no articulation points, return {-1}
    }
};


    int main() {
    int V, E;
    cout << "Enter number of vertices and edges: ";
    cin >> V >> E;

    vector<int> adj[V];  // Adjacency list representation of graph

    cout << "Enter edges (u v) (0-based index):" << endl;
    for (int i = 0; i < E; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);  // Since the graph is undirected
    }

    Solution obj;  // Create an instance of Solution class
    vector<int> result = obj.articulationPoints(V, adj);  // Call function to find articulation points

    cout << "Articulation Points: ";
    for (int point : result) {
        cout << point << " ";
    }
    cout << endl;

    return 0;


    
// Time and Space Complexity

// Time Complexity:

// DFS Traversal → O(V + E)
// Checking Articulation Conditions → O(1) per node
// Total Complexity → O(V + E)

// Space Complexity:
// Visited Array → O(V)
// Low & Tin Arrays → O(V)
// Mark Array → O(V)
// Adjacency List → O(V + E)
// Total Space Complexity → O(V + E)

// Where Can This Be Used?

// Network Analysis → Finding critical routers in a network.
// Power Grid Networks → Identifying weak points in electricity distribution.
// Road Networks → Determining critical junctions in city planning.
// Social Networks → Detecting influential users whose removal fragments the network.

    }