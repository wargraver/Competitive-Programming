//https://codeforces.com/contest/474/problem/D
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
ll mod = 1e9 + 7; ll k;
ll max1 = (ll)1e9; //ll ans = 0;
ll b[100005] = {0};
ll getways(ll n) {
	if (n == 0) return 1;
	if (b[n] != -1) return b[n] % mod;
	ll ans = 0;
	if (n >= k) ans += getways(n - k) % mod, ans %= mod;
	ans += getways(n - 1) % mod; ans %= mod;
	return b[n] = ans;
}
int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	freopen("err.txt", "w", stderr);
#endif
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	ll i, j, n, m, ct = 0, t;
	cin >> t >> k;
	memset(b, -1, sizeof(b));
	b[0] = 1;
	ll pref[100005] = {0};
	for (i = 1; i <= 100000; i++) pref[i] += (pref[i - 1] + getways(i)) % mod;
	while (t--) {
		ll a, b; //ans = 0;
		cin >> a >> b;
		cout << (mod + (pref[b] - pref[a - 1])) % mod << endl;
	}
	return 0;
}
