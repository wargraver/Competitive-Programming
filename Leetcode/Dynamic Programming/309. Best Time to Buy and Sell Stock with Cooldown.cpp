int dp[100007][2];
int ways(vector<int> a,int i,int flag){
    if(i>=a.size()) return 0;
    else if(dp[i][flag]==-1){
    if(flag==0){
        return dp[i][flag]=max(ways(a,i+1,1)-a[i],ways(a,i+1,0));
    }
    else if(flag==1){
         return dp[i][flag]=max(ways(a,i+2,0)+a[i],ways(a,i+1,1));
    }
   }
   else return dp[i][flag];
    return 0;
}
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        memset(dp,-1,sizeof(dp));
        return ways(prices,0,0);
    }
};
