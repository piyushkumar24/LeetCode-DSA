class Solution {

private:
    void bfs(int row, int col, vector<vector<int>>&vis, vector<vector<char>>&grid){
        vis[row][col]=1;
        int n=grid.size();
        int m=grid[0].size();
        queue<pair<int, int>>q;
        q.push({row, col});
        while(!q.empty()){
            int row=q.front().first;
            int col=q.front().second;
            q.pop();
            // Traverse the neibhours and mark them if it's a land
            for(int delrow=-1; delrow<=1; delrow++){
                for(int delcol=-1; delcol<=1; delcol++){
                    int nrow=row+delrow;
                    int ncol=col+delcol;
                    if(delrow!=0 && delcol!=0){
                        continue;
                    }
                    if(nrow>=0 && nrow<n && ncol>=0 && ncol<m && grid[nrow][ncol]=='1'&& !vis[nrow][ncol]){
                        vis[nrow][ncol]=1;
                        q.push({nrow, ncol});
                    }
                }
            }
        }
    }

public:
    int numIslands(vector<vector<char>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        vector<vector<int>>vis(n, vector<int>(m, 0));
        int cnt=0;
        for(int row=0; row<n; row++){
            for(int col=0; col<m; col++){
                if(!vis[row][col] && grid[row][col]=='1'){
                    cnt++;
                    bfs(row, col, vis, grid);
                }
            }
        }
        return cnt;
    }
};