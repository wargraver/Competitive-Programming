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
	cin >> n;
	ll a[n];
	for (i = 0; i < n; i++) cin >> a[i];
	map<ll, ll> dict;
	for (i = n - 1; i >= 0; i--) {
		ll val = a[i];
		if (dict.find(val + 1) == dict.end()) dict[val] = 1;
		else dict[val] = dict[val + 1] + 1;
	} ll max2 = -1;
	for (auto it = dict.begin(); it != dict.end(); it++) {
		if (max2 < it->S) {
			k = it->F;
			max2 = it->S;
		}
	}
	cout << max2 << endl;
	for (i = 0; i < n; i++) {
		if (a[i] == k) {
			cout << i + 1 << " ";
			k++;
		}
	}
	return 0;
}
