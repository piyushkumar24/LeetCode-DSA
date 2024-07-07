class Solution {
public:
    int dfs(int r1,int c1,int r2,int c2,vector<vector<int>>& grid,vector<vector<vector<vector<int>>>> &dp){
        int n = grid.size();
        int m = grid[0].size();
        if(r1 >= n || r2 >= n || c1 >= m || c2 >= m || grid[r1][c1] == -1 || grid[r2][c2] == -1){
            return -1e9;
        }
        if(r1 == n-1 && c1 == n-1) return grid[r1][c1];
        if(dp[r1][c1][r2][c2] != -1) return dp[r1][c1][r2][c2];
        int ax = 0;
        if(r1 == r2 && c1 == c2) ax += grid[r1][c1];
        else ax += grid[r1][c1] + grid[r2][c2];
        int a = dfs(r1+1,c1,r2+1,c2,grid,dp);
        int b = dfs(r1+1,c1,r2,c2+1,grid,dp);
        int c = dfs(r1,c1+1,r2+1,c2,grid,dp);
        int d = dfs(r1,c1+1,r2,c2+1,grid,dp);
        ax += max({a,b,c,d});
        return dp[r1][c1][r2][c2] = ax;
    }
    int cherryPickup(vector<vector<int>>& grid) {
        int n=grid.size();
        vector<vector<vector<vector<int>>>> dp(n,vector<vector<vector<int>>>(n,vector<vector<int>>(n,vector<int>(n,-1))));
        return max(0,dfs(0,0,0,0,grid,dp));
    }
};