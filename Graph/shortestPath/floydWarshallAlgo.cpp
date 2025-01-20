#include <bits/stdc++.h>
using namespace std;

/**
 * Floyd-Warshall Algorithm for All-Pairs Shortest Path
 * Works with negative weights and detects negative weight cycles.
 *
 * @param mat Adjacency matrix of the graph, where:
 *      - `mat[i][j]` is the weight of edge (i → j)
 *      - `-1` represents no direct edge (converted to infinity)
 */
void shortestDistance(vector<vector<int>>& mat) {
    int n = mat.size();
    
    // Step 1: Initialize the matrix
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (mat[i][j] == -1) {
                mat[i][j] = 1e9; // Treat no edge as "infinity"
            }
            if (i == j) {
                mat[i][j] = 0; // Distance to itself is always 0
            }
        }
    }

    // Step 2: Apply Floyd-Warshall Algorithm
    for (int k = 0; k < n; k++) { // Intermediate node
        for (int i = 0; i < n; i++) { // Source node
            for (int j = 0; j < n; j++) { // Destination node
                if (mat[i][k] != 1e9 && mat[k][j] != 1e9) {
                    mat[i][j] = min(mat[i][j], mat[i][k] + mat[k][j]);
                }
            }
        }
    }

    // Step 3: Detect negative weight cycles
    for (int i = 0; i < n; i++) {
        if (mat[i][i] < 0) {
            cout << "Negative weight cycle detected!" << endl;
            return;
        }
    }

    // Step 4: Convert unreachable nodes back to -1
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (mat[i][j] == 1e9) {
                mat[i][j] = -1;
            }
        }
    }
}

int main() {
    int n;
    cout << "Enter number of nodes: ";
    cin >> n;

    vector<vector<int>> mat(n, vector<int>(n));

    cout << "Enter adjacency matrix (use -1 for no direct edge):\n";
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> mat[i][j];
        }
    }

    shortestDistance(mat);

    cout << "Shortest distance matrix:\n";
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cout << (mat[i][j] == -1 ? "INF" : to_string(mat[i][j])) << " ";
        }
        cout << endl;
    }

//     Time & Space Complexity
// Time Complexity: O(N ^ 3)
// Three nested loops iterate over all combinations.
// This makes it slower than Dijkstra (O((V+E)logV)) but useful for dense graphs.
// Space Complexity: O(N ^  2)

// Why is Floyd-Warshall a Multi-Source Shortest Path Algorithm?

// Unlike Dijkstra or Bellman-Ford (which find shortest paths from a single source),
// Floyd-Warshall finds shortest paths between all pairs of nodes simultaneously.
// This makes it ideal for dense graphs where we need shortest paths between every pair.

// How Does It Detect Negative Cycles?
// After running the algorithm, if mat[i][i] (distance from a node to itself) becomes negative, it means:
// The node is part of a negative weight cycle.
// We detect this and terminate the algorithm.

// When to Use Floyd-Warshall?
// ✅ Graph is dense (𝐸≈𝑁 ^ 2)
// ✅ Need shortest paths for all pairs
// ✅ Graph contains negative weights
// ❌ Graph is sparse (use Dijkstra instead)
// ❌ Graph is too large (avoid O(N 3) complexity)

// Key Takeaways
// 🔹 Floyd-Warshall finds the shortest paths for all node pairs efficiently.
// 🔹 Works well for dense graphs but is slow for large graphs.
// 🔹 Can detect negative weight cycles.
// 🔹 Uses dynamic programming with a distance matrix.




    return 0;
}
