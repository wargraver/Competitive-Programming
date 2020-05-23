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
	//freopen("C:/Users/Utkarsh Kumar Singh/Desktop/ALL CODE/err.txt", "w", stderr);
#endif
	ll i, j, k, n, m, ct = 0, t, ans = 0;
	cin >> n >> k;
	ll a[n], b[n];
	vector<ll> vec;
	map<ll, ll> dict;
	for (i = 0; i < n; i++) cin >> a[i];
	for (i = 0; i < n; i++) cin >> b[i];
	for (i = 0; i < n; i++) dict.insert({a[i], b[i]});
	//for (auto it = dict.begin(); it != dict.end(); it++) cout << it->first << " " << it->second << endl;
	for (auto it2 = dict.begin(); it2 != dict.end(); it2++) {
		for (i = 0; i < vec.size(); i++) ans += vec[i];

		sort(vec.begin(), vec.end());
		if (k > vec.size()) vec.push_back(it2->second);
		else if (k == vec.size() && k != 0) {
			if (vec[0] < it2->second) {
				vec.erase(vec.begin());
				vec.push_back(it2->second);
			}
		}
		it2->second += ans; ans = 0;
		sort(vec.begin(), vec.end());
	}
	for (i = 0; i < n; i++) cout << dict[a[i]] << " ";
	return 0;
