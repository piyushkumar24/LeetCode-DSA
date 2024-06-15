class Solution {
public:
    double maxProbability(int n, vector<vector<int>>& edges, vector<double>& succProb, int start_node, int end_node) {
        vector<pair<int, double>>adj[n];
        for(int i=0;i<edges.size();i++){
            adj[edges[i][0]].push_back({edges[i][1], succProb[i]});
            adj[edges[i][1]].push_back({edges[i][0], succProb[i]});
        }
        vector<int>vis(n, 0);
        priority_queue<pair<double, int>> pq;
        vector<double>dist(n,0);
        pq.push({1.00, start_node});
        while(!pq.empty()){
            int node=pq.top().second;
            double prob=pq.top().first;
            pq.pop();
            vis[node]=1;
            for(auto it:adj[node]){
                int adjNode=it.first;
                double pathProb=it.second;
                if(!vis[adjNode]){
                    if(prob * pathProb > dist[adjNode]){
                        dist[adjNode]=prob * pathProb;
                        pq.push({prob * pathProb, adjNode});
                    }
                }
            }
        }
        return dist[end_node];
    }
};