class Solution {
public:
    bool containsCycle(vector<vector<char>>& grid) {
        vector<pair<int,int>> freq;
        int i,j,k,n,m;
        n=grid.size();m=grid[0].size();
       // vector<vector<int>> vis(n,vector<int>(m,-1));
        int vis[n][m];
        memset(vis,-1,sizeof(vis));
        for(i=0;i<n;i++){
            for(j=0;j<m;j++){
                if(vis[i][j]==-1){
                    queue<tuple<int,int,int,int>> q;
                    q.push({i,j,-1,-1});
                    while(q.empty()==false){
                        auto [x,y,px,py]  = q.front();
                        //cout<<x<<" "<<y<<" "<<px<<" "<<py<<endl;
                        q.pop();
                        vis[x][y]=1;
                        if(x-1>=0){
                            if(vis[x-1][y]==-1 && grid[i][j]-'a'==grid[x-1][y]-'a') q.push({x-1,y,x,y});
                            else if(px!=x-1 && y!=py && grid[i][j]-'a'==grid[x-1][y]-'a') return true;
                        }
                         if(y-1>=0){
                            if(vis[x][y-1]==-1 && grid[i][j]-'a'==grid[x][y-1]-'a') q.push({x,y-1,x,y});
                            else if(px!=x && y-1!=py && grid[i][j]-'a'==grid[x][y-1]-'a') return true;
                        }
                         if(y+1<m){
                            // cout<<grid[i][j]-'a'<<" "<<grid[x][y+1]-'a'<<" "<<vis[x][y+1]<<endl;
                            if(vis[x][y+1]==-1 && grid[i][j]-'a'==grid[x][y+1]-'a') q.push({x,y+1,x,y});
                            else if(px!=x && y+1!=py && grid[i][j]-'a'==grid[x][y+1]-'a') return true;
                           // else continue;
                        }
                         if(x+1<n){
                           //   cout<<grid[i][j]-'a'<<" "<<grid[x][y+1]-'a'<<" "<<vis[x][y+1]<<endl;
                            if(vis[x+1][y]==-1 && grid[i][j]-'a'==grid[x+1][y]-'a') q.push({x+1,y,x,y});
                            else if(px!=x+1 && y!=py && grid[i][j]-'a'==grid[x+1][y]-'a') return true;
                        }
                    }
                }
            }
        }
        return false;
    }
};
