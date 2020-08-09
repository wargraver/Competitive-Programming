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
ll max1 = (ll)1e9;
ll powerLL(ll x, ll n)
{
	ll result = 1;
	while (n) {
		if (n & 1)
			result = result * x % mod;
		n = n / 2;
		x = x * x % mod;
	}
	return result;
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
	cin >> n;
	ll res = 1;
	for (i = 1; i <= n; i++) res = (res * i) % mod;
	cout << (mod + (res - powerLL(2, n - 1))) % mod << endl;
	return 0;
}
