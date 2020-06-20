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
ll max1 = (ll)1e9, ct = 0; ll kt = 0;
ll nodes[200005] = {0}, height[200005] = {0};
vector<ll> vect, vect2, vect3;
void dfs(vector<ll> adj[], ll vis[], ll i) {
	vis[i] = 1;
	ct++;
	height[i] = ct - 1;
	for (ll x : adj[i]) {
		if (vis[x] == 0) {
			dfs(adj, vis, x);
			if (adj[x].size() == 1) nodes[x] = 0;
			nodes[i] += (nodes[x] + 1);
		}
	}
	vect.pb(nodes[i] - height[i]);
	ct--;
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
		cin >> j >> k;
		adj[j].pb(k);
		adj[k].pb(j);
	}
	ll vis[n + 1] = {0};
	dfs(adj, vis, 1);
	/*cout << endl;
	for (i = 1; i <= n; i++) cout << nodes[i] << " ";
	cout << endl;
	for (i = 1; i <= n; i++) cout << height[i] << " ";*/
	sort(vect.begin(), vect.end());
	reverse(vect.begin(), vect.end());
	for (i = 0; i < n - m; i++) ans += vect[i];
	cout << ans << endl;
	return 0;
}
