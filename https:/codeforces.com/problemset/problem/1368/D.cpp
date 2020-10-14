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
	ll a[22] = {0};
	for (i = 0; i < n; i++) {
		cin >> k;
		ct = 0;
		while (k) {
			ll x = k & 1;
			if (x == 1) a[ct]++;
			k = k >> 1;
			ct++;
		}
	}
	ans = 0;
	//for (i = 0; i < 22; i++) cout << a[i] << " ";
	ll flag = 0;
	while (flag == 0) {
		ll val = 0;
		for (i = 0; i < 22; i++) {
			if (a[i] > 0) {
				//	cout << i << " ";
				val += pow(2, i);
				a[i]--;
			}
		}
		ans += val * val;
		if (val == 0) flag = 1;
	}
	cout << ans << endl;
	return 0;
}
