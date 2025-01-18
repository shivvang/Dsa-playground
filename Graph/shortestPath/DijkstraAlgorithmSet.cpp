#include <bits/stdc++.h>
using namespace std;

vector<int> dijkstra(vector<vector<pair<int, int>>> &adj, int src) {
    vector<int> dis(adj.size(), INT_MAX);
    set<pair<int, int>> setkun;

    // Initialize source node
    dis[src] = 0;
    setkun.insert({0, src});

    while (!setkun.empty()) {
        auto it = *(setkun.begin()); // Get the node with the smallest distance
        int node = it.second;
        int distance = it.first;
        setkun.erase(it); // Remove processed node

        // Process adjacent nodes
        for (const auto& adjNodes : adj[node]) {
            int adjnode = adjNodes.first;
            int edgeweight = adjNodes.second;

            // Relaxation step
            if (distance + edgeweight < dis[adjnode]) {
                if (dis[adjnode] != INT_MAX) 
                    setkun.erase({dis[adjnode], adjnode});

                dis[adjnode] = distance + edgeweight;
                setkun.insert({dis[adjnode], adjnode});
            }
        }
    }

    return dis;
}

// Example Usage
int main() {
    int n = 5;  // Number of nodes
    vector<vector<pair<int, int>>> adj(n);

    // Graph edges (u, v, weight)
    adj[0].push_back({1, 2});
    adj[1].push_back({0, 2});

    adj[1].push_back({2, 4});
    adj[2].push_back({1, 4});

    adj[2].push_back({3, 1});
    adj[3].push_back({2, 1});

    adj[3].push_back({4, 3});
    adj[4].push_back({3, 3});

    int src = 0;
    vector<int> shortestDistances = dijkstra(adj, src);

    cout << "Shortest distances from source " << src << ":\n";
    for (int i = 0; i < n; i++) {
        cout << "Node " << i << ": " << shortestDistances[i] << endl;
    }

    return 0;

    // Time Complexity: O((V+E)logV)
// Space Complexity: O(V+E)
}
