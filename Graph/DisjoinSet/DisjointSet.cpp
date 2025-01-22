#include<iostream>
#include<vector>
using namespace std;

class DisJointSet {
    vector<int> rank, parent, size;

public:
    // Constructor to initialize Disjoint Set
    DisJointSet(int n) {
        rank.resize(n + 1, 0);   // Rank array for union by rank
        parent.resize(n + 1, 0); // Parent array to store leader/ultimate parent
        size.resize(n + 1, 0);   // Size array for union by size

        // Initially, every element is its own parent (self-loop)
        for (int i = 0; i <= n; i++) {
            parent[i] = i;
            size[i] = 1;
        }
    }

    // **Find operation with Path Compression**
    // - Finds the **ultimate parent (leader)** of a node.
    // - Uses **path compression**: Directly connects node to the ultimate parent.
    // - Time Complexity: **O(α(n)) ≈ O(1)** (Inverse Ackermann function)
    int findUPar(int node) {
        if (node == parent[node]) return node; // Node is its own parent

        // **Path Compression**: Set parent[node] directly to ultimate parent
        return parent[node] = findUPar(parent[node]);
    }

    // **Union by Rank**
    // - Connects two components based on **rank (height of tree)**.
    // - Smaller tree is attached under the larger tree.
    // - Time Complexity: **O(α(n)) ≈ O(1)**
    void unionByRank(int u, int v) {
        int ulp_u = findUPar(u); // Find ultimate parent of u
        int ulp_v = findUPar(v); // Find ultimate parent of v

        if (ulp_u == ulp_v) return; // Already in the same component

        // Attach smaller rank tree to larger rank tree
        if (rank[ulp_u] < rank[ulp_v]) {
            parent[ulp_u] = ulp_v;
        }
        else if (rank[ulp_v] < rank[ulp_u]) {
            parent[ulp_v] = ulp_u;
        }
        else { 
            // If ranks are equal, attach one under the other and increase rank
            parent[ulp_u] = ulp_v;
            rank[ulp_v]++;  // Increase rank of the new root
        }
    }

    // **Union by Size**
    // - Connects two components based on **size (number of nodes in component)**.
    // - Smaller component is attached under the larger component.
    // - Time Complexity: **O(α(n)) ≈ O(1)**
    void unionBySize(int u, int v) {
        int ulp_u = findUPar(u);
        int ulp_v = findUPar(v);

        if (ulp_u == ulp_v) return; // Already in the same component

        // Attach smaller component to larger component
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

int main() {
    // **Disjoint Set (Union-Find)**
    // - Used for **dynamic connectivity** in graphs.
    // - Operations: **Find Parent, Union by Rank, Union by Size**.

    DisJointSet ds(7);

    // Performing unions
    ds.unionByRank(1, 2);
    ds.unionByRank(2, 3);
    ds.unionByRank(4, 5);
    ds.unionByRank(6, 7);
    ds.unionByRank(5, 6);

    // **Checking connectivity between 3 and 7**
    // - If both have the same ultimate parent, they are in the same component.
    if (ds.findUPar(3) == ds.findUPar(7)) 
        cout << "Same\n";
    else 
        cout << "Not Same\n";

    // **Now connect 3 and 7**
    ds.unionByRank(3, 7);

    return 0;


//     📝 Notes on Disjoint Set (Union-Find)
// What is Disjoint Set (Union-Find)?
// A data structure to manage dynamic sets of elements that are disjoint (non-overlapping).

// It supports two operations:

// Find (findUPar) → Determines the leader (root) of a set.
// Union (unionByRank / unionBySize) → Merges two sets into one.
// Used in dynamic graphs where components change due to merging.

// Why Do We Use This?

// Efficient handling of connectivity problems in graphs.
// Faster than adjacency list-based graph traversal for certain applications.
// Supports dynamic merging of components.

// ⏳ Time Complexity

// Operation	Without Path Compression	With Path Compression
// Find Parent	O(log n)	O(α(n)) ≈ O(1)
// Union by Rank	O(log n)	O(α(n)) ≈ O(1)
// Union by Size	O(log n)	O(α(n)) ≈ O(1)

// Breaking Down Time Complexity

// Without Path Compression: The tree may become skewed (O(log n)).
// With Path Compression: Almost flat tree, making operations nearly constant (O(1)).
// Inverse Ackermann Function (O(α(n))):
// It grows extremely slowly.
// For all practical cases, α(n) ≤ 4 even for n = 10^18.

// 🗂 Space Complexity

// Parent Array → O(V)
// Rank/Size Array → O(V)
// Total: O(V) (Linear in the number of nodes)

// 📌 Applications of Disjoint Set

// Graph Algorithms

// Kruskal’s Algorithm for Minimum Spanning Tree (MST)
// Connected Components in a graph
// Cycle Detection in an undirected graph
// Dynamic Connectivity Problems

// Network Connectivity (checking if two computers are in the same network)
// Social Networks (finding mutual friends or communities)
// Game Development

// Merging connected regions in tile-based games
// Image Processing

// Grouping connected pixels in image segmentation
// Physics Simulations

// Particle clustering and merging dynamic sets of particles

}
