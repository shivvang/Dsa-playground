#include<iostream>
#include<vector>
#include<queue>
using namespace std;



// Function to detect a cycle using DFS in an undirected graph
bool detectcycledfs(int node, int parent, vector<vector<int>>& adj, vector<bool>& visited) {
    visited[node] = true; // Mark the current node as visited
    
    for (auto adjacentNode : adj[node]) {
        if (!visited[adjacentNode]) {
            if (detectcycledfs(adjacentNode, node, adj, visited)) {
                return true; // Cycle found
            }
        }
        // If adjacentNode is visited and is not the parent of the current node, it's a cycle
        else if (adjacentNode != parent) {
            return true; // Cycle found
        }
    }
    return false; // No cycle detected from this path
}


int main(){
     int n, e; // Number of nodes and edges
    cout << "Enter number of nodes and edges: ";
    cin >> n >> e;

    vector<vector<int>> adj(n);  // Adjacency list for graph representation
    cout << "Enter edges (u v):" << endl;
    for (int i = 0; i < e; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);  // Assuming an undirected graph
    }

    // The intuition behind this problem is: if we're performing BFS and encounter a node that was already touched from another direction
    // at the same level, and if this other node also points to the same destination, then we have found a cycle.
    vector<bool>visited(n,false);

    for(int i=0;i<n;i++){
        if(!visited[i]){
            if(detectcycledfs(i,-1,adj,visited) == true)cout<<"yes there exist cycle";
        }
    }

       //Time Complexity → O(N + 2E) for adjacent node calls + O(N) for disconnected components, though actual runtime is typically lower

      //Space Complexity → O(N) recusion stack space  + O(N) for visited
    return 0;
}