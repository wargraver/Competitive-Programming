int max1=20000000;
int dp[50005];
int ways(vector<int> a,int i){
  if(i>=a.size()) return 0;
    else if(dp[i]==-1e9){
        dp[i]=a[i]-ways(a,i+1);
        if(i+1<=a.size()-1) dp[i]=max(dp[i],a[i]+a[i+1]-ways(a,i+2));
        if(i+2<=a.size()-1) dp[i]=max(dp[i],a[i]+a[i+1]+a[i+2]-ways(a,i+3));
        return dp[i];
    }
    else return dp[i];
}
class Solution {
public:
    string stoneGameIII(vector<int>& a) {
      int i,j,k,n=a.size();
      for(i=0;i<=a.size()+4;i++) dp[i]=0;
      i=n-1;
      while(i>=0){
      if(i>=a.size()) dp[i]=0;
      else{  
        dp[i]=a[i]-dp[i+1];
        if(i+1<=a.size()-1) dp[i]=max(dp[i],a[i]+a[i+1]-dp[i+2]);
        if(i+2<=a.size()-1) dp[i]=max(dp[i],a[i]+a[i+1]+a[i+2]-dp[i+3]);
          }
        i--;
        }
        int val=dp[0];
        if(val==0) return "Tie";
        else if(val>0) return "Alice";
        else return "Bob";
    }
};
