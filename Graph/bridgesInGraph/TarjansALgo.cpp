#include<iostream>
#include<vector>
using namespace std;

int timer = 1;

/*
    Tarjan's Algorithm for finding Bridges in a Graph
    -------------------------------------------------
    - A bridge (or articulation edge) is an edge in a graph that, if removed, increases the number of connected components.
    - Tarjan's algorithm helps efficiently find all such bridges in an undirected graph.
    - This is useful in network analysis, circuit design, and any scenario where disconnection detection is important.
*/

void dfs(int node, int parent, vector<int> adj[], vector<bool>& vis, int tin[], int low[], vector<vector<int>>& bridges) {
    vis[node] = true;
    tin[node] = low[node] = timer++;  // Assign discovery and low-link values

    for (auto adjNode : adj[node]) {
        if (adjNode == parent) continue;  // Ignore the edge that led us here (parent edge)
        
        if (!vis[adjNode]) {  // If the adjacent node hasn't been visited, perform DFS
            dfs(adjNode, node, adj, vis, tin, low, bridges);
            low[node] = min(low[node], low[adjNode]);  // Update low-link value

            // Bridge condition: If low[adjNode] > tin[node], it means (node, adjNode) is a bridge
            if (low[adjNode] > tin[node]) {
                bridges.push_back({node, adjNode});  // Store the bridge
            }
        } else {
            // If the adjacent node is already visited, it means there's a back edge (a cycle)
            low[node] = min(low[node], tin[adjNode]);  // Update low-link value
        }
    }
}

/*
    Function: criticalConnections
    ------------------------------
    - This function finds all the critical connections (bridges) in an undirected graph.
    - The graph is represented as an adjacency list.
*/
vector<vector<int>> criticalConnections(int n, vector<vector<int>>& connections) {
    vector<int> adj[n];

    // Build adjacency list
    for (int i = 0; i < connections.size(); i++) {
        int u = connections[i][0];
        int v = connections[i][1]; 
        
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    vector<bool> vis(n, false);
    int tin[n], low[n];  // tin[] stores discovery time, low[] stores the lowest reachable node
    vector<vector<int>> bridges;

    // Start DFS from node 0 (assuming the graph is connected)
    dfs(0, -1, adj, vis, tin, low, bridges);

    return bridges;
}

int main() {
    /*
        Example Usage:
        --------------
        - Input a graph with 'n' nodes and 'e' edges.
        - Output the bridges in the graph.
    */

    int n, e;
    cout << "Enter number of nodes and edges: ";
    cin >> n >> e;

    vector<vector<int>> connections;
    cout << "Enter the edges (u v):" << endl;
    for (int i = 0; i < e; i++) {
        int u, v;
        cin >> u >> v;
        connections.push_back({u, v});
    }

    vector<vector<int>> bridges = criticalConnections(n, connections);

    cout << "Bridges in the graph are:\n";
    for (auto bridge : bridges) {
        cout << bridge[0] << " - " << bridge[1] << endl;
    }

    return 0;
}

/*
    Tarjan's Algorithm: Key Notes
    ------------------------------
    - **Why is it used?**
        - To find bridges in an undirected graph efficiently.
        - Used in network reliability, circuit connectivity, and bi-connected components in graphs.

    - **Where is it useful?**
        - In road and communication networks to identify critical links.
        - In detecting articulation points in graphs.
        - In designing networks that can withstand single points of failure.

    - **Why use Tarjan's Algorithm?**
        - A naive approach to finding bridges would require O(N * M) time complexity using DFS multiple times.
        - Tarjan's algorithm optimally finds bridges in **O(N + M)** time complexity using DFS and low-link values.

    - **Time Complexity:** 
        - **O(N + M)** (DFS traversal for all nodes and edges)

    - **Space Complexity:** 
        - **O(N + M)** (Adjacency list storage + recursion stack in worst case)
*/
