// 📚 Connected and Disconnected Graphs
// A graph can either be connected or disconnected based on whether there’s a path between every pair of vertices.

// ✅ 1. Connected Graph
// A graph is connected if every vertex can be reached from any other vertex by following a series of edges.
// There are no isolated vertices or subgraphs.

// 📊 Example of a Connected Graph:

//     (1) — (2)
//      |      |
//     (3) — (4)
// In the above graph:

// Every vertex can reach every other vertex either directly or indirectly.
// The graph is fully connected.

// 🧠 Key Observations:
// A connected graph has a single connected component.
// Traversals (DFS/BFS) starting from any vertex will visit all vertices.

// ✅ 2. Disconnected Graph
// A graph is disconnected if there exist two vertices such that no path exists between them.
// It can have multiple connected components or isolated vertices.

// 📊 Example of a Disconnected Graph:
/
//     (1) — (2)          (4)
//        \               
//         (3)

// Component 1: (1) — (2) — (3)
// Component 2: (4) (isolated vertex)

// 🧠 Key Observations:
// A disconnected graph has more than one connected component.
// Traversing (DFS/BFS) from one component won’t cover vertices in other components.


// 📝 Handling Connected and Disconnected Graphs

// ✅ 1. Identifying Connected Components:
// To identify all connected components, start traversal (DFS/BFS) from every unvisited vertex.

// Each traversal will cover one component.
// ✅ 2. Checking if a Graph is Connected:

// Perform DFS or BFS from any vertex.
// If all vertices are visited, the graph is connected.
// If some vertices are not visited, the graph is disconnected.

// ✅ 3. Counting Components:
// Start a traversal from every unvisited node.
// Every time a new traversal starts, increment the component count.

#include <iostream>
#include <vector>
using namespace std;

int main(){

    vector<int> adj[100];
    vector<bool> visited(100, false);

    int n, m; // n = vertices, m = edges
    cin >> n >> m;

    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u); // Undirected graph
    }

    int connectedComponents = 0;
    for (int i = 1; i <= n; i++) {
        if (!visited[i]) {
            somealgo(i); // Start DFS from this node
            connectedComponents++;
        }
    }

    cout << "Number of connected components: " << connectedComponents << endl;
    return 0;
}