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
		ans = 0;
		ll x1, y1, z1, x2, y2, z2;
		cin >> z1 >> y1 >> x1;
		cin >> z2 >> y2 >> x2;
		//for 2
		if (x1 <= y2) {
			ans += x1 * 2;
			y2 -= x1; x1 = 0;
		}
		else {
			ans += y2 * 2 ; x1 -= y2;
			y2 = 0;
			if (x1 <= x2) {
				ans += x1 * 0;
				x2 -= x1;
				x1 = 0;
			}
			else {
				ans += x2 * 0;
				x1 -= x2;
				x2 = 0;
				z2 -= x1;
				x1 = 0;
			}
		}
		//for 1
		if (y1 <= y2) {
			ans += y1 * 0;
			y2 -= y1; y1 = 0;
		}
		else {
			ans += y2 * 0; y1 -= y2;
			y2 = 0;
			if (y1 <= z2) {
				//ans+=x1*2;
				z2 -= y1;
				y1 = 0;
			}
			else {
				//ans+=y2*2;
				y1 -= z2;
				z2 = 0;
				ans -= y1 * 2;
				x2 -= y1;
				y1 = 0;
			}
		}
		cout << ans << endl;

	}
	return 0;
}
