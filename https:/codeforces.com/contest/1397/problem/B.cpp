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
string str;

int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	freopen("err.txt", "w", stderr);
#endif
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	ll i, j, k, n, m, ct = 0, t, ans = 0;
	cin >> n;
	ll a[n];
	for (i = 0; i < n; i++) cin >> a[i];
	ans = 1e18;
	sort(a, a + n);
	for (i = 1; i <= 1e9; i++) {
		ll sum = 0; k = 1;
		for (j = 0; j < n; j++) {
			sum += abs(a[j] - k);
			if (k >= 1e14) {cout << ans; return 0;}
			k = k * i;
			//cout << k << " ";
		} //cout << sum << endl;
		if (sum >= ans) break;
		else ans = min(sum, ans);
	}
	cout << ans << endl;
	return 0;
}
