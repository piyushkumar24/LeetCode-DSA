class Solution {
public:
    int numEnclaves(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        vector<vector<int>>vis(n,vector<int>(m,0));
        queue<pair<int,int>>q;
        for(int row=0;row<n;row++){
            for(int col=0;col<m;col++){
                if(row==0 || row==n-1 || col==0 || col==m-1){
                    if(grid[row][col]==1){
                        vis[row][col]=1;
                        q.push({row,col});
                    }
                }
            }
        }
        int delrow[]={-1,0,+1,0};
        int delcol[]={0,+1,0,-1};
        int count=0;
        while(!q.empty()){
            int row=q.front().first;
            int col=q.front().second;
            q.pop();
            for(int i=0;i<4;i++){
                int nrow=row+delrow[i];
                int ncol=col+delcol[i];
                if(nrow>=0 && nrow<n && ncol>=0 && ncol<m && !vis[nrow][ncol] && grid[nrow][ncol]==1){
                    vis[nrow][ncol]=1;
                    q.push({nrow,ncol});
                }
            }
        }
        for(int row=0;row<n;row++){
            for(int col=0;col<m;col++){
                if(vis[row][col]==0 && grid[row][col]){
                    count++;
                }
            }
        }
        return count;
    }
};