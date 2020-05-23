#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll inf = (ll)1e18;
ll mod = 1000000001;
ll max1 = (ll)1e9;
ll ct = 0;
void dfs(vector<int> vec[], ll vis[], ll i, ll n, ll a[], ll k, ll kt) {
	if (vis[i] == 0) {
		vis[i] = 1;
		if (a[i] == 1) kt++;
		else if (a[i] == 0) kt = 0;
		if (kt > k) {
			kt--;
			return;
		}
		//cout << i << " ";
		if (vec[i].size() == 1 && i != 1) ct++;
		for (int x : vec[i]) {
			dfs(vec, vis, x, n, a, k, kt);
		}

	}
}
int main() {
#ifndef ONLINE_JUDGE
	freopen("C:/Users/Utkarsh Kumar Singh/Desktop/ALL CODE/input.txt", "r", stdin);
	freopen("C:/Users/Utkarsh Kumar Singh/Desktop/ALL CODE/output.txt", "w", stdout);
	//freopen("C:/Users/Utkarsh Kumar Singh/Desktop/ALL CODE/err.txt", "w", stderr);
#endif
	ll i, j, k, n, m, t, ans = 0, kt = 0;
	cin >> n >> k;
	vector<int> vec[n + 1];
	ll a[n + 1] = {0}, vis[n + 1] = {0};
	for (i = 1; i <= n; i++) cin >> a[i];
	for (i = 1; i <= n - 1; i++) {
		ll x, y;
		cin >> x >> y;
		vec[y].push_back(x);
		vec[x].push_back(y);
	}
	dfs(vec, vis, 1, n, a, k, kt);
	cout << ct;
	return 0;
}
