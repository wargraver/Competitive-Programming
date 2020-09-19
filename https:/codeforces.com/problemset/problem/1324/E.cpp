//https://codeforces.com/problemset/problem/1324/E
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
ll max1 = (ll)1e9, a[2005], dp[2005][2005], l, r, h, ct = 0;
ll ways(ll i, ll n, ll st) {
	if (i == n) return dp[i][st] = 0;
	else if (dp[i][st] == -1) {
		ll st1 = (st + a[i]) % h, st2 = (st + a[i] - 1) % h;
		//if (st1 == 0) st1 = h;
		//	if (st2 == 0) st2 = h;
		if (l <= st1 && r >= st1 && l <= st2 && r >= st2) return dp[i][st] = 1 + max(ways(i + 1, n, st1), ways(i + 1, n, st2));
		else if (l <= st1 && r >= st1) return dp[i][st] = max(1 + ways(i + 1, n, st1), ways(i + 1, n, st2));
		else if (l <= st2 && r >= st2) return dp[i][st] = max(ways(i + 1, n, st1), 1 + ways(i + 1, n, st2));
		else return dp[i][st] = max(ways(i + 1, n, st1), ways(i + 1, n, st2));
	}
	else return dp[i][st];
}
int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	freopen("err.txt", "w", stderr);
#endif
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	ll i, j, k, n, m, ct = 0, t, ans = 0;
	cin >> n >> h >> l >> r;
	for (i = 0; i < n; i++) cin >> a[i];
	memset(dp, -1, sizeof(dp));
	cout << ways(0, n, 0) << endl;
	return 0;
}
