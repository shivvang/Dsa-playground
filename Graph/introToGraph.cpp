// 📚 Graph Representation in DSA
// When working with graphs, the input is often provided in a structured way, and there are two main ways to represent graphs in programming:

// Adjacency Matrix
// Adjacency List
// Let’s start step-by-step:

// 📝 1. Graph Input Format
// Typically, the input for a graph includes:

// Number of Vertices (V) – Total nodes in the graph.
// Number of Edges (E) – Total connections between nodes.

// Edges – Each edge specifies:
// Source node
// Destination node
// (Optional) Weight (for weighted graphs)

// 🔑 Example Input (Undirected Graph)
// 5 6  // 5 vertices, 6 edges
// 1 2
// 1 3
// 2 4
// 2 5
// 3 5
// 4 5

// 🔑 Example Input (Directed Weighted Graph)

// 4 4  // 4 vertices, 4 edges
// 1 2 5
// 1 3 3
// 2 4 2
// 3 4 4



// 🛠️ 2. Graph Representation Methods

// 📊 A. Adjacency Matrix

// A 2D Array of size  𝑉 × 𝑉
// V×V (where V = number of vertices).

// Matrix[i][j] = 1 (or weight) if there is an edge from i to j.

// Otherwise, Matrix[i][j] = 0.

// Example (Undirected Graph with 4 Vertices):


// Graph:

// 1 — 2
// |   |
// 3 — 4

// Adjacency Matrix: (its size is always nodees+1 * edges+1)

//    1 2 3 4
// 1 [0 1 1 0]
// 2 [1 0 1 1]
// 3 [1 1 0 1]
// 4 [0 1 1 0]

// Code Example (Adjacency Matrix in C++):


// int graph[4][4] = {
//     {0, 1, 1, 0},
//     {1, 0, 1, 1},
//     {1, 1, 0, 1},
//     {0, 1, 1, 0}
// };


//and if it was weighted undirected graph then we would replace 1's with weights


// 📊 Directed Graph Representation using Adjacency Matrix

// In a directed graph, edges have a direction (from one vertex to another). The Adjacency Matrix represents this using a 2D array where:

// Matrix[i][j] = 1 (or weight) → An edge exists from vertex i to vertex j.

// Matrix[i][j] = 0 → No edge exists from vertex i to vertex j.

// 📝 Example Directed Graph

//     (1) → (2)
//      ↓     ↑
//     (3) → (4)

// 📊 Adjacency Matrix Representation
// 1	2	3	4
// 1	0	1	1	0
// 2	0	0	0	1
// 3	0	0	0	1
// 4	0	1	0	0

// 🧠 Explanation:
// (1 → 2) → Matrix[1][2] = 1
// (1 → 3) → Matrix[1][3] = 1
// (2 → 4) → Matrix[2][4] = 1
// (3 → 4) → Matrix[3][4] = 1
// (4 → 2) → Matrix[4][2] = 1

// All other entries are 0, as no other edges exist.


// ✅ Pros:

// Easy to understand and implement.
// Fast to check if an edge exists between two nodes.
// ❌ Cons:

// Uses O(V²) memory, inefficient for sparse graphs.
// Adding/removing edges is expensive.


// 📋 B. Adjacency List

// Each vertex maintains a list of adjacent vertices.

// Efficient for sparse graphs.

// Can use Array of Vectors or Map of Lists in C++.

// Example (Undirected Graph with 4 Vertices):

// Graph:
// 1 — 2
// |   |
// 3 — 4

// Adjacency List:
// 1 -> 2, 3
// 2 -> 1, 3, 4
// 3 -> 1, 2, 4
// 4 -> 2, 3


// 📚 Directed Graph Representation using Adjacency List (Unweighted)
// In a directed graph, edges have a specific direction (from one vertex to another).
// The Adjacency List stores each vertex and a list of vertices it points to.

// 📝 Example Directed Graph (Unweighted)

//     (1) → (2)
//      ↓     ↓ 
//     (3) → (4)
// 📋 Adjacency List Representation

