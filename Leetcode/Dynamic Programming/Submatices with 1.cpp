class Solution {
public:
    int numSubmat(vector<vector<int>>& mat) {
        int res = 0;
        int m = mat.size();
        int n = mat[0].size();
        vector<vector<int>> dp(m, vector<int>(n ,0));
        
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(mat[i][j]==0){
                    continue;
                }
                dp[i][j] = (j-1>=0)?dp[i][j-1]+1:1;
                int min_len = dp[i][j];
                res += min_len;
                for(int k=i-1;k>=0;k--){
                    min_len = min(min_len, dp[k][j]);
                    res += min_len;
                }
            }
        }
        
    
        
        return res;
    }
};
