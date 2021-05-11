int dp[505][505];
class Solution {
public:
    int lcs(string s,string r,int i1,int i2){
        for(int i1=s.size()-1;i1>=0;i1--){
            for(int i2=r.size()-1;i2>=0;i2--){
                if(s[i1]==r[i2]) dp[i1][i2]=dp[i1+1][i2+1]+1;
                else dp[i1][i2]  = max(dp[i1+1][i2],dp[i1][i2+1]);
            }
        }
        return dp[0][0];
    }
    int minInsertions(string s) {
        int i,j,k,n,m,ct=0,ans;
        n=s.size();ans=n;
        string r = s;
        memset(dp,0,sizeof(dp));
        reverse(r.begin(),r.end());
        m = lcs(s,r,0,0);
        return n-m;
    }
};
