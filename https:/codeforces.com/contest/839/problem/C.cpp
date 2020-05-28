#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#include <bits/stdc++.h>
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
//#define init(x, a) memset(x, a, sizeof(x))
ll inf = (ll)1e18;
ll mod = 1000000001;
ll max1 = (ll)1e9;
vec leaf;
void dfs(ll vis[], double prob[], ll len[], ll i, vec adj[]) {
	if (vis[i] == 0) {
		vis[i] = 1;
		//cout << i << " ";
		ll m = adj[i].size();
		for (int j = 0; j < adj[i].size(); j++) if (vis[adj[i][j]] == 1) m--;
		for (int j = 0; j < adj[i].size(); j++) if (vis[adj[i][j]] != 1 && m > 0) prob[adj[i][j]] = (double)(prob[i] / m);
		if (m == 0) leaf.pb(i);
		for (int x : adj[i]) {
			if (vis[x] == 0) len[x] = len[i] + 1;
			dfs(vis, prob, len, x, adj);
		}
	}
}
int main() {
#ifndef ONLINE_JUDGE
	freopen("C:/Users/Utkarsh Kumar Singh/Desktop/ALL CODE/input.txt", "r", stdin);
	freopen("C:/Users/Utkarsh Kumar Singh/Desktop/ALL CODE/output.txt", "w", stdout);
	//freopen("C:/Users/Utkarsh Kumar Singh/Desktop/ALL CODE/err.txt", "w", stderr);
#endif
	ll i, j, k, n, m, ct = 0, t, ans = 0;
	ios_base::sync_with_stdio(false);
	cin >> n;
	ll vis[n + 1] = {0}, len[n + 1] = {0};
	double prob[n + 1] = {0};
	vec adj[n + 1];
	for (i = 1; i < n; i++) {
		cin >> j >> k;
		adj[j].pb(k);
		adj[k].pb(j);
	}
	len[1] = 0;
	prob[1] = 1;
	dfs(vis, prob, len, 1, adj);
	double val = 0;
	for (int x : leaf) {
		val += (double)(prob[x] * len[x]);
	}
	cout << setprecision(12) << val << endl;
	return 0;
}
