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
int main() {
#ifndef ONLINE_JUDGE
	freopen("C:/Users/Utkarsh Kumar Singh/Desktop/ALL CODE/input.txt", "r", stdin);
	freopen("C:/Users/Utkarsh Kumar Singh/Desktop/ALL CODE/output.txt", "w", stdout);
	freopen("C:/Users/Utkarsh Kumar Singh/Desktop/ALL CODE/err.txt", "w", stderr);
#endif
	ll i, j, k, n, m, ct = 0, t, ans = 0, q;
	cin >> n >> q;
	map<ll, ll> dict;
	set<ll> dict2;
	ct = 0;
	for (i = 0; i < n; i++) {
		cin >> k;
		dict[k]++;
		dict2.insert(k);
	}
	while (q--) {
		cin >> k;
		ll coins = 0;
		ct = k;
		auto it2 = dict2.begin();
		auto it = dict2.end();
		while (it2 != it && ct > 0) {
			it = lower_bound(dict2.begin(), dict2.end(), ct);
			if (*it != ct) it--;
			ll val = *it;
			ll z = ct / val;
			if (z == 0) break;
			z = min(z, dict[val]);
			ct = ct - z * val;
			coins += z;
		}
		if (ct == 0) cout << coins << endl;
		else cout << "-1\n";
	}
	return 0;
}
