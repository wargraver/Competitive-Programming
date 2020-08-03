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
ll a[10000];
ll max1 = (ll)1e9;
ll fib(ll n) {
	if (n == 0 || n == 1) return 1;
	if (a[n] == -1) return fib(n - 1) + fib(n - 2);
	else {
		return a[n];
	}
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
		cin >> n;
		memset(a, -1, sizeof(a));
		a[0] = 1; a[1] = 1;
		cout << fib(n - 1) << endl;
	}
	return 0;
}
