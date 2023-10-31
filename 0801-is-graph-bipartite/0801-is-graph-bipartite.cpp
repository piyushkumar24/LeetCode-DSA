// USING DFS TECHNIQUE:

class Solution {
private:
    bool dfs(int node, int col, int color[], vector<int> adj[]) {
        color[node] = col; 
        for (auto it : adj[node]) {
            if (color[it] == -1) {
                if (dfs(it, !col, color, adj) == false){
                    return false;
                } 
            }
            else if (color[it] == col) {
                return false; 
            }
        }
        
        return true; 
    }
public:
    bool isBipartite(vector<vector<int>>& graph) {
        int n = graph.size();
        int color[n];
        vector<int> adj[n];
        for (int i = 0; i < n; i++) {
            for (int it : graph[i]) {
                adj[i].push_back(it);
            }
        }
        for (int i = 0; i < n; i++) {
            color[i] = -1;
        }
        for (int i = 0; i < n; i++) {
            if (color[i] == -1) {
                if (dfs(i, 0, color, adj) == false) {
                    return false;
                }
            }
        }
        return true;
    }
};


// USING BFS TECHNIQUE:

// class Solution {
// private:
//     bool check(int start,int n, vector<vector<int>>&adj,int color[]){
//         queue<int>q;
//         color[start]=0;
//         q.push(start);
//         while(!q.empty()){
//             int node=q.front();
//             q.pop();
//             for(auto it:adj[node]){
//                 if(color[it]==-1){
//                     q.push(it);
//                     color[it]=!color[node];
//                 }
//                 else if(color[it]==color[node]){
//                     return false;
//                 }
//             }
//         }
//         return true;
//     }
// public:
//     bool isBipartite(vector<vector<int>>& graph) {
//         int n=graph.size();
//         int color[n];
//         for(int i=0;i<n;i++){
//             color[i]=-1;
//         }
//         vector<vector<int>>adj(n);
//         for(int i=0;i<n;i++){
//             for(auto it:graph[i]){
//                 adj[i].push_back(it);
//             }
//         }
//         for(int i=0;i<n;i++){
//             if(color[i]==-1){
//                 if(check(i,n,adj,color)==false){
//                     return false;
//                 }
//             }
//         }
//         return true;
//     }
// };