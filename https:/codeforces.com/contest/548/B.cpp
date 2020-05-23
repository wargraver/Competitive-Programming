//https://codeforces.com/problemset/problem/548/B
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll inf = (ll)1e18;
ll mod = 1000000001;
ll gcd(ll a, ll b) {
	if (a % b) return b;
	else return gcd(b, a % b);
}
int main() {
#ifndef ONLINE_JUDGE
	freopen("C:/Users/Utkarsh Kumar Singh/Desktop/ALL CODE/input.txt", "r", stdin);
	freopen("C:/Users/Utkarsh Kumar Singh/Desktop/ALL CODE/output.txt", "w", stdout);
	//freopen("C:/Users/Utkarsh Kumar Singh/Desktop/ALL CODE/err.txt", "w", stderr);
#endif
	int i, j, k, n, m, ct = 0, t, ans = 0, q, x, y;
	cin >> n >> m >> q;
	t = m + 1; k = n + 1;
	int a[501][501];
	vector<int> vec;
	vec.push_back(0);
	for (i = 1; i <= n; i++) {
		for (j = 1; j <= m; j++) cin >> a[i][j];
	}
	for (i = 1; i <= n; i++) {
		int max1 = 0; ct = 0;
		for (j = 1; j <= m; j++) {
			if (a[i][j] == 1) ct++;
			else ct = 0;
			max1 = max(max1, ct);
		}
		vec.push_back(max1);
	}
	//for (int x : vec) cout << x << " ";
	for (i = 1; i <= q; i++) {
		cin >> x >> y;
		a[x][y] = 1 - a[x][y];
		int max1 = 0; ct = 0;
		for (j = 1; j <= m; j++) {
			if (a[x][j] == 1) ct++;
			else ct = 0;
			max1 = max(max1, ct);
		}
		vec[x] = max1;
		max1 = 0;
		for (int z : vec) max1 = max(z, max1);
		cout << max1 << endl;
	}
	return 0;
}
