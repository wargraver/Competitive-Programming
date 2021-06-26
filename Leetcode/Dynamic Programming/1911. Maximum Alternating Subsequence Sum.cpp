
class Solution {
public:
  /*  int ways(vector<int> nums,int i,int flag){
        if(i>=nums.size()) return 0;
        if(dp[i][flag]==-1){
        if(flag==0){
             return dp[i][flag]=max(ways(nums,i+1,flag),nums[i]+ways(nums,i+1,1));
        }
        else{
            return dp[i][flag]=max(ways(nums,i+1,flag),ways(nums,i+1,0)-nums[i]);
        }
        }
        else return dp[i][flag];
    }
    */
    long long maxAlternatingSum(vector<int>& nums) {
       long long i,j,k,n,m,ct=0;
        n=nums.size();
        long long dp[n+5][2];
        memset(dp,0,sizeof(dp));
        dp[n-1][0] = nums[n-1];
        dp[n-1][1] = 0;
        for(i=n-2;i>=0;i--){
            for(j=0;j<2;j++){
                if(j==0){
                    dp[i][j] = max(dp[i+1][j],nums[i]+dp[i+1][1]);
                }
                else{
                    dp[i][j] = max(dp[i+1][j],dp[i+1][0]-nums[i]);
                }
            }
        }
        return dp[0][0];
    }
};
