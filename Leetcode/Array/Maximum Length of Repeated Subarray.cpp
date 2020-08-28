int n1,n2,dp[1005][1005];

class Solution {
public:
    int findLength(vector<int>& A, vector<int>& B) {
        n1=(int)A.size(),n2=(int)B.size();int ans=0;
        for(int i=0;i<=n1;i++){
            for(int j=0;j<=n2;j++) dp[i][j]=0;
        }
        for(int i=n1-1;i>=0;i--){
            for(int j=n2-1;j>=0;j--){
                if(A[i]==B[j]){
                    dp[i][j]=dp[i+1][j+1]+1;
                    if(ans<dp[i][j]) ans=dp[i][j];
                }
            }
        }
      return ans;
   }
};
