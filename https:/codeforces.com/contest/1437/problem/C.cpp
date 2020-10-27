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
ll max1 = (ll)1e9, n, dp[500][205];
ll ways(ll idx, ll val, ll a[]) {
	if (val > n) return 0;
	else if (idx > 400) return inf;
	else if (dp[idx][val] == -1) {
		return dp[idx][val] = min((abs(idx - a[val]) + ways(idx + 1, val + 1, a)), ways(idx + 1, val, a));
	}
	else return dp[idx][val];
}
int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	freopen("err.txt", "w", stderr);
#endif
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	ll i, j, k , m, ct = 0, t, ans = 0;
	cin >> t;
	while (t--) {
		cin >> n;
		ll a[n + 1];
		for (i = 1; i <= n; i++) cin >> a[i];
		memset(dp, -1, sizeof(dp));
		ans = inf;
		sort(a + 1, a + n + 1);
		for (i = 1; i <= n; i++) {
			ans = min(ans, ways(i, 1, a));
		}
		cout << ans << endl;
	}
	return 0;
}
