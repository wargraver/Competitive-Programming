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
ll a[1000][1000];
ll coin(ll val, ll n, ll b[]) {
	if (val == 0) return 0;
	else if (n == 0) return max1;
	if (a[n][val] == -1) {
		if (b[n] <= val) return min(1 + coin(val - b[n], n, b), coin(val, n - 1, b));
		else return coin(val, n - 1, b);
	}
	else return a[n][val];
}
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
		cin >> n >> k;
		ll b[k + 1];
		memset(a, -1, sizeof(a));
		for (i = 0; i < 1000; i++) a[i][0] = 0;
		for (i = 0; i < 1000; i++) a[0][i] = max1;
		for (i = 1; i <= k; i++) cin >> b[i];
		j = coin(n, k, b);
		if (j == max1) j = -1;
		cout << j << endl;
	}
	return 0;
}
