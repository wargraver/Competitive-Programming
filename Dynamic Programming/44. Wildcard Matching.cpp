class Solution {
public:
    bool isMatch(string s, string p) {
        int i,j,k,n,m,ct=0;
        n=s.size(),m=p.size();
        int dp[m+5][n+5];
        dp[0][0]=1;
        for(i=1;i<=n;i++) dp[0][i]=0;
        for(i=1;i<=m;i++){
            if(p[i-1]=='*') dp[i][0]=dp[i-1][0];
            else dp[i][0]=0;
        }
        for(i=1;i<=m;i++){
            for(j=1;j<=n;j++){
                if(p[i-1]==s[j-1]) {dp[i][j]=dp[i-1][j-1];}
                else if(p[i-1]=='*'){
                    if(p[0]=='*' && i-1==0) {for(k=1;k<=n;k++) dp[i][k]=1;break;}
                    else{
                       if(dp[i-1][j]==1){
                        for(k=j;k<=n;k++) dp[i][k]=dp[i-1][j];
                        break;
                       }
                        else dp[i][j]=dp[i-1][j];
                    }
                }
                else if(p[i-1]=='?'){
                    dp[i][j]=dp[i-1][j-1];
                }
               else if(p[i-1]!=s[j-1]) dp[i][j]=0;
            }
        }
       /*for(i=0;i<=m;i++){
            for(j=0;j<=n;j++) cout<<dp[i][j]<<" ";
            cout<<endl;
        }*/
        if(dp[m][n]==1) return true;
        else return false;
    }
};
