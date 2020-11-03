int dp[4002][4002];
vector<int> a;
int ways(int i,int last){
    if(i==a.size()) return 0;
    else if(dp[i][last]==-1){
       if(last==4000) return dp[i][last]=max(ways(i+1,last),ways(i+1,i)+1);
       else{
          int val1=0,val2;
           if(a[last]<a[i]) val1=ways(i+1,i)+1;
           val2=ways(i+1,last);
           return dp[i][last]=max(val1,val2);
    }
    }
    else return dp[i][last];
}
class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        ios_base::sync_with_stdio(false);
	    cin.tie(NULL);a.clear();
        for(int i=0;i<nums.size();i++) a.push_back(nums[i]);
        memset(dp,-1,sizeof(dp));
        return ways(0,4000);
    }
};
