int dp[200][600][2];
class Solution {
public:
    int ways(vector<int> piles,int i,int flag,int m){
        if(i==piles.size()) return dp[i][m][flag]=0;
        else if(dp[i][m][flag]==-1){
            int sum=0;int ans=0;
            if(flag==0) ans=0;
            else ans = 1e9;
            int k=piles.size();
            for(int j=i;j<min(i+2*m,k);j++){
                sum+=piles[j];
                 if(flag==0) ans =max(ans,sum+ways(piles,j+1,1,min(k,max(m,j-i+1))));
                 else ans = min(ans,ways(piles,j+1,0,min(k,max(m,j-i+1))));
            }
            return dp[i][m][flag]=ans;
        }
        else return dp[i][m][flag];
    }
    int stoneGameII(vector<int>& piles) {
        int i,j,k,n,m,ct=0;
        memset(dp,-1,sizeof(dp));
       return ways(piles,0,0,1);
  
    }
};
