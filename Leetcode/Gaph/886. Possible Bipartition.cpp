class Solution {
public:
    bool dfs(int i,int parent,vector<int>& vis,vector<int>& col,int colour,vector<int> adj[]){
         vis[i]=1;
         col[i]=colour;
      // cout<<i<<" "<<col[i]<<endl;
         bool ans = false;
         for(auto x:adj[i]){
             //cout<<x<<" "<<i<<endl;
             if(x!=parent && vis[x]==0) {
                 ans = ans || dfs(x,i,vis,col,colour ^ 1,adj);
                 //cout<<1<<endl;
             }
             else if(x!=parent && vis[x]==1){
                 if(col[x]==colour ^ 1) continue;
                 else return true;
             }
             else continue;
         }
        return ans;
    }
    bool possibleBipartition(int N, vector<vector<int>>& dislikes) {
         int i,j,k,m,n=dislikes.size();
        vector<int> adj[N+1];
        for(i=0;i<dislikes.size();i++){
            adj[dislikes[i][0]].push_back(dislikes[i][1]);
            adj[dislikes[i][1]].push_back(dislikes[i][0]);
        }
        vector<int> vis(N+1,0);
        vector<int> col(N+1,-1);
        for(i=1;i<=N;i++){
            if(vis[i]==0){
                if(dfs(i,-1,vis,col,1,adj)) return false;
            }
        }
        return true;
    }
};
