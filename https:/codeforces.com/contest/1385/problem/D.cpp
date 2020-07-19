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
vector<ll> str;
ll getmin(ll s, ll e,  ll ch) {
	ll ct = 0, kt = 0;
	if (e == s) {
		if (str[e] == ch) return 0;
		else return 1;
	}
	ll mid = (e + s) / 2;
	for (ll i = s; i <= mid; i++) if (str[i] != ch) ct++;
	for (ll i = mid + 1; i <= e; i++) if (str[i] != ch) kt++;
	return min(ct + getmin(mid + 1, e,  ch + 1), kt + getmin(s, mid, ch + 1));
}
int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	freopen("err.txt", "w", stderr);
#endif
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	ll i, j, k, n, m, ct = 0, t, ans = 0;
	cin >> t;
	while (t--) {
		str.clear();
		cin >> n; char ch;

		for (i = 0; i < n; i++) {
			cin >> ch;
			ll diff = ch - 'a';
			str.pb(diff);
		}
		ans = getmin(0, n - 1, 0);
		cout << ans << endl;
	}
	return 0;
}
