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
ll a[1000];
//recuirsively we hqave 2 choices either to take a coin or not taking it
//if we have 0 coins since no chnage can be formed we include the no of coins to be 1e9 as there can not be that much coins with given constraints
ll coin(ll val, ll n, ll a[]) {
	if (val == 0) return 0;
	else if (n == 0) return max1;
	else if (a[n] <= val) return min(1 + coin(val - a[n], n, a), coin(val, n - 1, a));
	else return coin(val, n - 1, a);
}
int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	freopen("err.txt", "w", stderr);
#endif
	ll i, j, k, n, m, ct = 0, t, ans = 0;
	cin >> t;
	while (t--) {
		cin >> n >> k;
		ll a[k + 1];
		for (i = 1; i <= k; i++) cin >> a[i];
		j = coin(n, k, a);
		if (j == max1) j = -1;
		cout << j << endl;
	}
	return 0;
}
