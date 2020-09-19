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
ll near_great(ll x, ll b[], ll n) {
	ll i, j, k;
	ll low = 0, high = n - 1; ll ans = -1;
	while (low <= high) {
		ll mid = (low + high) / 2;
		if (b[mid] >= x) {
			ans = mid;
			high = mid - 1;
		}
		else low = mid + 1;
	}
	if (ans != -1) return b[ans];
	else return b[n - 1];
}
ll near_prev(ll x, ll b[], ll n) {
	ll i, j, k;
	ll low = 0, high = n - 1; ll ans = -1;
	while (low <= high) {
		ll mid = (low + high) / 2;
		if (b[mid] <= x) {
			ans = mid;
			low = mid + 1;
		}
		else high = mid - 1;
	}
	if (ans != -1) return b[ans];
	else return b[0];
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
		ll n1, n2, n3; ans = inf;
		cin >> n1 >> n2 >> n3;
		ll a[n1], b[n2], c[n3];
		for (i = 0; i < n1; i++) cin >> a[i];
		for (i = 0; i < n2; i++) cin >> b[i];
		for (i = 0; i < n3; i++) cin >> c[i];
		sort(a, a + n1);
		sort(b, b + n2);
		sort(c, c + n3);
		for (i = 0; i < n1; i++) {
			ll f1 = near_great(a[i], c, n3);
			ll f2 = near_prev(a[i], b, n2);
			ans = (a[i] - f1) * (a[i] - f1) + (f1 - f2) * (f1 - f2) + (a[i] - f2) * (a[i] - f2);
			f1 = near_prev(a[i], c, n3);
			f2 = near_great(a[i], b, n2);
			ans = min(ans, (a[i] - f1) * (a[i] - f1) + (f1 - f2) * (f1 - f2) + (a[i] - f2) * (a[i] - f2));
		}
		for (i = 0; i < n2; i++) {
			ll f1 = near_great(b[i], c, n3);
			ll f2 = near_prev(b[i], a, n1);
			ans = min(ans, (b[i] - f1) * (b[i] - f1) + (f1 - f2) * (f1 - f2) + (b[i] - f2) * (b[i] - f2));
			f1 = near_prev(b[i], c, n3);
			f2 = near_great(b[i], a, n1);
			ans = min(ans, ((b[i] - f1) * (b[i] - f1) + (f1 - f2) * (f1 - f2) + (b[i] - f2) * (b[i] - f2)));
		}
		for (i = 0; i < n3; i++) {
			ll f1 = near_great(c[i], a, n1);
			ll f2 = near_prev(c[i], b, n2);
			ans = min(ans, ((c[i] - f1) * (c[i] - f1) + (f1 - f2) * (f1 - f2) + (c[i] - f2) * (c[i] - f2)));
			f1 = near_prev(c[i], a, n1);
			f2 = near_great(c[i], b, n2);
			ans = min(ans, ((c[i] - f1) * (c[i] - f1) + (f1 - f2) * (f1 - f2) + (c[i] - f2) * (c[i] - f2)));
		}
		cout << ans << endl;
	}
	return 0;
}
