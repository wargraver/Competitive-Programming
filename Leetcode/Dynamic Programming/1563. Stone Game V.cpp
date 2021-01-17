int dp[505][505],sum[505][505];
int ways(int st,int en,vector<int> a){
    if(st>en) return 0;
    else if(dp[st][en]==-1){
        int ans=0;
        for(int j=st;j<en;j++){
            int sum1=sum[st][j],sum2=sum[j+1][en];
            if(sum1<sum2) ans=max(ans,sum1+ways(st,j,a));
            else if(sum2<sum1) ans=max(ans,sum2+ways(j+1,en,a));
            else{
                ans=max(ans,max(sum1+ways(st,j,a),sum2+ways(j+1,en,a)));
            }
        }
        return dp[st][en]=ans;
    }
    else return dp[st][en];
}
class Solution {
public:
    int stoneGameV(vector<int>& a) {
        int i,j,k,n=a.size(),m,ct=0;
        for(i=0;i<=n+2;i++){
            for(j=0;j<=n+2;j++) {dp[i][j]=-1;sum[i][j]=0;}
        }
        for(i=0;i<n;i++){
            for(j=i;j<n;j++){
                 for(int st=i;st<=j;st++) sum[i][j]+=a[st];
            }
        }
        return ways(0,n-1,a);
    }
};
