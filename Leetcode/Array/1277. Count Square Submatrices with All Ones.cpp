class Solution {
public:
    int countSquares(vector<vector<int>>& a) {
        int i,j,k,n,m,ct=0;
        n = a.size();
        m = a[0].size();
        int dp1[n][m],dp2[n][m];
        memset(dp1,0,sizeof(dp1));
        memset(dp2,0,sizeof(dp2));
        for(i=0;i<n;i++){
            if(a[i][0]==1) dp1[i][0]=1;
            else dp1[i][0]=0;
        }
        for(j=0;j<m;j++){
            if(a[0][j]==1) dp2[0][j]=1;
            else dp2[0][j]=0;
        }
        for(i=1;i<n;i++){
            for(j=1;j<m;j++){
                if(a[i][j]==1){
                    dp1[i][j]=dp1[i][j-1]+1;
                }
                else dp1[i][j]=0;
                 if(a[i][j]==1){
                    dp2[i][j] = dp2[i-1][j]+1;
                }
                else dp2[i][j] = 0;
            }
           
        }
        int ans=0,flag=0;
        for(i=0;i<n;i++){
            for(j=0;j<m;j++){
                if(a[i][j]==1){
                    ans+=1;
                    for(k=1;k<min(n,m);k++){
                        if(i+k<n && j+k<m){
                            int n1 = dp1[i+k][j+k],n2 = dp2[i+k][j+k];
                            if(min(n1,n2)>=k+1) ans+=1;
                            else break;
                        }
                        else break;
                    }
                }
            }
        }
        return ans;
    }
};
