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
//ll max1 = (ll)1e9;
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
		ll x, y;
		cin >> n >> x >> y;
		vector<ll> temp; ll max1 = 1e18;
		vector<ll> vect3;
		ll max_diff = y - x;
		for (i = 1; i <= max_diff; i++) {
			for (j = 1; j <= 50; j++) {
				ct = 0;
				vector<ll> temp;
				for (k = 0; k < n; k++) {
					ll last = 0;
					if (temp.size() != 0) last = temp[temp.size() - 1];
					ll val = j + k * i;
					temp.pb(val);
					if (val == y || val == x) ct++;

				}
				if (ct == 2 && temp.size() == n) {
					ll max3 = temp[temp.size() - 1];
					if (max3 < max1) {
						max1 = max3;
						vect3.clear();
						for (k = 0; k < n; k++) vect3.pb(temp[k]);
					}
				}
			}
		}
		for (i = 0; i < n; i++) cout << vect3[i] << " ";
		cout << endl;
	}
	return 0;
}
