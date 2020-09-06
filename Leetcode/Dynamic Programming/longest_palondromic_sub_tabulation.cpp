#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define fo(i,n) for(i=0;i<n;i++)
#define Fo(i,k,n) for(i=k;i<=n;i++)
#define pa pair<ll,ll>
#define vec vector<ll>
#define pb push_back
#define in insert
#define mp make_pair
#define F first
#define S second
//memset(x, 0, sizeof(x))
ll inf = (ll)1e18;
ll mod = 1e9 + 7;
ll max1 = (ll)1e9; string str1, str2; ll dp[1005][1005];
//recursive approach
/*ll ways(ll i, ll j) {
	if (i > 0 || j < 0) return 0;
	if (dp[i][j] == -1) {
		if (str1[i] == str2[j]) return dp[i][j] = 1 + ways(i - 1, j - 1);
		else return dp[i][j] = max(ways(i - 1, j), ways(i, j - 1));
	}
	else return dp[i][j];
}*/
int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	freopen("err.txt", "w", stderr);
#endif
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	ll i, j, k, n, m, ct = 0, t, ans = 0;
	cin >> str2; n = str2.size();

	for (i = 0; i < str2.size(); i++) str1 += str2[i];
	reverse(str2.begin(), str2.end());
	memset(dp, 0, sizeof(dp));
	for (i = 1; i <= n; i++) {
		for (j = 1; j <= n; j++) {
			if (str1[i - 1] == str2[j - 1]) dp[i][j] = dp[i - 1][j - 1] + 1;
			else dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
		}
	}
	cout << dp[n][n];
	return 0;
}
