#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
using namespace std;
#define fo(i,n) for(i=0;i<n;i++)
#define Fo(i,k,n) for(i=k;i<n;i++)
#define pa pair<int,int>
#define vec vector<int>
#define pb push_back
#define mp make_pair
#define F first
#define S second
#define clr(x) memset(x, 0, sizeof(x))
#define init(x, a) memset(x, a, sizeof(x))
ll inf = (ll)1e18;
ll mod = 1000000001;
ll max1 = (ll)1e9;
ll check(ll a[], ll b[], ll m, ll n, ll k) {
	ll ct = 0, z = 0;
	for (ll i = 0; i < n; i++) ct += max(z, a[i] * m - b[i]);
	if (ct <= k) return 1;
	else return 0;
}
int main() {
#ifndef ONLINE_JUDGE
	freopen("C:/Users/Utkarsh Kumar Singh/Desktop/ALL CODE/input.txt", "r", stdin);
	freopen("C:/Users/Utkarsh Kumar Singh/Desktop/ALL CODE/output.txt", "w", stdout);
	//freopen("C:/Users/Utkarsh Kumar Singh/Desktop/ALL CODE/err.txt", "w", stderr);
#endif
	ll i, j, k, n, m, ct = 0, t, ans = 0;
	ios_base::sync_with_stdio(false);
	cin >> n >> k;
	ll a[n], b[n];
	for (i = 0; i < n; i++) cin >> a[i];
	for (i = 0; i < n; i++) cin >> b[i];
	ll low = 1, high = 1e9;
	while (low <= high) {
		ll mid = (low + high) / 2;
		if (check(a, b, mid, n, k) == 1) {
			ans = mid;
			low = mid + 1;
		}
		else high = mid - 1;
	}
	cout << ans << endl;
	return 0;
}
