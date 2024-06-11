class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        if(grid[0][0]==1) return -1;
        if(grid[n-1][m-1] == 1) return -1;
        if(n==1 and grid[0][0] == 0) return 1;
        queue<pair<int,pair<int,int>>> q;
        q.push({1,{0,0}});
        while(!q.empty()){
            int dis = q.front().first;
            int row = q.front().second.first;
            int col = q.front().second.second;
            q.pop();
            for(int deltrow=-1;deltrow<=1;deltrow++){
                for(int deltcol=-1;deltcol<=1;deltcol++){
                    int nrow=row+deltrow;
                    int ncol=col+deltcol;
                    if(nrow >= 0 && nrow < n && ncol>=0 && ncol<m && grid[nrow][ncol] == 0){
                        grid[nrow][ncol]=-1;
                        if(nrow == n-1 && ncol == m-1) return dis+1;
                        q.push({dis+1,{nrow,ncol}});
                    }
                }
            }
        }
        return -1;
    }
};