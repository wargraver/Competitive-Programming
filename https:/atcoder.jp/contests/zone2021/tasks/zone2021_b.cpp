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
	ll i, j, n, d, h, ct = 0, t;
	std::cout << setprecision(18);
	double ans  = 0;
	cin >> n >> d >> h;
	for (int t = 0; t < n; t++) {
		cin >> i >> j;
		double m = (double)(d - i) / (h - j);
		double k = (double)i / m;
		//cout << j - k << endl;
		ans = max(ans, j - k);
	}
	cout << ans << endl;

	return 0;
}
