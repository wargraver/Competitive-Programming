#include<bits/stdc++.h>
using namespace std;
typedef int ll;
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
ll max1 = (ll)1e9; ll n;
vector<ll> vect[205]; ll x = inf;
ll dp[201][201][512];
ll min_val(ll j, ll ans, ll ct) {
	if (ct == n) return dp[j][ct][ans] = ans;
	if (j == 0) return inf;
	if (dp[j][ct][ans] == -1) {
		ll val = inf;
		for (ll i = 0; i < vect[j - 1].size(); i++) {
			val = min(min_val(j - 1, ans | vect[j - 1][i], ct + 1), val);
		}
		return dp[j][ct][ans] = val;
	}
	else return dp[j][ct][ans];
}
int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	freopen("err.txt", "w", stderr);
#endif
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	ll i, j, k, m, ct = 0, t, ans = 0;
	cin >> n >> m;
	ll a[n], b[m];
	for (i = 0; i < n; i++) cin >> a[i];
	for (j = 0; j < m; j++) cin >> b[j];
	for (i = 0; i < n; i++) {
		for (j = 0; j < m; j++) {
			k = a[i] & b[j];
			vect[i].pb(k);
		}
	}
	memset(dp, -1, sizeof(dp));
	//dp[0][0] = 0;
	for (i = 0; i < 200; i++) dp[0][i][ans] = inf;
	cout << min_val(n, ans, 0);
	return 0;
}
