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
ll mod = 1e9 + 7, n, m, k, a[100007];
ll max1 = (ll)1e9;
ll ways(ll i, ll j, ll ct, ll sum, ll moves) {
	if (moves == m) return sum + a[i];
	else if (j < k && i > 0 && ct < 2) return max(ways(i + 1, j, 0, sum + a[i], moves + 1), ways(i - 1, j + 1, ct + 1, sum + a[i], moves + 1));
	else return ways(i + 1, j, 0, sum + a[i], moves + 1);
}
int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	freopen("err.txt", "w", stderr);
#endif
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	ll i, j, ct = 0, t, ans = 0;
	cin >> t;
	while (t--) {
		cin >> n >> m >> k;
		for (i = 0; i < n; i++) cin >> a[i];
		j = ways(0, 0, 0, 0, 0);
		cout << j << endl;
		for (i = 0; i < n; i++) a[i] = 0;
	}
	return 0;
}
