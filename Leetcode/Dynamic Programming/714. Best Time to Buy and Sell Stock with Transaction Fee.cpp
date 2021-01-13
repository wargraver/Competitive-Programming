int n;
int dp[50005][2];
class Solution {
public:
    int maxProfit(vector<int>& prices, int fee) {
        int i,j,k,m,ct=0;
        n=prices.size();
     dp[n][0]=0;
     dp[n][1]=-1e9;
     for(i=n-1;i>=0;i--){
        for(j=0;j<=1;j++){
            if(j==0){
                dp[i][0]=max(dp[i+1][0],dp[i+1][1]-prices[i]);
            }
            else{
                dp[i][1]=max(dp[i+1][1],dp[i+1][0]+prices[i]-fee);
            }
        }
    }
    return dp[0][0];
    }
};
