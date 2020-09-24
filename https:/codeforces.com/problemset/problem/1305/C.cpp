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
	ll i, j, k, n, m, ct = 0, t, ans = 1;
	cin >> n >> m;
	ll a[n], b[1005] = {0};
	map<ll, ll> dict;
	for (i = 0; i < n; i++) {
		cin >> a[i];
	}
	if (n <= m) {
		for (i = 0; i < n; i++) {
			for (j = i + 1; j < n; j++) {
				ll sum = abs(a[j] - a[i]);
				ans = (ans * sum) % m;
			}
		}
		cout << ans % m;
	}
	else cout << "0";
	return 0;
}
