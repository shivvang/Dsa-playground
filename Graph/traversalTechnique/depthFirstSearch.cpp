#include<iostream>
#include<vector>
using namespace std;

 
 void dfs(vector<vector<int>>& adj, int node, vector<int>& result, vector<bool>& visited) {
    visited[node] = true; // Mark the node as visited
    result.push_back(node); // Add the node to the result
    
    for (auto it : adj[node]) {
        if (!visited[it]) {
            dfs(adj, it, result, visited); // Recursive DFS call
        }
    }
}


int main(){
    vector<vector<int>>& adj;  //assumed given in a question
    vector<int> result; // Empty vector to store DFS traversal
    vector<bool> visited(adj.size(), false); // Boolean vector for visited nodes
    
    dfs(adj, 0, result, visited); // Start DFS from node 0

    //cout result;
    return 0;
}
