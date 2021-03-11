int dp1[205][205],n,m;
int ways(int i,int j,vector<vector<int>> dp){
        int temp_ans=0;
    if(dp1[i][j]==-1){
        if(i+1!=n && dp[i+1][j]>dp[i][j]) temp_ans=max(temp_ans,1+ways(i+1,j,dp));
         if(j+1!=m && dp[i][j+1]>dp[i][j]) temp_ans=max(temp_ans,1+ways(i,j+1,dp));
        if(j!=0 && dp[i][j-1]>dp[i][j]) temp_ans=max(temp_ans,1+ways(i,j-1,dp));
         if(i!=0 && dp[i-1][j]>dp[i][j]) temp_ans=max(temp_ans,1+ways(i-1,j,dp));
        return dp1[i][j]=temp_ans;
    }
        else return dp1[i][j];
}
   
class Solution {
public:
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        int i,j,k,ans=0;
        n=matrix.size();m=matrix[0].size();
        for(i=0;i<n+5;i++){
            for(j=0;j<m+5;j++){
                dp1[i][j]=-1;
            }
        }
        for(i=0;i<n;i++){
            for(j=0;j<m;j++){
                if(dp1[i][j]==-1) dp1[i][j]=ways(i,j,matrix);
                ans=max(dp1[i][j],ans);
            }
        }
        return ans+1;
    }
};
