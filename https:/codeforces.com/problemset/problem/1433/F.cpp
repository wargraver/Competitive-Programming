/*


 मंजिल मिल ही जायेगी एक दिन, भटकते-भटकते ही सही । गुमराह तो वो है, जो घर से निकले ही नहीं


 */
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
ll max1 = (ll)1e9, a[75][75], n, m, k, dp[75][75][75][75];
ll ways(ll x, ll y, ll ct, ll rem) {
	if (x >= n && rem != 0) return -inf;
	else if (x >= n && rem == 0) return 0;
	//else if (y >= m && ct < m / 2 && ct != 0) return -inf;
	//else if (y >= m && ct == 0 && dp[x][y][ct][rem] == -1) return dp[x][y][ct][rem] = ways(x + 1, 0, 0, rem);
	//else if (y >= m && ct == 0) return dp[x][y][ct][rem];
	else if (ct >= m / 2 && dp[x][y][ct][rem] == -1) return dp[x][y][ct][rem] = ways(x + 1, 0, 0, rem);
	else if (ct >= m / 2) return dp[x][y][ct][rem];
	else if (y >= m &&  dp[x][y][ct][rem] == -1) return dp[x][y][ct][rem] = ways(x + 1, 0, 0, rem);
	else if (y >= m) return dp[x][y][ct][rem];
	else if (dp[x][y][ct][rem] == -1) {
		return dp[x][y][ct][rem] = max(ways(x, y + 1, ct, rem), ways(x, y + 1, ct + 1, (rem + a[x][y]) % k) + a[x][y]);
	}
	else return dp[x][y][ct][rem];
}
int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	freopen("err.txt", "w", stderr);
#endif
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	ll i, j, ct = 0, t, ans = 0;
	cin >> n >> m >> k;
	for (i = 0; i < n; i++) {
		for (j = 0; j < m; j++) cin >> a[i][j];
	}
	memset(dp, -1, sizeof(dp));
	k = ways(0, 0, 0, 0);
	cout << k << endl;

	return 0;
}
