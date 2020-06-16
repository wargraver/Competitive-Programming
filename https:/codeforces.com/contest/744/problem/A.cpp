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
//ll max1 = (ll)1e9;
ll govt[1005] = {0};
vector<pair<ll, ll>> vect1, vect2;
ll ct = 0, flag = 0, cnt_edges = 0;
void dfs(vector<ll> adj[], ll vis[], ll i) {
	vis[i] = 1;
	//cout << i << " ";
	ct++; cnt_edges += adj[i].size();
	if (govt[i] == 1) flag = 1;
	for (ll x : adj[i]) {
		if (vis[x] == 0) dfs(adj, vis, x);
		else continue;
	}
	return;
}
int main() {
#ifndef ONLINE_JUDGE
	freopen("C:/Users/Utkarsh Kumar Singh/Desktop/ALL CODE/input.txt", "r", stdin);
	freopen("C:/Users/Utkarsh Kumar Singh/Desktop/ALL CODE/output.txt", "w", stdout);
	freopen("C:/Users/Utkarsh Kumar Singh/Desktop/ALL CODE/err.txt", "w", stderr);
#endif
	ll i, j, k, n, m, t, ans = 0;
	cin >> n >> m >> k;
	for (i = 0; i < k; i++) {
		cin >> j;
		govt[j] = 1;
	}
	vector<ll> adj[n + 1];
	for (i = 1; i <= m; i++) {
		cin >> j >> t;
		adj[j].pb(t);
		adj[t].pb(j);
	}
	ll vis[n + 1] = {0};
	for (i = 1; i <= n; i++) {
		if (vis[i] == 0) {
			flag = 0; ct = 0; cnt_edges = 0;
			dfs(adj, vis, i);
			if (flag == 1) vect1.pb(mp(ct, cnt_edges / 2));
			else vect2.pb(mp(ct, cnt_edges / 2));
		}
	}
	sort(vect1.begin(), vect1.end());
	sort(vect2.begin(), vect2.end());
	reverse(vect1.begin(), vect1.end());
	/*for (ll x : vect1) cout << x << " ";
	cout << endl;
	for (ll x : vect2) cout << x << " ";*/
	ll max1 = 0; j = 0;
	for (i = 0; i < vect1.size(); i++) {
		ll val = (vect1[i].F * (vect1[i].F - 1)) / 2;
		if (val > max1) {
			j = i;
			max1 = (vect1[i].F * (vect1[i].F - 1)) / 2;
		}
		ans += (vect1[i].F * (vect1[i].F - 1)) / 2;
	}
	ans -= max1;
	ll nodes = 0, edges = 0;
	if (vect1.size() >= 1) {nodes = vect1[j].F; edges = vect1[j].S;}
	for (i = 0; i < vect2.size(); i++) {
		nodes += vect2[i].F;
		edges += vect2[i].S;
	}
	//cout << nodes << " " << edges << " ";
	cout << (nodes * (nodes - 1)) / 2 - m + ans << endl;
	return 0;
}
