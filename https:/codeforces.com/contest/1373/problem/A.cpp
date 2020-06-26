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
		ll a, b, c;
		cin >> a >> b >> c;
		ll c1 = c;
		ll x =  1;
		ll c2 = a;
		if (c2 < c1) {
			cout << x << " ";
		}
		else cout << "-1 ";
		x = b;
		c1 = c; c2 = b * a;
		if (c2 > c1) {
			cout << b << " ";
		}
		else cout << "-1 ";
		cout << endl;
	}
	return 0;
}
