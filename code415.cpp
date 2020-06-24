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
vector<ll> vect(2000006);
ll max1 = (ll)1e9;
int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	freopen("err.txt", "w", stderr);
#endif
	ll i, j, k, n, m, ct = 0, t, ans = 0;
	vect[1] = 0;
	vect[2] = 0;
	for (i = 3; i <= vect.size() - 1; i++) {
		if (i % 3 == 0) vect[i] = (vect[i - 1] + 2 * vect[i - 2] + 1) % mod;
		else vect[i] = (vect[i - 1] + 2 * vect[i - 2]) % mod;
	}
	cin >> t;
	while (t--) {
		cin >> k;
		cout << (vect[k] * 4) % mod << endl;
	}
	return 0;
}