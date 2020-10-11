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
		ll flag = 0;
		for (i = 0; i <= 200; i++) {
			for (j = 0; j <= 200; j++) {
				if (n - 5 * i - 7 * j >= 0 && (n - 5 * i - 7 * j) % 3 == 0 ) {
					cout << (n - 5 * i - 7 * j) / 3 << " " << i << " " << j << " "  <<  endl;
					flag = 1;
					break;
				}
			}
			if (flag == 1) break;
		}
		if (flag == 0) cout << "-1\n";
	}
	return 0;
}
