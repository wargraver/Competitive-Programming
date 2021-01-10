vector<int> temp;
void dfs(int i,vector<int> adj[],int vis[]){
    vis[i]=1;
    temp.push_back(i);
    for(auto x:adj[i]){
        if(vis[x]==0) dfs(x,adj,vis);
    }
}
class Solution {
public:
    int minimumHammingDistance(vector<int>& s, vector<int>& t, vector<vector<int>>& swap) {
        int i,j,k,n,m,ct;
        n=s.size();ct=n;
        vector<int> adj[n+1];
        for(i=0;i<swap.size();i++){
            j=swap[i][0];
            k=swap[i][1];
            adj[j].push_back(k);
            adj[k].push_back(j);
        }
        int vis[n+1];
        memset(vis,0,sizeof(vis));
        for(i=0;i<n;i++){
            if(vis[i]==0){
                temp.clear();
                dfs(i,adj,vis);
                multiset<int> temp1,temp2;
                for(j=0;j<temp.size();j++){
                     temp1.insert(s[temp[j]]);
                     temp2.insert(t[temp[j]]);
                }
                for(auto it=temp1.begin();it!=temp1.end();it++){
                    if(temp2.find(*it)!=temp2.end()){
                        /*cout<<ct<<" ";*/ct--;
                        auto kt=temp2.find(*it);
                        temp2.erase(kt);
                    }
                }
            }
        }
        return ct;
    }
};
