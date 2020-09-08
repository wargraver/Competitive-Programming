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
ll max1 = (ll)1e9; ll b[1005] = {0};
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
		ll a[n];
		for (i = 0; i < n; i++) cin >> a[i];
		sort(a, a + n);
		memset(b, 0, sizeof(b));
		for (i = 0; i < n; i++) b[a[i]]++;
		vector<ll> vect;
		vect.pb(a[n - 1]);
		ll last = a[n - 1]; b[a[n - 1]]--; ll max_gcd = -1; j = -1;
		while (max_gcd != 1 || vect.size() < n) {
			for (i = 0; i < n; i++) {
				if (max_gcd < __gcd(last, a[i]) && b[a[i]] > 0) {
					j = i;
					max_gcd = __gcd(last, a[i]);
				}
			}
			if (j != -1) {vect.pb(a[j]); last = __gcd(last, a[j]); b[a[j]]--;}
			else if (j == -1 || max_gcd == -1) break;
			max_gcd = -1; j = -1;
		}
		for (i = 0; i <= 1000; i++) {
			while (b[i] > 0) {
				vect.pb(b[i]); b[i]--;
			}
		}
		for (i = 0; i < vect.size(); i++) cout << vect[i] << " ";
		cout << endl;
	}
	return 0;
}
