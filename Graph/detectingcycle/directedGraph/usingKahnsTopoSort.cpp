#include<iostream>
#include<vector>
#include<queue>
using namespace std;


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
    }
    
    
  vector<int> indegree(n + 1, 0);
    for (int i = 1; i <= n; i++) { 
        for (auto adjnode : adj[i]) {
            indegree[adjnode]++;
        }
    }

       queue<int> q;
    for (int i = 1; i <= n; i++) {
        if (indegree[i] == 0) {
            q.push(i);
        }
    }


   int counter = 0; 
    while (!q.empty()) {
        int node = q.front();
        q.pop();
        counter++;

        for (auto adjnode : adj[node]) {
            indegree[adjnode]--;
            if (indegree[adjnode] == 0) {
                q.push(adjnode);
            }
        }
    }


  cout<< (counter != n); 
//Time Complexity → O(N + 2E) for adjacent node calls 

      //Space Complexity → O(N) for queue + O(N) for visited
    return 0;
}