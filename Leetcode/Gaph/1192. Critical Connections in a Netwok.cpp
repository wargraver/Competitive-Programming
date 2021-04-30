int ct;
set<vector<int>> ans;
class Solution {
public:
    void dfs(int i,int vis[],int in[],int out[],vector<int> adj[],int par){
        ct++;vis[i]=1;in[i]=ct;out[i]=ct;
        for(auto x:adj[i]){
            if(vis[x]==0) dfs(x,vis,in,out,adj,i);
            if(par!=x) out[i] = min(out[i],out[x]);
        }
        for(auto x:adj[i]){
            if(par!=x){
                if(out[x]>in[i]){
                    vector<int>temp; 
                    temp.push_back(x);
                    temp.push_back(i);
                    if(ans.find(temp)==ans.end()){
                        reverse(temp.begin(),temp.end());
                        if(ans.find(temp)==ans.end()) ans.insert(temp);
                    }
                }
            }
        }
    }
    vector<vector<int>> criticalConnections(int n, vector<vector<int>>& con) {
        int i,j,k,m;ct=0;
        int in[n],out[n],vis[n];
        ans.clear();
        vector<int> adj[n];
        for(i=0;i<con.size();i++){
            adj[con[i][1]].push_back(con[i][0]);
            adj[con[i][0]].push_back(con[i][1]);
        }
        memset(vis,0,sizeof(vis));
        dfs(0,vis,in,out,adj,-1);
        vector<vector<int>> answer;
        for(auto it=ans.begin();it!=ans.end();it++){
            answer.push_back(*it);
        }
        return answer;
    }
};
