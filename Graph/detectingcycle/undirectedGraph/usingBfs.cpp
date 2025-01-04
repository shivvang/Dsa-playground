#include<iostream>
#include<vector>
#include<queue>
using namespace std;

bool bfs(vector<vector<int>>&adj,vector<bool>&visited,int src){
      visited[src] = true;
      queue<pair<int,int>>q; //{node itslef,node's parent}
      
      q.push({src,-1});
      
      while(!q.empty()){
          
         int node = q.front().first;
         int parent = q.front().second;
          
          q.pop();
          
          //touching neighbouring nodes
          for(auto it : adj[node]){
              if(!visited[it]){
                  visited[it] = true;
                  q.push({it,node});
              }
              else if(parent!=it){
                  //if current node is already visited by somebody else before us 
                  //and this guy is also trying to touch it it means there exist cycele
                  return true;
              }
          }
      }
      
      return false;
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

    vector<bool>visited(adj.size(),false);
        
        
        for(int i=0;i<adj.size();i++){
            if(!visited[i]){
               if(bfs(adj,visited,i)) cout <<true;
            }
        }
        
        cout<< false;

       //Time Complexity → O(N + 2E) for adjacent node calls + O(N) for disconnected components, though actual runtime is typically lower

      //Space Complexity → O(N) for queue + O(N) for visited
    return 0;
}