int dp[105][2];
int ways(vector<int> nums,int i,int flag){
    if(i==nums.size()) return 0;
    else if(dp[i][flag]==-1){
        if(flag==1) return dp[i][flag]=ways(nums,i+1,0);
        else return dp[i][flag]=max(nums[i]+ways(nums,i+1,1),ways(nums,i+1,0));
    }
    else return dp[i][flag];
}
class Solution {
public:
    int rob(vector<int>& nums) {
        int i,j,k,n,m,ct=0;
        memset(dp,-1,sizeof(dp));
        return ways(nums,0,0);
    }
};
