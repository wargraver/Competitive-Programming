class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
        int i,j,n=cardPoints.size(),m,ct=0;
        int st_sum[n+1],en_sum[n+1];
        memset(st_sum,0,sizeof(st_sum));
        memset(en_sum,0,sizeof(en_sum));
        for(i=0;i<n;i++) st_sum[i+1]+=(st_sum[i]+cardPoints[i]);
        for(i=n-1;i>=0;i--) en_sum[n-i]+=en_sum[n-i-1]+cardPoints[i];
        int ans=0;
        for(i=0;i<=k;i++){
            ans = max(ans,st_sum[i]+en_sum[k-i]);
        }
        return ans;
    }
};
