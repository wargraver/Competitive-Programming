#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {

	ll i, j, k, n, m, ct = 0, t, ans = 0;
	cin >> t;
	while (t--) {
		ll b;
		cin >> n >> b >> m;
		k = (n + b - 1) / b;
		j = 0;
		ct = 0;
		ll bl = -1;
		for (i = 0; i < m; i++) {
			cin >> j;
			ll curr_block = j / b + 1;
			if (curr_block != bl) {
				ct++;
				bl = curr_block;
			}
		}
		cout << ct << "\n";
	}
	return 0;
}
