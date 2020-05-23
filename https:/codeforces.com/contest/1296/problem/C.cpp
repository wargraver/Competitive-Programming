//https://codeforces.com/problemset/problem/1296/C
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll inf = (ll)1e18;
ll mod = 1000000001;
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
		string str;
		cin >> n >> str;
		map<pair<int, int>, int> dict;
		dict.insert({make_pair(0, 0), 0});
		pair<int, int> p = {0, 0};
		ll left = -1, right = n;
		for (i = 0; i < n; i++) {
			if (str[i] == 'L') p.first--;
			else if (str[i] == 'R') p.first++;
			else if (str[i] == 'D') p.second--;
			else p.second++;
			if (dict.count(p)) {
				if (i - dict[p] + 1 < right - left + 1) {
					left = dict[p];
					right = i;
				}
			}
			dict[p] = i + 1;
		}
		if (left == -1) cout << "-1\n";
		else cout << left + 1 << " " << right + 1 << "\n";
	}
	return 0;
}