// 1 → 2, 3  
// 2 → 4  
// 3 → 4  
// 4 → (empty)

// 🧠 Explanation:
// 1 → 2 → Vertex 1 points to Vertex 2.
// 1 → 3 → Vertex 1 points to Vertex 3.
// 2 → 4 → Vertex 2 points to Vertex 4.
// 3 → 4 → Vertex 3 points to Vertex 4.

// Vertex 4 has no outgoing edges.

// ✅ Pros:

// Space-efficient, uses O(2 * E) memory.
// Adding/removing edges is easy.

// ❌ Cons:

// Checking if an edge exists between two nodes takes longer.


#include<iostream>
#include<vector>
using namespace std;


int main(){
    // n represent no of nodes
    // m represent no of edges

    int n , m;

   //📚 Graph Representation: Adjacency Matrix & Adjacency List (Weighted and Unweighted)

         //    📊 1. Adjacency Matrix Representation

        //    ✅ Undirected Graph (Unweighted)

        int adjMatrix[n+1][n+1] = {0}; // Initialize matrix with 0

        for (int i = 0; i < m; i++) {
            int u, v;
            cin >> u >> v; // Input edge (u, v)
            adjMatrix[u][v] = 1;
            adjMatrix[v][u] = 1; // Since it's undirected
        }

        // Time Complexity: O(1) per edge insertion.
        // Space Complexity: O(n²)

        // ✅ Directed Graph (Unweighted)

        for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v; // Input edge (u → v)
        adjMatrix[u][v] = 1;
        }

        // Time Complexity: O(1) per edge insertion.
        // Space Complexity: O(n²)

        //✅ Undirected Graph (Weighted)

        int adjMatrix[n+1][n+1] = {0}; // Initialize matrix with 0

        for (int i = 0; i < m; i++) {
            int u, v, weight;
            cin >> u >> v >> weight; // Input edge (u, v) with weight
            adjMatrix[u][v] = weight;
            adjMatrix[v][u] = weight; // Since it's undirected
        }

        // Time Complexity: O(1) per edge insertion.
        // Space Complexity: O(n²)

        //✅ Directed Graph (Weighted)

        int adjMatrix[n+1][n+1] = {0}; // Initialize matrix with 0

        for (int i = 0; i < m; i++) {
            int u, v, weight;
            cin >> u >> v >> weight; // Input edge (u → v) with weight
            adjMatrix[u][v] = weight;
        }
        // Time Complexity: O(1) per edge insertion.
        // Space Complexity: O(n²) 


        //📋 2. Adjacency List Representation
        
        //✅ Undirected Graph (Unweighted)

        vector<int> adjList[n+1];

        for (int i = 0; i < m; i++) {
            int u, v;
            cin >> u >> v; // Input edge (u, v)
            adjList[u].push_back(v);
            adjList[v].push_back(u); // Since it's undirected
        }
        // Time Complexity: O(1) per edge insertion.
        // Space Complexity: O(2E) ≈ O(E)

        // ✅ Directed Graph (Unweighted)


        for (int i = 0; i < m; i++) {
            int u, v;
            cin >> u >> v; // Input edge (u → v)
            adjList[u].push_back(v);
        }
        // Time Complexity: O(1) per edge insertion.
        // Space Complexity: O(E)

        //✅ Undirected Graph (Weighted)

        vector<pair<int, int>> adjListt[n+1];

        for (int i = 0; i < m; i++) {
            int u, v, weight;
            cin >> u >> v >> weight; // Input edge (u, v) with weight
            adjListt[u].push_back({v, weight});
            adjListt[v].push_back({u, weight}); // Since it's undirected
        }
        // Time Complexity: O(1) per edge insertion.
        // Space Complexity: O(2E) ≈ O(E)

        //✅ Directed Graph (Weighted)

        for (int i = 0; i < m; i++) {
            int u, v, weight;
            cin >> u >> v >> weight; // Input edge (u → v) with weight
            adjListt[u].push_back({v, weight});
        }

        // Time Complexity: O(1) per edge insertion.
        // Space Complexity: O(E)

    return 0;
}