class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<pair<int,int>>adj[n+1];
        for(auto it:times){
            adj[it[0]].push_back({it[1],it[2]});
        }
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
        pq.push({0,k});
        vector<int>dist(n+1, INT_MAX);
        dist[k]=0;
        while(!pq.empty()){
            int dis=pq.top().first;
            int node=pq.top().second;
            pq.pop();
            for(auto it:adj[node]){
                int adjNode=it.first;
                int steps=it.second;
                if(dis+steps<dist[adjNode]){
                    dist[adjNode]=dis+steps;
                    pq.push({dis+steps,adjNode});
                }
            }
        }
        int ans=-1;
        for(int i=1;i<=n;i++){
            ans=max(ans,dist[i]);
        }
        if(ans==INT_MAX) return -1;
        return ans;
    }
};