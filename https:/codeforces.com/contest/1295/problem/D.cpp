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
ll phi(ll n) {
	ll res = n;
	for (ll i = 2; i <= sqrt(n); i++) {
		if (n % i == 0) {
			res /= i;
			res *= (i - 1);
			while (n % i == 0) n /= i;
		}
	}
	if (n > 1) { res /= n; res *= (n - 1);}
	return res;
}
int main() {
#ifndef ONLINE_JUDGE
	freopen("C:/Users/Utkarsh Kumar Singh/Desktop/ALL CODE/input.txt", "r", stdin);
	freopen("C:/Users/Utkarsh Kumar Singh/Desktop/ALL CODE/output.txt", "w", stdout);
	freopen("C:/Users/Utkarsh Kumar Singh/Desktop/ALL CODE/err.txt", "w", stderr);
#endif
	ll i, j, k, n, m, ct = 0, t, ans = 0, a, b;
	cin >> t;
	while (t--) {
		cin >> a >> b;
		k = __gcd(a, b);
		j = b / k;
		ans = phi(j);
		cout << ans << endl;
	}
	return 0;
}
