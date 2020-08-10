//https://codeforces.com/problemset/problem/118/D
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
ll max1 = (ll)1e9, k1, k2;
ll ways(ll n1, ll n2, ll c1, ll c2) {
	if (c1 > k1 || c2 > k2 ) return 0;
	else if (n1 == 0 && n2 == 0) return 1;
	if (n1 >= 1 && n2 >= 1) return ways(n1 - 1, n2, c1 + 1, 0) + ways(n1, n2 - 1, 0, c2 + 1);
	else if (n1 >= 1)  return ways(n1 - 1, n2, c1 + 1, 0);
	else if (n2 >= 1) return ways(n1, n2 - 1, 0, c2 + 1);
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
	ll n1, n2;
	cin >> n1 >> n2 >> k1 >> k2;
	cout << ways(n1, n2, 0, 0);
	return 0;
}
