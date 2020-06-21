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
ll max1 = 0;
int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	freopen("err.txt", "w", stderr);
#endif
	ll i, j, k, n, m, ct = 0, t, ans = 0;
	cin >> t;
	while (t--) {
		cin >> n >> m; max1 = 0;
		vector<pair<ll, ll>> vect; ct = 0;
		for (i = 0; i < n; i++) {
			cin >> j >> k;
			max1 = max(max1, j);
			ll diff = j - k;
			vect.pb(mp(diff, j));
		}
		sort(vect.begin(), vect.end());
		reverse(vect.begin(), vect.end());
		if (m - max1 <= 0) cout << "1\n";
		else if (vect[0].F <= 0) cout << "-1\n";
		else {
			k = m;
			ll diff = vect[0].F;
			m = max(m, max1);
			cout << ((m - max1) + diff - 1) / diff + 1 << endl;
		}
	}
	return 0;
}
