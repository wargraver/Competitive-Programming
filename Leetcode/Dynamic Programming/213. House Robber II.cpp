int dp[105][105][2];
int ways(vector<int> a,int i,int last,int n,int flag){
    if(i>=n) return 0;
    else if(dp[i][last][flag]==-1){
        int k=last;
        if(last==104){
            int j;j=flag;
            if(i==0) j=0;
            return dp[i][last][flag]=max(ways(a,i+1,last,n,flag),ways(a,i+2,i,n,j)+a[i]);}
        else{
            if(i-1==last || (flag==0 && i==n-1)) return dp[i][last][flag]=ways(a,i+1,last,n,flag);
            else return dp[i][last][flag]=max(ways(a,i+1,last,n,flag),ways(a,i+1,i,n,flag)+a[i]);
        } 
    }
    else return dp[i][last][flag];
}
class Solution {
public:
    int rob(vector<int>& nums) {
        int n=nums.size();
        
        memset(dp,-1,sizeof(dp));
        return ways(nums,0,104,n,1);
    }
};
