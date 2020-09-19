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
	//ios_base::sync_with_stdio(false);
	//cin.tie(NULL);
	ll i, j, k, n, m, ct = 0, t, ans = 0;
	cin >> t;
	while (t--) {
		cin >> n; ll odd = 0, even = 0;
		ll a[n + 1];
		for (i = 1; i <= n; i++) {
			scanf("%1d", &a[i]);
			if (i % 2 != 0) {
				if (a[i] % 2 == 0) even++;
			}
			else {
				if (a[i] % 2 != 0) odd++;
			}
		}
		//cout << even << " " << odd << endl;
		ll n2 = (n + 1) / 2 - even, n3 = n / 2 - odd;
		ll digits = n; ll flag = 0;
		while (digits != 1) {
			if (flag == 0) {
				if (even > 0) {
					even--;
					flag = 1;
				}
				else {
					n2--;
					flag = 1;
				}
			}
			else {
				if (odd > 0) {
					odd--;
					flag = 0;
				}
				else {
					n3--;
					flag = 0;
				}
			}
			digits--;
		}
		if (even >= 1 || n3 >= 1) cout << "2\n";
		else cout << "1\n";
	}
	return 0;
}
