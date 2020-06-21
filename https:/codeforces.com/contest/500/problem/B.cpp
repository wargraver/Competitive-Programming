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
#define clr(x) memset(x, 0, sizeof(x))
#define init(x, a) memset(x, a, sizeof(x))
ll inf = (ll)1e18;
ll mod = 1e9 + 7;
ll max1 = (ll)1e9;
vector<ll> vect, vect2;
map<ll, ll> dict2;
void dfs(vector<ll> adj[], ll vis[], ll i, map<ll, ll> dict, ll parent) {
	vis[i] = 1;
	vect.pb(i);
	vect2.pb(dict[i]);
	for (ll x : adj[i]) {
		if (vis[x] == 0) dfs(adj, vis, x, dict, i);
		else if (vis[x] == 1 && parent == x) continue;
	}
	return;
}
int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	freopen("err.txt", "w", stderr);
#endif
	ll i, j, k, n, m, ct = 0, t, ans = 0;
	cin >> n;
	vector<ll> adj[n + 1];
	ll a[n + 1] = {0};
	map<ll, ll> dict;
	ll vis[n + 1] = {0};
	for (i = 1; i <= n; i++) {
		cin >> a[i];
		dict.insert({a[i], i});
	}
	for (i = 1; i <= n; i++) {
		for (j = 1; j <= n; j++) {
			scanf("%1d", &k);
			if (k == 1) adj[a[i]].pb(a[j]);
			else continue;
		}
	}
	for (i = 1; i <= n; i++) {
		if (vis[i] == 0) {
			dfs(adj, vis, i, dict, -1);
			sort(vect2.begin(), vect2.end());
			sort(vect.begin(), vect.end());
			for (j = 0; j < vect.size(); j++) {
				dict2.insert({vect2[j], vect[j]});
			}
			vect.clear();
			vect2.clear();
		}
	}
	for (i = 1; i <= n; i++) cout << dict2[i] << " ";
	return 0;
}
