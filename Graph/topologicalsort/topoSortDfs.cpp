#include<iostream>
#include<vector>
#include<stack>
using namespace std;


 void dfs(vector<vector<int>>&adj,vector<bool>&visited,stack<int>&s,int start){
      visited[start] = true;
      
      for(auto adjnodes : adj[start] ){
          if(!visited[adjnodes]){
              dfs(adj,visited,s,adjnodes);
          }
      }
      
      s.push(start);
  }


int main(){

//     Topological Sort Notes


// Definition:

// A linear ordering of vertices such that for every directed edge u -> v, vertex u appears before vertex v in the ordering.

// Conditions:

// Directed Graph: Ensures directionality of edges to define ordering.
// Acyclic Graph: Cycles prevent valid ordering due to circular dependencies (e.g., 1 -> 2 -> 3 -> 1).

// Use Cases:

// Task scheduling with dependencies (e.g., prerequisites in a course).
// Resolving dependency graphs in compilers.
// Ordering nodes in workflow systems.

// Intuition:

// A DAG represents dependencies. Topological sort ensures that all dependencies (u) of a node (v) are resolved before v is processed.

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

    vector<int>result;
       vector<bool>visited(adj.size(),false);
       stack<int>s;
       
       for(int i = 0; i<adj.size(); i++ ){
          if(!visited[i]){
              dfs(adj,visited,s,i);
          }
       }
       
       while(!s.empty()){
           
           int top  = s.top();
           
           result.push_back(top);
           
           s.pop();
       }

       for(int i=0;i<result.size();i++){

        cout<<result[i]<<" ";

       }

    //   Time Complexity: O(V+E) (Process each vertex and edge once).
    //   Space Complexity: O(V)  (For stack, visited array, and recursion stack).

    return 0;
}