#include<iostream>
#include<vector>
#include<stack>
using namespace std;

// Kosaraju's Algorithm is used to find the number of Strongly Connected Components (SCCs) in a directed graph.
// An SCC is a maximal subgraph where every node is reachable from every other node in that subgraph.

void dfs(int node, vector<vector<int>>& adj, vector<bool>& vis, stack<int>& st) {
    vis[node] = true;
    
    // Exploring all neighbors (standard DFS traversal)
    for (auto adjnode : adj[node]) {
        if (!vis[adjnode]) {
            dfs(adjnode, adj, vis, st);
        }
    }

    // Push the node onto the stack after visiting all its neighbors (stores nodes in finishing time order)
    st.push(node);
}

void dfsT(int node, vector<vector<int>>& adjT, vector<bool>& vis) {
    vis[node] = true;
    
    // Explore the transposed graph (Reverse edges)
    for (auto adjnode : adjT[node]) {
        if (!vis[adjnode]) {
            dfsT(adjnode, adjT, vis);
        }
    }
}

// Function to compute SCC count using Kosaraju's Algorithm
int kosaraju(vector<vector<int>> &adj) {
    int n = adj.size(); // Number of nodes
    vector<bool> vis(n, false);
    stack<int> st;

    // Step 1: Perform DFS and store nodes in stack in order of their finish times
    for (int i = 0; i < n; i++) {
        if (!vis[i]) {
            dfs(i, adj, vis, st);
        }
    }

    // Step 2: Build the transpose graph (reverse all edges)
    vector<vector<int>> adjT(n);
    for (int i = 0; i < n; i++) {
        for (auto it : adj[i]) {
            adjT[it].push_back(i); // Reverse edge direction
        }
    }

    // Step 3: Perform DFS on the transpose graph in order of decreasing finish time
    fill(vis.begin(), vis.end(), false); // Reset visited array
    int scc = 0; // Strongly Connected Components count

    while (!st.empty()) {
        int node = st.top();
        st.pop();
        if (!vis[node]) {
            scc++; // Found a new SCC
            dfsT(node, adjT, vis);
        }
    }

    return scc;  // Return the number of SCCs in the graph
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
    }

    cout << "Number of Strongly Connected Components: " << kosaraju(adj) << endl;

    return 0;
}

/*
====================================================================================
💡 **INTUITION BEHIND KOSARAJU'S ALGORITHM**
====================================================================================
1️⃣ **First DFS (Ordering Nodes by Finish Time)**
   - We perform a **Depth-First Search (DFS)** and store nodes in a stack in the order
     of their completion (finish time). This ensures that we always process nodes in
     the correct order in the second DFS.

2️⃣ **Graph Transposition (Reversing Edges)**
   - We create a **transpose graph** by reversing the direction of all edges.
     If an edge existed from `u -> v` in the original graph, it now goes from `v -> u`.
     This allows us to traverse SCCs independently in the second DFS.

3️⃣ **Second DFS (Finding SCCs)**
   - We pop nodes one by one from the stack and perform DFS on the transposed graph.
   - Since the nodes are processed in decreasing order of their original finish times,
     each DFS call finds one complete **Strongly Connected Component (SCC)**.
   - We count the number of DFS calls made in this step as our final SCC count.

====================================================================================
📌 **PURPOSE OF KOSARAJU'S ALGORITHM**
====================================================================================
✅ Used to **find SCCs in a directed graph**.
✅ Helps in **decomposing a directed graph into its strongly connected components**.
✅ Used in **2-SAT problems, dependency resolution, and circuit analysis**.

====================================================================================
⏳ **TIME COMPLEXITY**
====================================================================================
✅ **First DFS (storing finish order)**: O(V + E)
✅ **Graph Transposition (reversing edges)**: O(V + E)
✅ **Second DFS (finding SCCs)**: O(V + E)
👉 **Overall Complexity:** O(V + E)

====================================================================================
🛠️ **SPACE COMPLEXITY**
====================================================================================
✅ **Adjacency List Storage:** O(V + E)
✅ **Visited Array:** O(V)
✅ **Stack for DFS:** O(V)
✅ **Transpose Graph Storage:** O(V + E)
👉 **Overall Complexity:** O(V + E)

====================================================================================
⚠️ **WHY IS KOSARAJU'S ALGORITHM RESTRICTED TO DIRECTED GRAPHS?**
====================================================================================
- **In an undirected graph**, all nodes in a connected component are trivially reachable from one another.
- **SCCs are meaningful only in directed graphs**, where cycles and reachability vary.
- In **undirected graphs**, Kosaraju would simply return the number of connected components.

====================================================================================
🎯 **WHEN TO USE KOSARAJU'S ALGORITHM?**
====================================================================================
✅ **Finding SCCs in directed graphs**
✅ **Dependency analysis (e.g., package managers)**
✅ **Deadlock detection in systems**
✅ **2-SAT problems in Boolean algebra**
✅ **Graph condensation (reducing a graph into a DAG of SCCs)**
====================================================================================
*/
