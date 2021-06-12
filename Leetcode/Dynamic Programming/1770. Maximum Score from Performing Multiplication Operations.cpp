int dp[1005][1005];
class Solution {
public:
    int ways(vector<int> nums,vector<int> m,int st,int en){
        if(st+en>=m.size()) return 0;
        else if(dp[st][en]==-1){
            int i1 = st+en;
            int t = nums.size()-1;
            return dp[st][en]= max(m[i1]*nums[st] + ways(nums,m,st+1,en),m[i1]*nums[t-en]+ways(nums,m,st,en+1));
        }
        else return dp[st][en];
    }
    int maximumScore(vector<int>& nums, vector<int>& multipliers) {
        int i,j,k,n=nums.size(),m=multipliers.size(),ct=0;
        for(i=0;i<=m+3;i++){
            for(j=0;j<=m+3;j++) dp[i][j]=-1;
        }
        return ways(nums,multipliers,0,0);
    }
};
