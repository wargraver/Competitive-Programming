long long mod=1e9+7;
long long dp[100005][2][3];
long long ways(int i,int a,int l,int n){
    if(l==3) return 0;
    else if(a==2) return 0;
    else if(i==n) return 1;
    else if(dp[i][a][l]==-1){
        if(a==1 && l==2) return dp[i][a][l]=ways(i+1,a,0,n)%mod;
        else if(a==1 && l<2) return dp[i][a][l]=(ways(i+1,a,0,n)%mod+ways(i+1,a,l+1,n)%mod)%mod;
        else if(a==0 && l==2) return dp[i][a][l]=(ways(i+1,a,0,n)%mod+ways(i+1,a+1,0,n)%mod)%mod;
        else if(a==0 && l<2) return dp[i][a][l]=(ways(i+1,a,l+1,n)%mod+ways(i+1,a,0,n)%mod+ways(i+1,1,0,n)%mod);
        return 0;
    }
    else return dp[i][a][l]%mod;
}
class Solution {
public:
    long long checkRecord(int n) {
        int i,j,k,m,ct=0;
        for(i=0;i<=n+2;i++){
            for(j=0;j<=1;j++){
                for(k=0;k<=2;k++) dp[i][j][k]=-1;
            }
        }
        return ways(0,0,0,n)%mod;
        //return k;
    }
};
