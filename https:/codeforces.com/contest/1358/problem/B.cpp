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
	// freopen("C:/Users/Utkarsh Kumar Singh/Desktop/ALL CODE/err.txt", "w", stderr);
#endif
	ll i, j, k, n, m, ct = 0, t, ans = 0;
	cin >> t;
	while (t--) {
		cin >> n;
		vector<int> vec, vec2;
		vec.push_back(0);
		for (i = 1; i <= n; i++) {
			cin >> k;
			vec.push_back(k);
		}
		sort(vec.begin(), vec.end());
		ct = 1; ll kt = 1;
		ll l = 0; j = 0; i = 0;
		for (i = 1; i <= n; i++) {
			if (ct + i - l > vec[i]) {
				ct += i - l;
				l = i;
			}
		}
		cout << ct << endl;
	}
	return 0;
}
