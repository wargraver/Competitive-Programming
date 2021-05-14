class Solution {
public:
    int maxSumDivThree(vector<int>& nums) {
        int i,j,k,n,m;
        n = nums.size();
        int dp[n+1][3];
        memset(dp,0,sizeof(dp));
       dp[n-1][nums[n-1]%3] = nums[n-1];
        //cout<<dp[n-1][nums[n-1]%3]<<endl;
        for(i=n-2;i>=0;i--){
           dp[i][0] = dp[i+1][0];
           dp[i][1] = dp[i+1][1];
           dp[i][2] = dp[i+1][2];
           for(j=0;j<3;j++){
               int res = (dp[i+1][j]+nums[i])%3;
               dp[i][res] = max(dp[i+1][j]+nums[i],dp[i][res]);
           }
        }
        return dp[0][0];
    }
};
