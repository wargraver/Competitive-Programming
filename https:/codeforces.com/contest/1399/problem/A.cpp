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
		cin >> n;
		ll a[n]; ll flag = 0;
		for (i = 0; i < n; i++) cin >> a[i];
		sort(a, a + n);
		for (i = 1; i < n; i++) {
			ll diff = a[i] - a[i - 1];
			if (diff <= 1) continue;
			else {flag = 1; break;}
		}
		if (flag == 1) cout << "NO\n";
		else cout << "YES\n";
	}
	return 0;
}
