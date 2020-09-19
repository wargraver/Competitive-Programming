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
	ll sum = 1; ll diff = 2; vector<ll> vect;
	vect.pb(1);
	while (sum <= 1e18) {
		sum += diff;
		vect.pb(sum);
		diff = diff * 2;
	}
	//for (i = 0; i < 63; i++) cout << ((vect[i]) * (vect[i] + 1)) / 2 << " ";
	//cout << endl;
	//cout << vect.size() << endl;
	//cout << vect[0] << " " << vect[vect.size() - 1] << endl;
	while (t--) {
		ll x;
		cin >> x; ll val = 0; ans = 0; sum = 0;
		//cout << x << endl;
		i = 0;
		while (sum < x) {
			sum += (vect[i] * (vect[i] + 1) / 2);
			if (sum <= x) ans++;
			i++;
		}
		cout << ans << endl;
	}
	return 0;
}
