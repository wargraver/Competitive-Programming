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
		ll flag = 0; m = n;
		while (flag != 1) {
			vector<ll> vect;
			k = m;
			while (k != 0) {
				j = k % 10;
				if (j != 0) vect.pb(j);
				k = k / 10;
			}
			ll flag2 = 0;
			for (i = 0; i < vect.size(); i++) {
				if (m % vect[i] != 0) flag2 = 1;
			}
			if (flag2 == 0) {cout << m << endl; flag = 1;}
			else m++;
		}
	}
	return 0;
}
