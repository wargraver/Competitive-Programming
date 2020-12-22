int dp[205][205];
int n,m,ans=1e9;
int dfs(int i,int j,vector<vector<int>> a){
    if(i==n-1 && j==m-1) return dp[i][j]=a[i][j];
    else if(dp[i][j]==-1){
        int ans=1e9;
        if(i!=n-1) ans=min(ans,a[i][j]+dfs(i+1,j,a));
        if(j!=m-1) ans=min(ans,a[i][j]+dfs(i,j+1,a));
        return dp[i][j]=ans;
    }
    else return dp[i][j];
}
class Solution {
public:
    int minPathSum(vector<vector<int>>& a) {
        ios_base::sync_with_stdio(false);
	cin.tie(NULL);
        int i,j,k,ct=0;
        ans=1e9;
        m=a[0].size();
        n=a.size();
        for(i=0;i<n+3;i++){
            for(j=0;j<m+3;j++) dp[i][j]=-1;
        }
        return dfs(0,0,a);
        
    }
};
