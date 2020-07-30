//https://codeforces.com/contest/1388/problem/A
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
		ll sum = 10 + 6 + 14;
		if (n > sum) {
			cout << "YES\n";
			if (n - sum == 14) cout << 6 << " " << 10 << " " << 15 << " " << 13 << endl;
			else if (n - sum == 10) cout << 6 << " " << 14 << " " << 15 << " " << 5 << endl;
			else if (n - sum == 6) cout << 6 << " " << 14 << " " << 15 << " " << 1 << endl;
			else cout << 6 << " " << 10 << " " << 14 << " " << n - sum << "\n";
		}
		else cout << "NO\n";
	}
	return 0;
}
