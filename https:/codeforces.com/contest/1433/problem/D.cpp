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
		ll a[n];
		for (i = 0; i < n; i++) cin >> a[i];
		ct = 0; k = a[0]; map<ll, ll> dict;
		for (i = 0; i < n; i++) dict[a[i]] = i;
		for (i = 0; i < n; i++) {
			if (a[i] == k) ct++;
		}
		if (ct == n) cout << "NO\n";
		else {
			cout << "YES\n";
			auto it = dict.begin();
			auto kt = dict.begin();
			kt++;
			ll ind1 = it->S, ind2 = kt->S;
			//cout << ind1 << " " << ind2 << endl;
			ll freq[n + 1] = {0};
			for (i = 0; i < n; i++) {
				if (a[ind1] == a[i]) continue;
				else {
					cout << ind1 + 1 << " " << i + 1 << endl;
					freq[i] = 1;
					freq[ind1] = 1;
				}
			}
			for (i = 0; i < n; i++) {
				if (a[ind2] == a[i]) continue;
				else if (freq[i] == 1) continue;
				else {
					cout << ind2 + 1 << " " << i + 1 << endl;
					freq[i] = 1;
				}
			}
		}
	}
	return 0;
}
