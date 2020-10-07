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
ll max1 = (ll)1e9; ll min2 = inf, n, a[200][200];
ll ways(ll col, ll row, ll ans) {
	if (col >= 0 && col < n && row == n) return ans;
	else {
		if (col == n - 1) return min(ways(col - 1, row + 1, ans + a[row][col]), ways(col, row + 1, ans + a[row][col]));
		else if (col == 0) return min(ways(col + 1, row + 1, ans + a[row][col]), ways(col, row + 1, ans + a[row][col]));
		else return min(ways(col + 1, row + 1, ans + a[row][col]), min(ways(col, row + 1, ans + a[row][col]), ways(col - 1, row + 1, ans + a[row][col])));
	}
}
int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	freopen("err.txt", "w", stderr);
#endif
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	ll i, j, k, m, ct = 0, t, ans = 0;
	cin >> n;
	for (i = 0; i < n; i++) {
		for (j = 0; j < n; j++) cin >> a[i][j];
	}
	min2 = inf;
	for (i = 0; i < n; i++) {
		min2 = min(min2, ways(i, 0, 0));
		//cout << ways(i, 0, 0) << endl;
	}
	cout << min2;
	return 0;
}
