//https://leetcode.com/problems/best-time-to-buy-and-sell-stock-iii/submissions/
int dp[100005][3][3],n;
vector<int> a;
int ways(int i,int brought,int ct){
    if(ct>=2 && brought==0) return 0;
    else if(ct>=2 && brought==1) return -2e9;
    else if(i==n && brought==0) return 0;
    else if(i==n && brought==1) return -2e9;
    else if(dp[i][brought][ct]==-1){
        if(brought==1){
             return dp[i][brought][ct]=max(ways(i+1,0,ct+1)+a[i],ways(i+1,1,ct));
        }
        else{
            return dp[i][brought][ct]=max(ways(i+1,1,ct)-a[i],ways(i+1,0,ct));
        }
    }
    else return dp[i][brought][ct];
}
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        n=prices.size();
        a.clear();
        memset(dp,-1,sizeof(dp));
        for(int i=0;i<prices.size();i++) a.push_back(prices[i]);
        return ways(0,0,0);
    }
};
