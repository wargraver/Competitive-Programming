//https://codeforces.com/contest/1419/problem/C
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
int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	freopen("err.txt", "w", stderr);
#endif
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	ll t;
	cin >> t;
	while (t--) {
		ll n, x;
		cin >> n >> x;
		int cntx = 0;
		ll sum = 0;

		for (int i = 0; i < n; ++i) {
			int j;
			cin >> j;

			sum += j;
			if (j == x) cntx++;
		}

		if (cntx == n) {
			cout << "0\n";
		}

		else if (x * n == sum or cntx) {
			cout << "1\n";
		}

		else cout << "2\n";
	}
	return 0;
}
