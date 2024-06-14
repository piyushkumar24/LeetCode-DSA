class Solution {
public:
    int swimInWater(vector<vector<int>>& grid) {
        int n = grid.size();
        if (n==1) return 0;
        vector<vector<bool>> vis(n, vector<bool>(n,0));
        vis[0][0] = true;
        int result = max(grid[0][0], grid[n - 1][n - 1]);
        priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> pq;
        pq.push({result, 0, 0});
        while (!pq.empty()) {
            vector<int> curr = pq.top();
            pq.pop();
            result = max(result, curr[0]);
            int dr []={-1,0,+1,0};
            int dc []={0,+1,0,-1};
            for (int i = 0; i < 4; i++) {
                int x = curr[1] + dr[i];
                int y = curr[2] + dc[i];
                if (x < 0 || x >= n || y < 0 || y >= n || vis[x][y]) continue;
                if (x == n - 1 && y == n - 1) return result;
                pq.push({grid[x][y], x, y});
                vis[x][y] = true;
            }
        }
        return -1;
    }
};