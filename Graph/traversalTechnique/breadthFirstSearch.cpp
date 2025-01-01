#include<iostream>
#include<vector>
#include<queue>
using namespace std;

int main(){
    //when adjacency matrix given 
    vector<vector<int>>adj;//zero base index asssuming
    vector<int>result(adj.size());
    vector<int>visited(adj.size());

    queue<int>q;
    q.push(0);
    visited[0] =  true;

    while(!q.empty()){
        int node = q.front();
        q.pop();
        result.push_back(node);

        for(int i=0;i<adj[node].size();i++){
            int subnode = adj[node][i];
            if(!visited[subnode]) {
                q.push(subnode);
                visited[subnode]=true;
            }
        }
    }
    //return result or print 

    //space complexity - o(n) visited + o(n) result + o(n) queue => o(n)
    //time complexity - o(n) //traversing all the nodes at once + o(2E) secondary loop runs for all the adjacent nodes
    return 0;
}