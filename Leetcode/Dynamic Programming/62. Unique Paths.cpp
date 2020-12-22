int dp[105][105];
int ways(int i,int j,int n,int m){
    if(i==n-1 && j==m-1) return 1;
    else if(dp[i][j]==-1){
        int ans=0;
        if(i!=n-1) ans+=ways(i+1,j,n,m);
        if(j!=m-1) ans+=ways(i,j+1,n,m);
        return dp[i][j]=ans;
    }
    else return dp[i][j];
}
class Solution {
public:
    int uniquePaths(int m, int n) {
        int i,j,k;
        for(i=0;i<=n+3;i++){
            for(j=0;j<=m+3;j++) dp[i][j]=-1;
        }
        return ways(0,0,n,m);
    }
};
