typedef int ll;
ll max1 = (ll)1e9, n, dp[505][505], a[505];
ll ways(ll st, ll en) {
	if (st > en) return 0;
	else if (dp[st][en] == -1) {
		ll max2 = 0;
		//cout << max2 << endl;
		for (ll j = st; j <= en; j++) {
			ll ans;
            int k=a[j]*a[st-1];
			ans = ways(st, j - 1) + ways(j + 1, en) + k*a[en + 1];
			max2 = max(max2, ans);
		}
		return dp[st][en] = max2;
	}
	else return dp[st][en];
}
class Solution {
public:
    int maxCoins(vector<int>& nums) {
         memset(dp, -1, sizeof(dp));a[0]=1;
         for(int i=0;i<nums.size();i++) a[i+1]=nums[i];
        // for(int i=0;i<=nums.size();i++) cout<<a[i]<<" ";
          int n=nums.size();a[n+1]=1;
          return ways(1,n);
    }
};
