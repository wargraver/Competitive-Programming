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
ll flag = 0;
bool dfs(vector<ll> adj[], ll u, vector<bool>& visited, vector<bool>& recStack)
{
	if (!visited[u])
	{
		visited[u] = recStack[u] = true;

		for (auto v : adj[u])
		{
			if (!visited[v] && dfs(adj, v, visited, recStack))
				return true;
			else if (recStack[v])
				return true;
		}

	}

	recStack[u] = false;
	return false;
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
		cin >> n >> m;
		vector<ll> adj[n + 1];
		ans = m;
		for (i = 0; i < m; i++) {
			cin >> j >> k;
			if (j != k) {
				adj[j].pb(k);
			}
			else ans--;
		}
		vector<bool> vis(n + 1, false), recStack(n + 1, false);

		for (i = 1; i <= n; i++)
		{
			if (!vis[i] && dfs(adj, i, vis, recStack))
				ans++;
		}
		cout << ans << endl;
	}
	return 0;
}
