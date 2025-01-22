#include <iostream>
#include <vector>
#include <algorithm>  // Needed for sorting edges

using namespace std;

class DisJointSet {
    vector<int> rank, parent, size;

public:
    // Constructor to initialize the Disjoint Set
    DisJointSet(int n) {
        rank.resize(n + 1, 0);
        parent.resize(n + 1, 0);
        size.resize(n + 1, 0);

        // Every node is its own parent initially (self-rooted)
        for (int i = 0; i <= n; i++) {
            parent[i] = i;
            size[i] = 1;
        }
    }

    // Find function with path compression (reduces tree height)
    int findUPar(int node) {
        if (node == parent[node]) return node;
        return parent[node] = findUPar(parent[node]); // Path compression
    }

    // Union by Rank (connect smaller rank tree to larger)
    void unionByRank(int u, int v) {
        int ulp_u = findUPar(u);
        int ulp_v = findUPar(v);

        if (ulp_u == ulp_v) return; // Already in the same set

        if (rank[ulp_u] < rank[ulp_v]) {
            parent[ulp_u] = ulp_v;
        }
        else if (rank[ulp_v] < rank[ulp_u]) {
            parent[ulp_v] = ulp_u;
        }
        else { // If both have same rank, attach one to the other and increase rank
            parent[ulp_u] = ulp_v;
            rank[ulp_v]++;
        }
    }

    // Union by Size (connect smaller size tree to larger)
    void unionBySize(int u, int v) {
        int ulp_u = findUPar(u);
        int ulp_v = findUPar(v);

        if (ulp_u == ulp_v) return; // Already in the same set

        if (size[ulp_u] < size[ulp_v]) {
            parent[ulp_u] = ulp_v;
            size[ulp_v] += size[ulp_u];
        }
        else {
            parent[ulp_v] = ulp_u;
            size[ulp_u] += size[ulp_v];
        }
    }
};

class Solution {
public:
    // Function to find sum of weights of edges of the Minimum Spanning Tree using Kruskal's Algorithm.
    int spanningTree(int V, vector<vector<int>> adj[]) {
        vector<pair<int, pair<int, int>>> edges; // Stores edges in {weight, {node1, node2}} format

        // Step 1: Convert adjacency list to edge list
        for (int i = 0; i < V; i++) {
            for (auto it : adj[i]) {
                int adjnode = it[0];
                int wt = it[1];
                int node = i;
                
                edges.push_back({wt, {node, adjnode}});
            }
        }

        // Step 2: Sort edges by weight (greedy step)
        sort(edges.begin(), edges.end());

        // Step 3: Initialize Disjoint Set for cycle detection
        DisJointSet ds(V);
        int mstwt = 0; // Stores weight of Minimum Spanning Tree (MST)

        // Step 4: Iterate over sorted edges and apply Union-Find
        for (auto it : edges) {
            int wt = it.first;
            int u = it.second.first;
            int v = it.second.second;

            // If u and v belong to different components, include this edge in MST
            if (ds.findUPar(u) != ds.findUPar(v)) {
                mstwt += wt;
                ds.unionBySize(u, v); // Can use unionByRank as well
            }
        }

        return mstwt; // Returns the total weight of the MST
    }
};

/*
    🌟 Notes on Kruskal’s Algorithm and Disjoint Set:
    
    1️⃣ **What is this?**
       - This is **Kruskal's Algorithm** for finding the **Minimum Spanning Tree (MST)** in a weighted graph.
       - It follows a **greedy approach**, always picking the smallest weight edge that doesn’t form a cycle.

    2️⃣ **How does it work?**
       - Convert adjacency list into an edge list.
       - Sort all edges by weight (ascending).
       - Use **Disjoint Set (Union-Find)** to check if adding an edge forms a cycle.
       - If no cycle is formed, add the edge to MST.
       - Continue until MST has (V-1) edges.

    3️⃣ **Why Disjoint Set?**
       - To efficiently check if two nodes belong to the same component (cycle detection).
       - Supports **Union by Rank** and **Union by Size** for efficient merging.
       - Uses **Path Compression** to optimize find operations.

    4️⃣ **Time Complexity:**
       - Sorting edges: **O(E log E)**
       - Union-Find operations: **O(α(N)) ≈ O(1) (using path compression)**
       - Overall: **O(E log E)** (since sorting dominates)

    5️⃣ **Space Complexity:**
       - **O(V + E)** for storing edges and disjoint set data.

    6️⃣ **Applications of Kruskal’s Algorithm:**
       ✅ Network Design (LAN, Telephone lines)
       ✅ Road Construction
       ✅ Clustering in Machine Learning
       ✅ Image Segmentation (Computer Vision)

*/
