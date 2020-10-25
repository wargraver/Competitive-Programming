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
		cin >> n >> m;
		ll b[1000];
		ll row[n][m], col[m][n];
		for (i = 0; i < n; i++) {
			for (j = 0; j < m; j++) cin >> row[i][j];
		}
		for (i = 0; i < m; i++) {
			for (j = 0; j < n; j++) cin >> col[i][j];
		}
		for (i = 0; i < m; i++) {
			k = col[i][0];
			ll flag = 0;
			for (j = 0; j < n; j++) {
				if (k == row[j][0]) {
					b[0] = j;
					flag = 1;
					break;
				}
			}
			ct = 1;
			if (flag == 1) {
				for (j = 1; j < n; j++) {
					k = col[i][j];
					for (ll x = 0; x < n; x++) {
						if (k == row[x][0]) {
							b[ct] = x;
							ct++;
							break;
						}
					}
				}
			}
		}
		for (i = 0; i < n; i++) {
			k = b[i];
			for (j = 0; j < m; j++) cout << row[k][j] << " ";
			cout << endl;
		}
	}
	return 0;
}
