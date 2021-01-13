class Solution {
public:
    int maximalRectangle(vector<vector<char>>& matrix) {
        int i,j,k,n,m,ct=0;
        n=matrix.size();
        if(n==0) return 0;
        m=matrix[0].size();
        int dp1[n][m];
        for(i=0;i<n;i++){
            for(j=0;j<m;j++){
                ct=0;
                if(matrix[i][j]=='0') dp1[i][j]=0;
                else{
                    k=j;
                    while(k<m && matrix[i][k]=='1'){
                        ct++;
                        k++;
                    }
                    dp1[i][j]=ct;
                }
            }
        }
       int ans=0;
       for(i=0;i<n;i++){
           for(j=0;j<m;j++){
               int min1=dp1[i][j];
               if(dp1[i][j]!=0){
                   k=i;ct=1;
                   while(k<n && dp1[k][j]>=1){
                       min1=min(min1,dp1[k][j]);
                       ans=max(ans,min1*ct);
                       k++;ct++;
                   }
               }
           }
       }
       return ans;
    }
};
