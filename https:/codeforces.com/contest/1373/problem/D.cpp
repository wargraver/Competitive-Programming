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
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	freopen("err.txt", "w", stderr);
#endif
	ll i, j, k, n, m, ct = 0, t, ans = 0;
	cin >> t;
	while (t--) {
		cin >> n;
		ll sum1 = 0, max2 = 0, sum2 = 0, max3 = 0, sum3 = 0;
		ll a[n];
		for (i = 0; i < n; i++) cin >> a[i];
		for (i = 0; i < n; i++) {
			if (i % 2 == 0) {
				sum1 += a[i];
				if (i + 1 <= n - 1) {
					ll diff = a[i + 1] - a[i];
					if (sum2 + diff >= 0) {
						sum2 += diff;
						max2 = max(sum2, max2);
					}
					else sum2 = 0;
				}
			}
			else {
				if (i + 1 <= n - 1) {
					ll diff = a[i] - a[i + 1];
					if (sum3 + diff >= 0) {
						sum3 += diff;
						max3 = max(sum3, max3);
					}
					else sum3 = 0;
				}
			}
		}
		cout << sum1 + max(max2, max3) << endl;
	}
	return 0;
}
