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
	cin >> t;
	while (t--) {
		ll r, g, w, b;
		cin >> r >> g >> b >> w;
		ll flag = 0; ct = 0; ll kt = 0;
		ll r1, g1, w1, b1;
		if (r != 0 && g != 0 && b != 0) {
			r1 = r - 1; g1 = g - 1; w1 = w + 3; b1 = b - 1;
			if (r1 % 2 == 0) kt++;
			if (g1 % 2 == 0) kt++;
			if (b1 % 2 == 0) kt++;
			if (w1 % 2 == 0) kt++;
		}
		if (r % 2 == 0) ct++;
		if (g % 2 == 0) ct++;
		if (b % 2 == 0) ct++;
		if (w % 2 == 0) ct++;
		//if (w % 2 == 0) ct++;
		if (ct >= 3 ) flag = 1;
		if (kt >= 4 || kt >= 3) flag = 1;
		if (r + g + w + b == r || r + g + w + b == b || r + g + w + b == g) flag = 1;
		//if (r == 0 && b == 0 && )
		if (flag == 1) cout << "Yes\n";
		else cout << "No\n";
	}
	return 0;
}
