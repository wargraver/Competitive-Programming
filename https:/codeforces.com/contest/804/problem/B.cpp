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
ll mod = 1e9 + 7;
ll max1 = (ll)1e9;
ll fast_expo(ll r, ll n) {
	ll ans = 1;
	if (r == 0) return 0;
	while (n > 0) {
		if (n % 2 != 0) ans = (ans * r) % mod;
		r = (r * r) % mod;
		n = n / 2;
	}
	return ans % mod;
}
int main() {
#ifndef ONLINE_JUDGE
	freopen("C:/Users/Utkarsh Kumar Singh/Desktop/ALL CODE/input.txt", "r", stdin);
	freopen("C:/Users/Utkarsh Kumar Singh/Desktop/ALL CODE/output.txt", "w", stdout);
	//freopen("C:/Users/Utkarsh Kumar Singh/Desktop/ALL CODE/err.txt", "w", stderr);
#endif
	ll i, j, k, n, m, ct = 0, t, ans = 0;
	ios_base::sync_with_stdio(false);
	string str;
	cin >> str;
	ll flag = 0;
	ct = 0; ll kt = 0;
	for (i = 0; i < str.size(); i++) {
		if (str[i] == 'a') ct++;
		else if ( ct != 0 && str[i] == 'b') { kt++; }
		if ((ct != 0 && kt != 0 && i == str.size() - 1) || (str[i + 1] != 'b' && str[i] == 'b' && ct != 0)) {
			//cout << ct << " " << kt << " ";
			ll r_pow = fast_expo( 2,  ct);
			//cout << r_pow << " ";
			ans += (kt % mod * (r_pow - 1) % mod) % mod;
			//cout << ans << endl;
			kt = 0;
		}
		if (str[i] != 'a' && str[i] != 'b') {ct = 0;}
	}
	cout << ans % mod << endl;
	return 0;
}
