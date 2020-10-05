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
ll check(ll a, ll b, ll val1, ll val2, ll val3, ll val4) {
	if (abs(a - val1) + abs(a - val2) + abs(a - val3) + abs(a - val4) > abs(b - val1) + abs(b - val2) + abs(b - val3) + abs(b - val4)) return 1;
	else return 0;
}
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
		cin >> n >> m;
		ll a[105][105], b[105][105];
		memset(b, -1, sizeof(b));
		for (i = 1; i <= n; i++) {
			for (j = 1; j <= m; j++) cin >> a[i][j];
		}
		ans = 0;
		for (i = 1; i <= n; i++) {
			for (j = 1; j <= m; j++) {
				if (b[i][j] == -1) {
					b[i][j] = 1; b[i][m - j + 1] = 1;
					b[n - i + 1][j] = 1; b[n - i + 1][m - j + 1] = 1;
					ll val1 = a[i][j];
					ll val2 = a[n - i + 1][j];
					ll val3 = a[i][m - j + 1];
					ll val4 = a[n - i + 1][m - j + 1];
					//cout << val1 << " " << val2 << " " << val3 << " " << val4 << endl;
					ll low = min(val1, min(val2, min(val3, val4)));
					ll high = max(val1, max(val2, max(val3, val4)));
					ll tempans = 0;
					while (low <= high) {
						ll mid = (low + high) / 2;
						if (check(mid, mid + 1, val1, val2, val3, val4) == 1) {
							tempans = mid + 1;
							low = mid + 1;
						}
						else if (check(mid, mid - 1, val1, val2, val3, val4) == 1) {
							tempans = mid - 1;
							high = mid - 1;
						}
						else if (check(mid, mid + 1, val1, val2, val3, val4) == 0) {
							tempans = mid;
							high = mid - 1;
						}
						else if (check(mid, mid - 1, val1, val2, val3, val4) == 0) {
							tempans = mid;
							low = mid + 1;
						}
					}
					if (i == n - i + 1 && j == m - j + 1) continue;
					else if (i == n - i + 1) ans += abs(tempans - val1) + abs(tempans - val3);
					else if (j == m - j + 1) ans += abs(tempans - val1) + abs(tempans - val2);
					else ans += abs(tempans - val1) + abs(tempans - val2) + abs(tempans - val3) + abs(tempans - val4);
				}
			}
		}
		cout << ans << endl;
	}
	return 0;
}
