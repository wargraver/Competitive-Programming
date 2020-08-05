//https://codeforces.com/contest/466/problem/C
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
	ll i, j, k, n, m, ct = 0, t, ans = 0;
	cin >> n; ll sum = 0;
	ll a[n + 1], b[n + 1] = {0};
	for (i = 0; i < n; i++) {
		cin >> a[i];
		sum += a[i];
	}
	//cout << sum << endl;
	if (sum % 3 == 0) {
		ll s1 = 0, ct2 = 0, ct3 = 0;
		for (i = 0; i < n - 1; i++) {
			s1 += a[i];
			if (s1 == (2 * sum) / 3) ct3 += ct2;
			if (s1 == sum / 3) ct2++;
		}
		cout << ct3;
	}
	else cout << "0";
	return 0;
}
