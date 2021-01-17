class Solution {
public:
    int largestSubmatrix(vector<vector<int>>& matrix) {
        int i,j,k,n,m,ct=0,ans=0;
        n=matrix.size();m=matrix[0].size();
        int dp[n+5][m+5];
        for(j=0;j<m;j++){
            int flag=0,ct=0;
            for(i=n-1;i>=0;i--){
                if(matrix[i][j]==0) {
                    dp[i][j]=0;
                    ct=0;
                    flag=0;
                }
                else{
                    ct++;
                    dp[i][j]=ct;
                    flag=1;
                }
            }
        }
        for(i=0;i<n;i++){
            multiset<int> dict;
            for(j=0;j<m;j++) dict.insert(dp[i][j]);
            auto it=dict.end();
            it--;int flag=1;ct=0;int val=1e9;
            while(flag==1){
                ct++;
                val=*it;
                ans=max(ans,ct*val);
                if(it==dict.begin()) flag=0;
                else it--;
            }
        }
        return ans;
    }
};
