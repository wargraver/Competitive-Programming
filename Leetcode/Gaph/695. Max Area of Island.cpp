class Solution {
public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int i,j,k,n,m,ct=0;
        n = grid.size();
        m = grid[0].size();
        int vis[n+1][m+1];
        for(i=0;i<=n;i++){
            for(j=0;j<=m;j++) vis[i][j]=0;
        }
        int ans=0;
        for(i=0;i<n;i++){
            for(j=0;j<m;j++){
                queue<tuple<int,int,int>> q;
                if(grid[i][j]==1 && vis[i][j]==0){
                    q.push({i,j,1});int temp=0;
                    while(q.empty()==false){
                        auto [x,y,area] = q.front();
                        
                       // cout<<x<<" "<<y<<" "<<temp<<endl;
                        q.pop();
                        if(vis[x][y]==1) continue;
                        temp++;
                        vis[x][y]=1;
                        ans  = max(ans,temp);
                        if(x-1>=0){
                            if(grid[x-1][y]==1 && vis[x-1][y]==0) q.push({x-1,y,area+1});
                        }
                        if(x+1<n){
                             if(grid[x+1][y]==1 && vis[x+1][y]==0) q.push({x+1,y,area+1});
                        }
                        if(y-1>=0){
                             if(grid[x][y-1]==1 && vis[x][y-1]==0) q.push({x,y-1,area+1});
                        }
                        if(y+1<m){
                             if(grid[x][y+1]==1 && vis[x][y+1]==0) q.push({x,y+1,area+1});
                        }
                    }
                }
            }
        }
        return ans;
    }
};
