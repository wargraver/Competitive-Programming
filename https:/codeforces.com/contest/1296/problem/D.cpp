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
	ll i, j, k, n, m, ct = 0, t, ans = 0, a, b;
	cin >> n >> a >> b >> k;
	vector<int> vec, val;
	for (i = 0; i < n; i++) {
		cin >> m;
		vec.push_back(m);
	}
	//sort(vec.begin(), vec.end());
	for (i = 0; i < n; i++) {
		//ll quo = vec[i] / (a + b);
		ll rem = vec[i] % (a + b);
		ll req = (a + rem - 1) / a;
		if (rem == 0) val.push_back((b + a - 1) / a);
		else if (rem <= a) val.push_back(0);
		else if (rem > a) val.push_back(req - 1);
	}
	sort(val.begin(), val.end());
	for (i = 0; i < n; i++) {
		if (ans + val[i] <= k) {
			ans += val[i];
		}
		else break;
	}
	cout << i;
	return 0;
}
