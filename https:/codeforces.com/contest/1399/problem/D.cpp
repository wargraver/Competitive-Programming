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
		string str;
		cin >> str;
		vector<ll> vect[n + 1];
		ll b[n + 1];
		set<ll> zeros, ones;
		ct = 0;
		for (i = 0; i < n; i++) {
			if (str[i] == '1') {
				if (zeros.size() == 0) {
					ct++;
					zeros.in(ct);
				}
				auto it = zeros.begin();
				ll val = *it;
				vect[val].pb(i);
				zeros.erase(it);
				ones.in(val);
			}
			else {
				if (ones.size() == 0) {
					ct++;
					ones.in(ct);
				}
				auto it = ones.begin();
				ll val = *it;
				vect[val].pb(i);
				ones.erase(it);
				zeros.in(val);
			}
		}
		for (i = 1; i <= n; i++) {
			for (auto x : vect[i]) {
				b[x] = i;
			}
		}
		max1 = 0;
		for (i = 0; i < n; i++) max1 = max(max1, b[i]);
		cout << max1 << endl;
		for (i = 0; i < n; i++) cout << b[i] << " ";
		cout << endl;
	}
}
