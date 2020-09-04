//https://codeforces.com/contest/1409/problem/B
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
		ll a, b, x, y, c, d, e;
		cin >> c >> d >> x >> y >> e;
		a = c; b = d; n = e;
		j = a - x; k = b - y;
		if (a == b) {
			m = max(a - x, a - y);
			a -= min(m, n);
			n -= min(m, n);
			if (n > 0) {
				if (a - x >= a - y) b -= min(n, b - y);
				else b -= min(n, b - x);
			}
			ans = a * b;
			cout << ans << endl;
		}
		else {
			a = c; b = d; n = e;
			b -= min(n, b - y);
			n -= min(n, k);
			//cout << n << " ";
			if (n > 0) {
				a -= min(n, a - x);
				n -= min(n, j);
			}
			//cout << a << " " << b << endl;
			ans = a * b;
			a = c; b = d; n = e;
			a -= min(n, a - x);
			n -= min(n, j); ll ans2;
			if (n > 0) {
				b -= min(n, b - y);
				n -= min(n, k);
				//cout << a << " " << b << endl;

			}
			ans2 = a * b;
			cout << min(ans, ans2) << endl;
		}
	}
	return 0;
}
