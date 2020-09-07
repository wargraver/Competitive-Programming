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
ll max1 = (ll)1e9; ll pref[10005] = {0}, a[10005],  k;
ll ways(ll st, ll en) {
	if (st >= en) return 0;
	else {
		ll ans = 1e18;
		for (int j = st; j <= en - 1; j++) {
			ll sum = pref[j] - pref[st] + a[st];
			ll sum2 = pref[en] - pref[j + 1] + a[j + 1];
			ll temp = ways(st, j) + ways(j + 1, en) + (sum + sum2) * k;
			//cout << st << " " << j << " " << en << " " << temp << endl;
			ans = min(temp, ans);
		}
		return ans;
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
	ll i, j, n, m, ct = 0, t;
	cin >> n >> k;
	for (i = 0; i < n; i++) cin >> a[i];
	ll sum = 0;
	for (i = 0; i < n; i++) {
		pref[i] += sum + a[i];
		sum += a[i];
	}
	cout << ways(0, n - 1) << endl;
	return 0;
}
