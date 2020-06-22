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
vector<ll> nodes;
ll mod = 1e9 + 7;
void dfs(vector<ll> adj[], ll vis[], ll i, ll parent, ll a[], ll b[], double ratio) {
	vis[i] = 1;
	nodes.pb(i);
	for (ll x : adj[i]) {
		double ratio2 = (double)a[x] / b[x];
		if (vis[x] == 0 && ratio2 == ratio) {
			dfs(adj, vis, x, i, a, b, ratio);
		}
	}
	return;
}
int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	freopen("err.txt", "w", stderr);
#endif
	std::ios::sync_with_stdio(false);
	ll i, j, k, n, m, ct = 0, t, ans = 0;
	cin >> t;

	while (t--) {
		cin >> n >> m;
		double max1 = 0.00;
		vector<ll> adj[n + 1];
		vector<ll> vect3;
		ll vis[n + 1] = {0};
		ll a[n + 1], b[n + 1];
		for (i = 1; i <= n; i++) cin >> a[i];
		for (j = 1; j <= n; j++) cin >> b[j];
		double ratio = 0;
		for (i = 1; i <= n; i++) {
			double y = (double)a[i] / b[i];
			ratio = max(y, ratio);
		}
		for (i = 0; i < m; i++) {
			cin >> j >> k;
			adj[j].pb(k);
			adj[k].pb(j);
		}
		for (i = 1; i <= n; i++) {
			double ratio2 = (double)a[i] / b[i];
			if (vis[i] == 0 && ratio == ratio2) {
				dfs(adj, vis, i, -1, a, b, ratio);
				if (nodes.size() > vect3.size()) {
					vect3.clear();
					for (i = 0; i < nodes.size(); i++) {
						vect3.pb(nodes[i]);
					}
				}
				nodes.clear();
			}
		}
		cout << vect3.size() << "\n";
		for (i = 0; i < vect3.size(); i++) cout << vect3[i] << " ";
		cout << "\n";
	}
	return 0;
}
