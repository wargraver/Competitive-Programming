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
	freopen("C:/Users/Utkarsh Kumar Singh/Desktop/ALL CODE/input.txt", "r", stdin);
	freopen("C:/Users/Utkarsh Kumar Singh/Desktop/ALL CODE/output.txt", "w", stdout);
	freopen("C:/Users/Utkarsh Kumar Singh/Desktop/ALL CODE/err.txt", "w", stderr);
#endif
	ll i, j, k, n, m, ct = 0, t, ans = 0;
	cin >> n;
	ll a[n]; ll min1 = 1e9;
	for (i = 0; i < n; i++) cin >> a[i];
	t = 0;
	for (t = 1; t <= 105; t++) {
		ct = 0;
		for (i = 0; i < n; i++) {
			if (a[i] < t) {
				ct += (t - 1 - a[i]);
			}
			else if (a[i] > t) ct += (a[i] - t - 1);
		}
		if (ct < min1) {
			min1 = ct;
			j = t;
		}
	}
	cout << j << " " << min1 << endl;
	return 0;
}
