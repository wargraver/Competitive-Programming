int ans=0;
void dfs(vector<vector<int>> adj,int vis[255][255],int i,int j){
    vis[i][j]=1;
    ans++;
    for(int st=0;st<adj.size();st++){
        if(adj[st][j]==1 && vis[st][j]==0) {
            dfs(adj,vis,st,j);
            break;
        }
    }
    for(int st=0;st<adj[i].size();st++){
        if(adj[i][st]==1 && vis[i][st]==0){
            dfs(adj,vis,i,st);
            break;
        }
    }
}
class Solution {
public:
    int countServers(vector<vector<int>>& grid) {
        ios_base::sync_with_stdio(false);
	cin.tie(NULL);
        int i,j,k,n;
        n=grid.size();
        int vis[255][255];
        vector<pair<int,int>> vect[n];
        memset(vis,0,sizeof(vis));
        int ct=0;
        for(i=0;i<n;i++){
            for(j=0;j<grid[0].size();j++){
            if(vis[i][j]==0 && grid[i][j]==1){
                ans=0;
                dfs(grid,vis,i,j);
                if(ans>1) ct+=ans;
            }
            }
        }
        return ct;
    }
};
