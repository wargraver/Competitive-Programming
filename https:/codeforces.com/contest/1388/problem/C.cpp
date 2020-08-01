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
#define clr(x) memset(x, 0, sizeof(x))
#define init(x, a) memset(x, a, sizeof(x))
ll inf = (ll)1e18;
ll mod = 1e9 + 7;
ll max1 = (ll)1e9; ll flag = 0;
ll c[200006] = {0}, d[200006] = {0}, e[200006] = {0};
void dfs(vector<ll> adj[], ll vis[], ll i, ll a[], ll b[], ll parent) {
	vis[i] = 1;
	for (ll x : adj[i]) {
		if (vis[x] == 0) {
			dfs(adj, vis, x, a, b, i);
		}
	}
	d[i] += a[i];
	d[parent] += d[i];
	ll happy = (d[i] + b[i]) / 2, bad = (d[i] - b[i]) / 2;
	//cout << i << " " << happy << " " << bad << " " << d[i] << endl;
	c[parent] += bad; e[parent] += happy;

	if ((d[i] + b[i]) % 2 != 0) flag = 1;
	if (happy > d[i] || happy < 0) flag = 1;
	if (happy < e[i]) flag = 1;
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
	cin >> t;
	while (t--) {
		cin >> n >> m; flag = 0;
		ll a[n + 1], b[n + 1], vis[n + 1] = {0};
		vector<ll> adj[n + 1];
		for (i = 1; i <= n; i++) cin >> a[i];
		for (i = 1; i <= n; i++) cin >> b[i];
		for (i = 1; i <= n - 1; i++) {
			cin >> j >> k;
			adj[j].pb(k);
			adj[k].pb(j);
		}
		dfs(adj, vis, 1, a, b, 0);
		if (d[1] != m) flag = 1;
		if (flag == 1) cout << "NO\n";
		else cout << "YES\n";
		for (i = 0; i <= n; i++) {
			c[i] = 0; d[i] = 0; e[i] = 0;
		}
	}
	return 0;
}
