class Solution {
public:
    int swimInWater(vector<vector<int>>& grid) {
        int i,j,k,n,m,ct=1e9;
        queue<tuple<int,int,int>> q;
        n = grid.size();m = grid[0].size();
        q.push({0,0,0});
        int vis[n][m];
        memset(vis,1000000,sizeof(vis));
        
        while(q.empty()==false){
            auto [x,y,time] = q.front();
           // cout<<x<<" "<<y<<" "<<time<<endl;
            q.pop();
            if(x==n-1 && y==m-1){
                ct = min(ct,time);
                continue;
            }
            if(vis[x][y]<=time) continue;
            vis[x][y]=time;
            if(x-1>=0){
                if(time>=grid[x][y] && time>=grid[x-1][y]) q.push({x-1,y,time});
                else{
                    int t_new = max(grid[x][y],grid[x-1][y]);
                    q.push({x-1,y,t_new});
                }
            }
            if(x+1<n){
                 if(time>=grid[x][y] && time>=grid[x+1][y]) q.push({x+1,y,time});
                else{
                    int t_new = max(grid[x][y],grid[x+1][y]);
                    q.push({x+1,y,t_new});
                }
            }
            if(y-1>=0){
                 if(time>=grid[x][y] && time>=grid[x][y-1]) q.push({x,y-1,time});
                else{
                    int t_new = max(grid[x][y],grid[x][y-1]);
                    q.push({x,y-1,t_new});
                }
            }
            if(y+1<m){
                 if(time>=grid[x][y] && time>=grid[x][y+1]) q.push({x,y+1,time});
                else{
                    int t_new = max(grid[x][y],grid[x][y+1]);
                    q.push({x,y+1,t_new});
                }
            }
        }
        return ct;
    }
};
