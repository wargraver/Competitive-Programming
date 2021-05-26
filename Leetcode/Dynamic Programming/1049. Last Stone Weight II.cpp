int dp[3005][3005];
class Solution {
public:
    int ways(int i,vector<int> stones,int sum1,int sum2){
        if(i==stones.size()) return abs(sum1-sum2);
        else if(dp[sum1][sum2]==-1){
     return dp[sum1][sum2]=min(ways(i+1,stones,sum1+stones[i],sum2),ways(i+1,stones,sum1,sum2+stones[i]));
        }
        return dp[sum1][sum2];
    }
    int lastStoneWeightII(vector<int>& stones) {
        int i,j,k,n,m,ct=0;
        n=stones.size();
        memset(dp,-1,sizeof(dp));
        return ways(0,stones,0,0);
    }
};
