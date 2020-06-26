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
ll even(ll m, ll a[], ll n, ll j) {
	ll sum = 0, i, k = 0;
	for (i = 1; i <= n; i++) {
		if (sum % 2 == 0) sum++;
		else {
			if (a[i] <= m) sum++;
		}
	}
	if (sum >= j) return 1;
	else return 0;
}
ll odd(ll m, ll a[], ll n, ll j) {
	ll sum = 0, i, k = 0;
	for (i = 1; i <= n; i++) {
		if (sum % 2 != 0) sum++;
		else {
			if (a[i] <= m) sum++;
		}
	}
	if (sum >= j) return 1;
	else return 0;
}
int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	freopen("err.txt", "w", stderr);
#endif
	ll i, j, k, n, m, ct = 0, t, ans = 1e9;
	cin >> n >> j;
	ll a[n + 1];
	for (i = 1; i <= n; i++) cin >> a[i];
	ll low = 1, high = 1e9;
	while (low <= high) {
		ll mid = (low + high) / 2;
		if (odd(mid, a, n, j) == 1 || even(mid, a, n, j) == 1) {
			ans = mid;
			high = mid - 1;
			//cout << ans << endl;
		}
		else low = mid + 1;
		//cout << mid << endl;
	}
	cout << ans << endl;
	return 0;
}
