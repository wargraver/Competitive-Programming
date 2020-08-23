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
ll freq[100007] = {0};
ll dfs(ll i, ll vis[], vector<ll> dict[]) {
	vis[i] = 1;
	for (auto x : dict[i]) {
		if (vis[x] == 0) freq[i] += (dfs(x, vis, dict) + 1);
	}
	return freq[i];
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
		cin >> n;
		vector<ll> dict[n + 1], vect;
		for (i = 1; i <= n - 1; i++) {
			cin >> j >> k;
			dict[j].pb(k);
			dict[k].pb(j);
		}
		cin >> m;
		for (i = 0; i < m; i++) {
			cin >> j;
			vect.pb(j);
		}
		sort(vect.begin(), vect.end());
		if (m > n - 1) {
			auto it = vect.end();
			it--;
			ll val = 1;
			while (m != n - 2) {
				auto kt = it;
				j = *it;
				val = (val * j) % mod;
				//cout << j << " " << val << endl;
				val %= mod;
				vect.erase(kt);
				it--; m--;
			}
			vect.pb(val);
		}
		if (vect.size() < n - 1) {
			while (vect.size() != n - 1) vect.pb(1);
			sort(vect.begin(), vect.end());
		}
		//for (i = 0; i < n; i++) cout << vect[i] << " ";
		ll vis[n + 1] = {0};
		freq[1] = dfs(1, vis, dict);
		for (i = 1; i <= n; i++) freq[i] = (freq[i] + 1) * (n - freq[i] - 1);
		sort(freq, freq + n + 1);
		ans = 0;
		for (i = 2; i <= n; i++) {
			ans += (freq[i] * vect[i - 2]) % mod;
			ans %= mod;
		}
		cout << ans % mod << endl;
		//for (i = 1; i <= n; i++) cout << freq[i] << " ";
		//	for (i = 1; i <= )
		for (i = 0; i <= n; i++) freq[i] = 0;

	}
	return 0;
}
