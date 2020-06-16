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
ll max1 = (ll)1e9;
bool edge_exist(ll x, ll y, vector<ll> adj[]) {
	for (ll i = 0; i < adj[x].size(); i++) {
		if (adj[x][i] == y) return true;
	}
	return false;
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
	for (i = 1; i <= m; i++) {
		cin >> j >> k;
		adj[j].pb(k);
		adj[k].pb(j);
	} ct = inf;
	for (i = 1; i <= n; i++) {
		for (j = 0; j < adj[i].size(); j++) {
			for (k = j + 1; k < adj[i].size(); k++) {
				t = adj[i][j]; m = adj[i][k];
				if (edge_exist(adj[i][j], adj[i][k], adj)) {
					ll l = adj[i].size() + adj[t].size() + adj[m].size();
					ct = min(ct, l);
				}
			}
		}
	}
	if (ct == inf) cout << "-1";
	else cout << ct - 6;
	return 0;

}
