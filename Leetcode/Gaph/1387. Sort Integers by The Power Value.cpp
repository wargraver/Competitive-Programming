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
ll max1 = (ll)1e9;
ll vis[50005] = {0}; ll ans[50005] = {0};
ll ways(ll i) {
	if (i <= 50000 && ans[i] != 0) return ans[i];
	else {
		//cout << i << endl;
		if (i % 2 == 0) {return 1 + ways(i / 2);}
		else {1 + ways((3 * i + 1));}
	}
}
void dfs(ll i, vector<ll> adj[], ll parent) {
	vis[i] = 1;
	ans[i] = 1 + ans[parent];
	for (auto x : adj[i]) {
		if (vis[x] == 0) dfs(x, adj, i);
	}
}
int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	freopen("err.txt", "w", stderr);
#endif
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	ll i, j, k, n, m, ct = 0, t;
	cin >> n >> m >> k;
	vector<ll> adj[50000];
	for (i = 1; i <= 10000; i++) {
		adj[i].pb(2 * i);
		if (i % 2 == 0) {
			if ((i - 1) % 3 == 0 && i - 1 > 4) {
				adj[i].pb((i - 1) / 3);
			}
		}
	}
	dfs(1, adj, 0);
	for (i = 2; i <= 1001; i++) {
		ans[i] = ways(i);
	}
	//for (i = 0; i <= 1000; i++) cout << i << " " << ans[i] - 1 << endl;
	set<pair<ll, ll>> dict;
	for (i = n; i <= m; i++) dict.in({ans[i] - 1, i});
	j = 0;
	for (auto it = dict.begin(); it != dict.end(); it++) {
		j++;
		cout << it->F << " " << it->S << endl;
		if (j == k) cout << it->S;
	}
	return 0;
}
