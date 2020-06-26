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
ll a[400005];
int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	freopen("err.txt", "w", stderr);
#endif
	ll i, j, k, n, m, ct = 0, t, ans = 0;
	ll x = 0;
	cin >> n >> x;
	ll a[x] = {0};
	set<pair<ll, ll>> dict;
	for (i = 0; i < x; i++) {
		dict.in(mp(a[i], i));
	}
	for (i = 0; i < n; i++) {
		cin >> k;
		ll val = k % x;
		dict.erase(mp(a[val], val));
		a[val]++;
		dict.in(mp(a[val], val));
		cout << dict.begin()->F*x + dict.begin()->S << endl;
	}
	return 0;
}
