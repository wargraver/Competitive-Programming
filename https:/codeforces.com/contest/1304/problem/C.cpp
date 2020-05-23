#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll inf = (ll)1e18;
ll mod = 1000000001;
ll max1 = (ll)1e9;
int main() {
#ifndef ONLINE_JUDGE
	freopen("C:/Users/Utkarsh Kumar Singh/Desktop/ALL CODE/input.txt", "r", stdin);
	freopen("C:/Users/Utkarsh Kumar Singh/Desktop/ALL CODE/output.txt", "w", stdout);
	//freopen("C:/Users/Utkarsh Kumar Singh/Desktop/ALL CODE/err.txt", "w", stderr);
#endif
	ll i, j, k, n, m, ct = 0, t, ans = 0, flag = 0;
	cin >> t;
	while (t--) {
		cin >> n >> m; flag = 0;
		ll a[n + 1], b[n + 1], c[n + 1];
		a[0] = 0; b[0] = m; c[0] = m;
		for (i = 1; i <= n; i++) cin >> a[i] >> b[i] >> c[i];
		for (i = 1; i <= n; i++) {
			ll lower_bound = b[i - 1] - (a[i] - a[i - 1]);
			ll upper_bound = c[i - 1] + (a[i] - a[i - 1]);
			//cout << lower_bound << " " << upper_bound << endl;
			if (c[i] < lower_bound || b[i] > upper_bound) {
				flag = 1;
				break;
			}
			else {
				//cout << b[i] << " " << c[i] << endl;
				b[i] = max(b[i], lower_bound);
				c[i] = min(c[i], upper_bound);
			}

		}
		if (flag == 1) cout << "NO\n";
		else cout << "YES\n";
	}
	return 0;
}
