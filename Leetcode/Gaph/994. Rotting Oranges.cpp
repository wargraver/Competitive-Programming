class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int i,j,k,n,m,ct=0;
        n=grid.size();
        m=grid[0].size();
        int vis[n][m];
        memset(vis,-1,sizeof(vis));
        queue<tuple<int,int,int>> q;
        for(i=0;i<n;i++){
            for(j=0;j<m;j++){
                if(grid[i][j]==2)  q.push({i,j,0});
                if(grid[i][j]==1 or grid[i][j]==2) ct++;
            }
        }
        int ans=0;
        while(q.empty()==false){
            auto [x,y,time] = q.front();
            q.pop();
            if(vis[x][y]==1) continue;
            else vis[x][y]=1;
            ans = max(ans,time);
            ct--;
            if(x-1>=0){
                if(grid[x-1][y]==1) q.push({x-1,y,time+1});
            }
            if(x+1<n){
                if(grid[x+1][y]==1) q.push({x+1,y,time+1});
            }
            if(y+1<m){
                if(grid[x][y+1]==1) q.push({x,y+1,time+1});
            }
            if(y-1>=0){
                if(grid[x][y-1]==1) q.push({x,y-1,time+1});
            }
        }
        if(ct!=0) return -1;
        return ans;
    }
};
