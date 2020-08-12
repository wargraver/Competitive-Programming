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
	ll i, j, k, n, m, ct = 0, t, ans = 0, x, y;
	cin >> n >> m >> x >> y;
	ll x1 = x, y1 = y;
	ll vis[105][105]; ll flag = 0;
	vector<pair<ll, ll>> vect;
	memset(vis, -1, sizeof(vis));
	vis[x][y] = 1;
	vect.pb(mp(x, y));
	vect.pb(mp(x, m)); vis[x][m] = 1;
	for (i = m; i >= 1; i--) {
		if (vis[x][i] == -1) {vect.pb(mp(x, i)); vis[x][i] = 1;}
	} k = x;
	vis[1][1] = 1;
	vect.pb(mp(1, 1));
	for (i = 1; i <= n; i++) {
		if (k != i && flag == 0) {
			flag = 1;
			for (j = 1; j <= m; j++) {
				if (vis[i][j] == -1) {
					vis[i][j] = 1;
					vect.pb(mp(i, j));
				}
			}
		}
		else if (flag == 1 && k != i) {
			flag = 0;
			for (j = m; j >= 1; j--) {
				if (vis[i][j] == -1) {
					vis[i][j] = 1;
					vect.pb(mp(i, j));
				}
			}
		}
	}
	for (i = 0; i < vect.size(); i++) cout << vect[i].F << " " << vect[i].S << endl;
	return 0;
}
