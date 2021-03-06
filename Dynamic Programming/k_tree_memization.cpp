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
ll a[1000] = {0}, k, max2;
ll b[1000] = {0};
ll ways(ll n, ll m, ll ct) {
	if (n == 0) return 1;
	else if (m == 0) return 0;
	else if (b[n] == -1) {
		ll res = 0;
		for (ll i = 1; i <= m; i++) {
			if (n >= i) {
				res += ways(n - i, m, ct) ;
			}
		}
		b[n] = res % mod ;
		return res % mod ;
	}
	else return b[n] % mod ;
}
int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	freopen("err.txt", "w", stderr);
#endif
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	ll i, j, n, m, ct = 0, t, ans = 0;
	cin >> n >> m >> k;
	for (i = 1; i <= m; i++) a[i] = i;
	memset(b, -1, sizeof(b));
	ll m1 = ways(n, m, 0) ;
	memset(b, -1, sizeof(b));
	ll m2 = ways(n, k - 1, 0);
	//cout << m1 << " " << m2 << endl;
	cout << (mod + (m1 - m2)) % mod << endl;
	return 0;
}
