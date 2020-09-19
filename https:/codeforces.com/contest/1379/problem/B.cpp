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
		ll l, r;
		cin >> l >> r >> m;
		ll min1 = 0, max2 = r - l;
		for (i = l; i <= r; i++) {
			if (m % i == 0) {
				cout << i << " " << r << " " << r << endl;
				break;
			}
			else {
				ll rem = m % i;
				ll req = i - rem;
				if (req <= max2 && l + req <= r) {
					cout << i << " " << l << " " << l + req << endl;
					break;
				}
				else if (rem <= max2 && l + rem <= r) {
					cout << i << " " << l + rem << " " << l << endl;
					break;
				}
			}
		}
	}
	return 0;
}
