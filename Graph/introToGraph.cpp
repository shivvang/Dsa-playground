// 📚 Graph 
// Graph: A collection of nodes (vertices) connected by edges.

// Nodes (Vertices): Fundamental units, represented as V.

// Edges: Connections between nodes, represented as E.

// Graph Representation:

// Adjacency Matrix (2D Array)
// Adjacency List (Array of Linked Lists/Arrays)

// Notation:  𝐺 = (𝑉,𝐸 )
// G=(V,E)


// Example:

// Graph Representation (Adjacency List):

// A -> B, C  
// B -> A, D  
// C -> A, D  
// D -> B, C  


// 🛠️ Components of a Graph

// Vertex (Node): Fundamental unit (e.g., A, B, C).

// Edge: Connects two vertices (e.g., A—B).

// Degree: Number of edges connected to a vertex.

        // In an undirected graph, the degree of a vertex (or node) is defined as:

        // 📌 Degree of a Vertex:
        // The number of edges connected to that vertex.
        // Each edge contributes 1 to the degree of a vertex.
        // Example:

        // mathematica

        //    A — B — C
        //    |     |
        //    D     E
        
        // Degree of A: 2 (Connected to B and D)
        // Degree of B: 3 (Connected to A, C, and E)
        // Degree of C: 1 (Connected to B)

        // 🧠 Key Points About Degree in Undirected Graphs:

        // The sum of degrees of all vertices is always twice the number of edges:(important)

        //total degree of graph = 2 * No Of Edges
        // Σ(degreeofallvertices)=2∗∣E∣

        // A vertex with degree 0 is called an isolated vertex.


        // In a directed graph, each edge has a direction, and we calculate in-degree and out-degree separately for each vertex.

        // 📌 In-Degree and Out-Degree in Directed Graphs

        // In-Degree:

        // The number of incoming edges to a vertex.
        // Edges pointing towards the vertex.

        // Out-Degree:

        // The number of outgoing edges from a vertex.
        // Edges pointing away from the vertex.

        // 📝 Key Difference:
        // In in-degree, we count edges arriving at the vertex.
        // In out-degree, we count edges leaving the vertex.

        // 🧠 Mathematical Property:
        // For a directed graph:

   
        // Σ(In-Degree of all vertices)=Σ(Out-Degree of all vertices)=∣E∣

        // Where |E| is the total number of edges.


        //🧩 Example of In-Degree and Out-Degree
        // mathematica
        // Copy code
        //     A → B → C
        //     ↑   ↓
        //     D ← E
        // In-Degree:

        // A: 0
        // B: 2 (From A and E)
        // C: 1 (From B)
        // D: 1 (From E)
        // E: 1 (From B)
        // Out-Degree:

        // A: 1 (To B)
        // B: 2 (To C and E)
        // C: 0
        // D: 1 (To A)
        // E: 1 (To D)



// Path: Sequence of edges connecting vertices.(a node cannot appear twice in a path)

// Cycle: A path that starts and ends at the same vertex.

// Connected Graph: All vertices are connected by edges.

// Disconnected Graph: Some vertices are not connected.



// 🔄 Types of Graphs

// Type	Description	Example

// Directed	Edges have direction (→)	A → B

// Undirected	Edges have no direction (—)	A — B

// Weighted	Edges have weights (costs)	A —5— B

// Unweighted	Edges have no weights	A — B

// Cyclic	Contains cycles	A → B → A

// Acyclic	No cycles	A → B → C

// Connected	All vertices are reachable	Graph (All connected)

// Disconnected	Some vertices are unreachable	Graph (Isolated nodes)

// Tree	Acyclic connected graph	Binary Tree

// Bipartite	Vertices can be divided into 2 sets	Two groups


// ⚙️ Graph Terminologies

// Adjacency: Two vertices connected by an edge are adjacent.

// Incidence: Edge is incident on its connected vertices.

// Isolated Vertex: Vertex with no edges.

// Complete Graph: Every vertex is connected to every other vertex.

// Subgraph: Part of a graph.

//with images for better understanding :- https://www.javatpoint.com/types-of-graph-in-data-structure