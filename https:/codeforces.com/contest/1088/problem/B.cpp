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
	cin >> n >> k;
	ll a[n]; ll sum = 0;
	set<ll> dict;
	for (i = 0; i < n; i++) cin >> a[i];
	for (i = 0; i < n; i++) dict.insert(a[i]);
	sort(a, a + n);
	j = 0;
	for (i = 1; i <= k; i++) {
		auto it = dict.find(a[j]);
		if (it != dict.end()) {
			//cout << a[j] << " " << sum << endl;
			cout << a[j] - sum << endl;
			sum += (a[j] - sum);
			while (j < n && *it == a[j]) j++;
		}
		else cout << "0\n";
	}
	return 0;
}
