#include <bits/stdc++.h>
using namespace std;

vector<int> dijkstra(vector<vector<pair<int, int>>> &adj, int src) {
    vector<int> dis(adj.size(), INT_MAX);
    
    // Min-heap (priority queue)
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

    pq.push({0, src});
    dis[src] = 0;

    while (!pq.empty()) {
        int distance = pq.top().first;
        int node = pq.top().second;
        pq.pop();

        // Process adjacent nodes
        for (const auto& adjNodes : adj[node]) {
            int adjnode = adjNodes.first;
            int edgeweight = adjNodes.second;

            // Relaxation step
            if (distance + edgeweight < dis[adjnode]) {
                dis[adjnode] = distance + edgeweight;
                pq.push({dis[adjnode], adjnode});
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

// Time Complexity: O((V+E)logV)
// Space Complexity: O(V+E)

    return 0;
}
