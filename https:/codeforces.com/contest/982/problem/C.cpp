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
ll max1 = (ll)1e9;
ll ans = 0;
//ll size[N] = {0};
void dfs(ll curr, ll parent, vector<ll> adj[], ll size[] ) {
	size[curr] = 1;
	for (ll x : adj[curr]) {
		if (x == parent) continue;
		dfs(x, curr, adj, size);
		size[curr] += size[x];
		//all even sized child removed
		if (size[x] % 2 == 0) ans++;
	}
}
int main() {
#ifndef ONLINE_JUDGE
	freopen("C:/Users/Utkarsh Kumar Singh/Desktop/ALL CODE/input.txt", "r", stdin);
	freopen("C:/Users/Utkarsh Kumar Singh/Desktop/ALL CODE/output.txt", "w", stdout);
	//freopen("C:/Users/Utkarsh Kumar Singh/Desktop/ALL CODE/err.txt", "w", stderr);
#endif
	ll i, j, k, n, m, ct = 0, t;
	ios_base::sync_with_stdio(false);
	cin >> n;
	vector<ll> adj[n + 1];
	for (i = 1; i <= n - 1; i++) {
		cin >> j >> k;
		adj[k].pb(j);
		adj[j].pb(k);
	}
	ll size[n + 1] = {0};
	if (n % 2 != 0) ans = -1;
	else dfs(1, -1, adj, size);
	cout << ans << endl;
	return 0;
}
