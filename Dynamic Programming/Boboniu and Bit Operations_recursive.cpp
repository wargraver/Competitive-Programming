//https://codeforces.com/contest/1395/problem/C
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
ll max1 = (ll)1e9; ll n;
vector<ll> vect[205]; ll x = inf;
ll min_val(ll j, ll ans, ll ct) {
	if (ct == n) return ans;
	if (j == 0) return inf;
	else {
		ll val = inf;
		for (ll i = 0; i < vect[j - 1].size(); i++) {
			val = min(min(min_val(j - 1, ans, ct), min_val(j - 1, ans | vect[j - 1][i], ct + 1)), val);
		}
		return val;
	}
}
int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	freopen("err.txt", "w", stderr);
#endif
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	ll i, j, k, m, ct = 0, t, ans = 0;
	cin >> n >> m;
	ll a[n], b[m];
	//vect.pb(0);
	for (i = 0; i < n; i++) cin >> a[i];
	for (j = 0; j < m; j++) cin >> b[j];
	for (i = 0; i < n; i++) {
		for (j = 0; j < m; j++) {
			k = a[i] & b[j];
			//cout << k << endl;
			vect[i].pb(k);
		}
	}
	//ll ans = 0;
	//for (i = 0; i < vect.size(); i++) cout << vect[i] << " ";
	cout << min_val(n, ans, 0);
	return 0;
}
