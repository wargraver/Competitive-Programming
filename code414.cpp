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
		cin >> n >> m;
		ll a[n] = {0}; ll sum = 0;
		for (i = 0; i < n; i++) cin >> a[i];
		sort(a, a + n);
		ll b[m];
		for (i = 0; i < m; i++) cin >> b[i];
		sort(b, b + m);
		//for (i = 0; i < m; i++) cout << b[i] << " ";
		k = 0; j = n - 1;
		for (i = 0; i < m; i++) {
			if (b[i] == 1) {
				sum += 2 * a[j];
				b[i] = -1;
				j--;
			}
			else break;
		} ct = 1;
		sort(b, b + m);
		reverse(b, b + m);
		//for (i = 0; i < m; i++) cout << b[i] << " ";
		ll l = 0;
		for (i = 0; i < m; i++) {
			if (b[i] != -1) {
				sum += a[j]; j--;
				sum += a[k];
				k += (b[i] - 1);
				//cout << b[i] << " " << j << " " << k << endl;
			}
		}
		cout << sum << endl;
	}
	return 0;
}