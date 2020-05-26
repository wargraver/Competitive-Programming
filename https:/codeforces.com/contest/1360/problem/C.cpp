#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll inf = (ll)1e18;
ll mod = 1000000001;
ll gcd(ll a, ll b) {
	if (a % b) return b;
	else return gcd(b, a % b);
}
ll max1 = (ll)1e9;
int main() {
#ifndef ONLINE_JUDGE
	freopen("C:/Users/Utkarsh Kumar Singh/Desktop/ALL CODE/input.txt", "r", stdin);
	freopen("C:/Users/Utkarsh Kumar Singh/Desktop/ALL CODE/output.txt", "w", stdout);
	//freopen("C:/Users/Utkarsh Kumar Singh/Desktop/ALL CODE/err.txt", "w", stderr);
#endif
	ll i, j, k, n, m, ct = 0, t, ans = 0;
	cin >> t;
	while (t--) {
		cin >> n;
		vector<ll> even, odd;
		ll flag = 0;
		for (i = 0; i < n; i++) {
			cin >> k;
			if (k % 2 == 0) even.push_back(k);
			else odd.push_back(k);
		}
		if (even.size() % 2 == 0 && odd.size() % 2 == 0) flag = 1;
		else {
			for (i = 0; i < odd.size(); i++) {
				for (j = 0; j < even.size(); j++) {
					if (even[j] == odd[i] - 1 || even[j] == odd[i] + 1) {
						flag = 1; break;
					}
				}
			}
		}
		if (flag == 1) cout << "YES\n";
		else cout << "NO\n";
	}
	return 0;
}
