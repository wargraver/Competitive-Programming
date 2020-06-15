#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
using namespace std;
#define fo(i,n) for(i=0;i<n;i++)
#define Fo(i,k,n) for(i=k;i<n;i++)
#define pa pair<int,int>
#define vec vector<int>
#define pb push_back
#define mp make_pair
#define F first
#define S second
#define clr(x) memset(x, 0, sizeof(x))
#define init(x, a) memset(x, a, sizeof(x))
ll inf = (ll)1e18;
ll mod = 1000000001;
ll max1 = (ll)1e9, flag = 0;
/*void mark(ll vis[], ll i, vector<ll> adj[]) {
	if (vis[i] == 0) {
		vis[i] = 1;
		for (ll x : adj[i]) mark(vis, x, adj);
	}
	else return;
}*/
bool dfs(ll i, vector<ll> adj[], ll vis[], ll parent, ll j) {
	vis[i] = 1;
	//cout << i << " ";
	if (adj[i].size() > 2 || adj[i].size() <= 1) flag = 1;
	for (ll x : adj[i]) {
		if (vis[x] == 1 && parent == x) continue;
		else if (vis[x] == 1 && adj[x].size() == 2 && flag != 1 && parent != x && i == j) return true;
		else if (vis[x] == 0) dfs(x, adj, vis, i, j);
	}

	return false;
}
int main() {
#ifndef ONLINE_JUDGE
	freopen("C:/Users/Utkarsh Kumar Singh/Desktop/ALL CODE/input.txt", "r", stdin);
	freopen("C:/Users/Utkarsh Kumar Singh/Desktop/ALL CODE/output.txt", "w", stdout);
	//freopen("C:/Users/Utkarsh Kumar Singh/Desktop/ALL CODE/err.txt", "w", stderr);
#endif
	ll i, j, k, n, m, ct = 0, t, ans = 0;
	cin >> n >> m;
	ll vis[n + 1] = {0};
	vector<ll> adj[n + 1];
	for (i = 0; i < m; i++) {
		cin >> j >> k;
		adj[j].pb(k);
		adj[k].pb(j);
	}
	for (i = 1; i <= n; i++) {
		if (vis[i] == 0) {
			flag = 0;
			if (dfs(i, adj, vis, -1, i)) {ct++; /*cout << i << endl;*/}
		}
	}
	cout << ct << endl;
	return 0;
}
