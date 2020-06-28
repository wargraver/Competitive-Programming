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
	ll i, j, k, n, m, ct = 0, t;
	cin >> n >> k;
	vector<ll> a, freq(200005, 0);
	for (i = 0; i < n; i++) {
		cin >> j;
		a.pb(j);
		freq[j]++;
	}
	vector<ll> ans;
	ll low = 1, high = n;
	while (low <= high) {
		ll mid = (low + high) / 2;
		vector<ll> curr;
		for (i = 1; i < freq.size(); i++) {
			for (j = 0; j < freq[i] / mid; j++) curr.pb(i);
		}
		if (curr.size() >= k) {
			ans.clear();
			for (i = 0; i < curr.size(); i++) {
				ans.pb(curr[i]);
			}
			low = mid + 1;
		}
		else high = mid - 1;
	}
	for (i = 0; i < k; i++) cout << ans[i] << " ";
	return 0;
}
