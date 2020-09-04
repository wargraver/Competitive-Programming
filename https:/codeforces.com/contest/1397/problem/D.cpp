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
		ll a[n]; multiset<ll> dict;
		for (i = 0; i < n; i++) {
			cin >> a[i];
			dict.in(a[i]);
		}
		auto it = dict.end(); it--;
		ll flag = 0; ct = 0; ll last = -1, prev_last = -1;
		while (flag != 1) {
			if (ct % 2 == 0) {
				it = dict.end(); it--;
				last = *it;
				auto kt = it;
				dict.erase(kt);
				if (last > 0) last--;
				else {flag = 1; break;}
				ct = 1;
				if (prev_last != -1) dict.in(prev_last);
			}
			else {
				if (dict.size() == 0) flag = 1;
				else {
					it = dict.end(); it--;
					prev_last = *it;
					auto kt = it;
					dict.erase(kt);
					if (prev_last > 0) prev_last--;
					else {flag = 1; break;}
					ct = 0;
					if (last != -1) dict.in(last);
				}

			}
		}
		//cout << ct << endl;
		if (ct % 2 != 0) cout << "T\n";
		else cout << "HL\n";
	}
	return 0;
}
