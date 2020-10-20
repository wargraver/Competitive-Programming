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
		cin >> n;
		ll a[n], kt = 0; ct = 0;
		for (i = 0; i < n; i++) cin >> a[i];
		ll sol = 0; ll flag = 0;
		ll count = 0;
		for (i = 0; i < n; i++)
		{
			if (a[i] == 1 && (flag == 1))
			{
				sol = sol + count;
				count = 0;
			}
			if (a[i] == 1)
			{
				flag = 1;
				count = 0;
			}

			if (flag == 1 && a[i] == 0)
				count++;
		}
		cout << sol << endl;

	}
	return 0;
}
