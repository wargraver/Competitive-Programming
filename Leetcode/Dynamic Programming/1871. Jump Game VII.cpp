class Solution {
public:
   bool canReach(string s, int minJ, int maxJ) {
        int n = s.size(), pre = 0;
        vector<bool> dp(n, false);
        dp[0] = true;
        for (int i = 1; i < n; ++i) {
            if (i >= minJ)
                pre += dp[i - minJ];
            if (i > maxJ)
                pre -= dp[i - maxJ - 1];
            dp[i] = pre > 0 && s[i] == '0';
        }
        return dp[n - 1];
    }
};
