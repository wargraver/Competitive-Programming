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
void dfs(vector<ll> adj[], ll vis[], ll i) {
	vis[i] = 1;
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
	ll i, j, k, n, m, ct = 0, t, ans = 0;
	cin >> n;
	ll b[27] = {0};
	vector<ll> adj[27 + n + 1];
	for (i = 1; i <= n; i++) {
		string str;
		cin >> str;
		for (j = 0; j < str.size(); j++) {
			k = str[j] - 'a' + 1;
			b[k]++;
			adj[k].pb(i + 26);
			adj[i + 26].pb(k);
		}
	} ll vis[n + 28] = {0};
	for (i = 1; i <= n + 26; i++) {
		if (vis[i] == 0) {
			if (i <= 26 && b[i] > 0) {
				ct++;
				dfs(adj, vis, i);
			}
			else if (i > 26) {
				ct++;
				dfs(adj, vis, i);
			}
		}
	}
	cout << ct << endl;
	return 0;
}
