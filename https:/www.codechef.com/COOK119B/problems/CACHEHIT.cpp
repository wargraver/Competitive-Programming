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
		ll b;
		cin >> n >> b >> m;
		k = (n + b - 1) / b;
		j = 0;
		ct = 0;
		ll bl = -1;
		for (i = 0; i < m; i++) {
			cin >> j;
			ll curr_block = j / b + 1;
			if (curr_block != bl) {
				ct++;
				bl = curr_block;
			}
			else continue;
		}
		cout << ct << endl;
	}
	return 0;
}
