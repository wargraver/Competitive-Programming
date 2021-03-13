class Solution {
public:
    bool isMatch(string s, string p) {
        int i,j,k,n,m;
        n=s.size();m=p.size();
        int dp[m+1][n+1];
        for(i=0;i<=m;i++){
            for(j=0;j<=n;j++) dp[i][j]=0;
        }
        dp[0][0]=1;
        for(i=1;i<=n;i++) dp[0][i]=0;
        for(i=1;i<=m;i++){
            if(p[i-1]=='*') dp[i][0]=dp[i-2][0];
            else dp[i][0]=0;
        }
        for(i=1;i<=m;i++){
            for(j=1;j<=n;j++){
                if(p[i-1]==s[j-1]) dp[i][j]=dp[i-1][j-1];
                else if(p[i-1]=='*'){
                     if(p[i-2]==s[j-1]|| p[i-2]=='.'){
                         dp[i][j]=dp[i-1][j] || dp[i][j-1];
                     }
                    dp[i][j]=dp[i][j] || dp[i-2][j];
                }
                else if(p[i-1]=='.') dp[i][j]=dp[i-1][j-1];
                else dp[i][j]=0;
            }
        }
     
        if(dp[m][n]==0) return false;
        else return true;
    }
};
