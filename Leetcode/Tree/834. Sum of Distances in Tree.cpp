int ans=0;
class Solution {
public:
    void dfs2(int i,vector<int> adj[],int parent[],int nodes[],int ans2,vector<int>& temp){
            int k = parent[i];
            if(k==-1){
                temp[i] = ans2;
                for(auto x:adj[i]){
                    if(x!=parent[i]) dfs2(x,adj,parent,nodes,ans2,temp);
                }
            }
            else{
                int nodes_left = nodes[parent[i]]-nodes[i];
                ans2-=nodes[i];
                ans2+=nodes_left;
                temp[i] = ans2;
                nodes[i] = nodes[parent[i]];
                 for(auto x:adj[i]){
                    if(x!=parent[i]) dfs2(x,adj,parent,nodes,ans2,temp);
                }
            }
    }
    int dfs(int i,vector<int> adj[],int parent[],int nodes[],int level){
        ans+=level;nodes[i]=1;
        if(adj[i].size()==1 && parent[i]==adj[i][0]) return nodes[i];
        for(auto x:adj[i]){
            if(x!=parent[i]){
                parent[x]=i;
                nodes[i] += dfs(x,adj,parent,nodes,level+1);
            }
        }
        return nodes[i];
    }
    vector<int> sumOfDistancesInTree(int n, vector<vector<int>>& edges) {
        int i,j,k,m,ct=0;ans=0;
        m=edges.size();vector<int> temp(n,0);
        vector<int> adj[n];
        int parent[n], nodes[n];
        memset(nodes,0,sizeof(nodes));
        memset(nodes,-1,sizeof(parent));
        parent[0]=-1;
        for(i=0;i<m;i++){
            j = edges[i][0];
            k = edges[i][1];
            adj[j].push_back(k);
            adj[k].push_back(j);
        }
        int k1 = dfs(0,adj,parent,nodes,0);
      //  cout<<ans<<endl;
        //for(i=0;i<n;i++) cout<<nodes[i]<<endl;
        dfs2(0,adj,parent,nodes,ans,temp);
        return temp;
    }
};
