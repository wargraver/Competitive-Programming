int vis[16]={0};
vector<unordered_set<int>> dict;
unordered_set<int> temp;
void dfs(vector<int> adj[],int i,int n){
   // vis[i]=1;
    temp.insert(i);
    for(auto x:adj[i]){
        if(vis[x]==0){
            if(x==n){
                temp.insert(n);
                
                dict.push_back(temp);
     for(auto it=temp.begin();it!=temp.end();it++) cout<<*it<<" ";
    cout<<endl;
    temp.erase(n);
            }
            if(x!=n) dfs(adj,x,n);
        }
    }
    temp.erase(i);
}
void find(vector<int> adj[],int i,int n){
          dfs(adj,i,n);
}

class Solution {
public:
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        vector<int> adj[16];
        dict.clear();temp.clear();
        for(int i=0;i<graph.size();i++){
            for(int j=0;j<graph[i].size();j++){
                adj[i].push_back(graph[i][j]);
            }
        }
        find(adj,0,graph.size()-1);
        vector<vector<int>> dict2;
        for(int i=0;i<dict.size();i++){
            vector<int> temp2;
     for(auto it=dict[i].begin();it!=dict[i].end();it++) temp2.push_back(*it);
        reverse(temp2.begin(),temp2.end());
        dict2.push_back(temp2);
        }
        return dict2;
    }
};
