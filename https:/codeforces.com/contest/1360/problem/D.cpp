#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll inf = (ll)1e18;
ll mod = 1000000001;
ll val(ll n, ll k) {
	ll max1 = 1;
	for (ll i = 1; i <= sqrt(n); i++) {
		if (n % i == 0 && i <= k) {
			max1 = max(max1, i);
			if (n / i <= k) max1 = max(n / i, max1);
		}
	}
	return max1;
}
//ll max1 =(ll)1e9;
int main() {
#ifndef ONLINE_JUDGE
	freopen("C:/Users/Utkarsh Kumar Singh/Desktop/ALL CODE/input.txt", "r", stdin);
	freopen("C:/Users/Utkarsh Kumar Singh/Desktop/ALL CODE/output.txt", "w", stdout);
	// freopen("C:/Users/Utkarsh Kumar Singh/Desktop/ALL CODE/err.txt", "w", stderr);
#endif
	ll i, j, k, n, m, ct = 0, t, ans = 0;
	cin >> t;
	while (t--) {
		cin >> n >> k;
		m = val(n, k);
		cout << n / m << endl;
	}
	return 0;
}
