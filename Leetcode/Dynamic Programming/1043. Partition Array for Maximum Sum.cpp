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
ll max1 = (ll)1e9; ll a[602], n;
ll dp[601][601]; ll val[605][605];
ll ways(ll st, ll en) {
	if (en >= n || st >= n) return 0;
	if (st > en) return -inf;
	if (en == st) {/*cout << " " << st << " " << " " << en << endl; */return val[st][en] = dp[en][st];}
	else if (val[st][en] == -1) {
		ll ans = dp[st][en];
		for (ll j = st; j <= en - 1; j++) {
			ll temp2 = ways(st, j) + ways(j + 1, en);
			//	cout << temp2 << " " << st << " " << j << " " << en << endl;
			ans = max(ans, temp2);
		}
		return val[st][en] = ans;
	}
	else return val[st][en];
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
	cin >> n >> m;
	for (i = 0; i < n; i++) cin >> a[i];
	for (i = 0; i < n; i++) {
		ll sum = 0;
		for (j = i; j < n; j++) {
			sum += a[j];
			dp[i][j] = sum;
		}
	}
	//cout << "val st en dp" << endl;
	for (i = 0; i < n; i++) {
		ll yoo = 0;
		ll st = max(i - (m - 1), yoo);
		for (j = st; j <= i; j++) {
			for (k = i; k <= min(i + m - 1, n - 1); k++) {
				ll elem = k - j + 1;
				if (elem > m) break;
				dp[j][k] = max(dp[j][k], elem * a[i]);
				//cout << i << " " << j << " " << k << " " << dp[j][k] << endl;
			}
		}
	}
	memset(val, -1, sizeof(val));
	cout << ways(0, n - 1);
	return 0;
}
