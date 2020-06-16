#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define fo(i,n) for(i=0;i<n;i++)
#define rep(i,k,n) for(i=k;i<=n;i++)
#define pa pair<ll,ll>
#define vec vector<ll>
#define pb push_back
#define in insert
#define mp make_pair
#define F first
#define S second
#define clr(x) memset(x, 0, sizeof(x))
#define init(x, a) memset(x, a, sizeof(x))
ll inf = (ll)1e18, kt = 0;
ll mod = 1e9 + 7;
ll max1 = (ll)1e9;
void dfs(vector<ll> adj[], ll i, ll vis[], ll parent) {
	vis[i] = 1;
	//cout << i << " ";
	kt++;
	for (ll x : adj[i]) {
		if (vis[x] == 0) dfs(adj, x, vis, i);
		else if (vis[x] == 1) continue;
	}
	return;
}
int main() {
#ifndef ONLINE_JUDGE
	freopen("C:/Users/Utkarsh Kumar Singh/Desktop/ALL CODE/input.txt", "r", stdin);
	freopen("C:/Users/Utkarsh Kumar Singh/Desktop/ALL CODE/output.txt", "w", stdout);
	freopen("C:/Users/Utkarsh Kumar Singh/Desktop/ALL CODE/err.txt", "w", stderr);
#endif
	ll i, j, k, n, m, ct = 0, t, ans = 0;
	cin >> n >> m;
	vector<ll> adj[n + 1];
	for (i = 1; i <= n - 1; i++) {
		cin >> j >> k >> t;
		if (t == 0) {
			adj[k].pb(j);
			adj[j].pb(k);
		}
	} ct = 0; ll ans2 = 0;
	ll vis[n + 1] = {0};
	for (i = 1; i <= n; i++) {
		if (vis[i] == 0) {
			kt = 0;
			dfs(adj, i, vis, -1);
			t = 1;
			for (j = 1; j <= m; j++) t = (t * kt) % mod;
			//cout << endl << kt << endl;
			ans2 = (ans2 + t) % mod;
			ans2 = ans2 % mod;
		}
	} ans = 1;
	//cout << ans2 % mod << endl;
	for (i = 1; i <= m; i++) ans = (ans * n) % mod;
	//cout << ans << endl;
	cout << (ans - ans2 + mod) % mod << endl;
	return 0;
}
