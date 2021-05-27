class Solution {
public:
    int shortestPathLength(vector<vector<int>>& graph) {
        int i,j,n,m,ct=0;
        n=graph.size()-1;
        int k = pow(2,n+1)-1;
        int ans=1e9;
        for(i=0;i<=n;i++){
            int t = k;
            queue<tuple<int,int,int>> q;
            t = k xor 1<<i;
            q.push({i,0,t});
            bool vis[n+1][t+1];
            memset(vis,false,sizeof(vis));
            while(q.empty()==false){
                auto [j,level,val] = q.front();
                q.pop();
                if(val==0) {
                    ans=min(ans,level);
                    break;
                   }
                if(vis[j][val]==true) continue;
                vis[j][val] = true;
                for(auto x:graph[j]){
                   if((val & (1<<x))==pow(2,x)){
                      int new_val = (val xor 1<<x);
                      q.push({x,level+1,new_val});
                     }
                    else q.push({x,level+1,val});
                }
            }
        }
        return ans;
    }
};
