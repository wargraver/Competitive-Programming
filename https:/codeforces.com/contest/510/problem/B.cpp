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
#define init(x, a) memset(x, a, sizeof(x))
ll inf = (ll)1e18;
ll ct = 0;
ll mod = 1000000001;
ll max1 = (ll)1e9;
ll flag = 0;
int dfs(vector<int> adj[], int vis[], ll i, ll parent) {
	vis[i] = 1;
	//cout << i << " ";
	for (int x : adj[i]) {
		if (vis[x] == 0) {
			if (dfs(adj, vis, x, i) == 1) return 1;
		}
		else if (x != parent) return 1;

	}
	return 0;
}
int main() {
#ifndef ONLINE_JUDGE
	freopen("C:/Users/Utkarsh Kumar Singh/Desktop/ALL CODE/input.txt", "r", stdin);
	freopen("C:/Users/Utkarsh Kumar Singh/Desktop/ALL CODE/output.txt", "w", stdout);
	//freopen("C:/Users/Utkarsh Kumar Singh/Desktop/ALL CODE/err.txt", "w", stderr);
#endif
	ll i, j, k, n, m, t, ans = 0;
	ios_base::sync_with_stdio(false);
	cin >> n >> m;
	ll a[51][51];
	ll total = n * m + 1;
	vector<int> adj[total];
	for (i = 0; i < n; i++) {
		for (j = 0; j < m; j++) {
			char ch;
			cin >> ch;
			a[i][j] = ch - 'A';
		}
	}
	for (i = 0; i < n; i++) {
		for (j = 0; j < m  ; j++) {
			if (i != n - 1 && a[i][j] == a[i + 1][j]) {
				ll c1 = i * m + j;
				ll c2 = (i + 1) * m + j;
				//cout << c1 << " " << c2 << endl;
				adj[c1].push_back(c2);
				adj[c2].push_back(c1);
			}
			if (j != m - 1 && a[i][j] == a[i][j + 1]) {
				ll c1 = i * m + j;
				ll c2 = (i) * m + j + 1;
				//cout << c1 << " " << c2 << endl;
				adj[c1].push_back(c2);
				adj[c2].push_back(c1);
			}
			//cout << (i)*m + j << " ";
		}
	}
	int vis[total] = {0};
	for (i = 0; i < total; i++) {
		if (vis[i] == 0) flag = dfs(adj, vis, i, -1);
		if (flag == 1) break;

	}
	if (flag == 1) cout << "Yes\n";
	else cout << "No\n";
	return 0;
}
