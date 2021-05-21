class Solution {
public:
    int shortestPath(vector<vector<int>>& grid, int k) {
        int i,j,n,m,ct=0,ans=INT_MAX;
        n=grid.size();
        m=grid[0].size();
        vector<vector<pair<int,int>>> dp(n,vector<pair<int,int>> (m,{INT_MAX,0}));
        // x, y, cost, kRem
        using QEntry = tuple<int,int,int,int>;
        queue<QEntry> q;
        if(grid[0][0]==1) q.push({0,0,1,k-1});
        else q.push({0,0,1,k});
       while(q.empty()==false){
            auto [x,y,res,rem]=q.front();
            q.pop();
            if(x==n-1 && y==m-1){
                ans = min(ans,res);
                continue;
            }
            if(dp[x][y].first<=res && dp[x][y].second>=rem) continue;
            dp[x][y].first = res;
            dp[x][y].second = rem;
            if(x-1>=0 && rem-grid[x-1][y]>=0) q.push({x-1,y,res+1,rem-grid[x-1][y]});
            if(y-1>=0 && rem-grid[x][y-1]>=0) q.push({x,y-1,res+1,rem-grid[x][y-1]});
            if(x+1<=n-1 && rem-grid[x+1][y]>=0) q.push({x+1,y,res+1,rem-grid[x+1][y]});
            if(y+1<=m-1 && rem-grid[x][y+1]>=0) q.push({x,y+1,res+1,rem-grid[x][y+1]});
        }
        return ans==INT_MAX ? -1:ans-1;
    }
};
