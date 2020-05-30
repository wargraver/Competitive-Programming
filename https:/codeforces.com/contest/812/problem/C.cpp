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
ll check(ll a[], ll mid, ll n, ll s) {
	vector<ll> dict;
	for (ll i = 1; i <= n; i++) dict.push_back(a[i] + i * mid);
	sort(dict.begin(), dict.end());
	ll sum = 0;
	for (ll i = 0; i < mid; i++) sum += dict[i];
	if (sum <= s) return 1;
	else return 0;
}
int main() {
#ifndef ONLINE_JUDGE
	freopen("C:/Users/Utkarsh Kumar Singh/Desktop/ALL CODE/input.txt", "r", stdin);
	freopen("C:/Users/Utkarsh Kumar Singh/Desktop/ALL CODE/output.txt", "w", stdout);
	//freopen("C:/Users/Utkarsh Kumar Singh/Desktop/ALL CODE/err.txt", "w", stderr);
#endif
	ll i, j, k, n, m, ct = 0, t, ans = 0, s;
	ios_base::sync_with_stdio(false);
	cin >> n >> s;
	ll a[n + 1] = {0};
	for (i = 1; i <= n; i++) cin >> a[i];
	ll low = 1, high = n;
	while (low <= high) {
		ll mid = (low + high) / 2;
		if (check(a, mid, n, s) == 1) {
			ans = mid;
			low = mid + 1;
		}
		else high = mid - 1;
	}
	ll sum = 0;
	for (i = 1; i <= n; i++) a[i] = (a[i] + i * ans);
	//for (int x : a) cout << x << " ";
	//cout << endl;
	sort(a, a + n + 1);
	for (i = 1; i <= ans; i++) sum += a[i];
	cout << ans << " " << sum << endl;
	return 0;
}
