class Solution {
public:
    int maxResult(vector<int>& a, int k) {
        int i,j,n=a.size(),m,ct=0;
      //  int ans=-1e9;
        multiset<int> dict;
        dict.insert(a[n-1]);
        int dp[100005]={0};
        dp[n-1]=a[n-1];
        for(i=n-2;i>=0;i--){
            if(dict.size()<=k){
                auto it=dict.end();
                it--;
                int sum=*it;
                dp[i]=a[i]+sum;
                dict.insert(dp[i]);
             }
            else{
                dict.erase(dp[i+k+1]);
                auto it=dict.end();
                it--;
                int sum=*it;
                dp[i]=a[i]+sum;
                dict.insert(dp[i]);
            }
        }
        return dp[0];
    }
};
