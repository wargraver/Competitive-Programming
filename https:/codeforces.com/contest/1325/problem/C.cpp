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
	cin >> n;
	vector<int> vec[n + 1];
	int a[n + 1];
	for (i = 0; i <= n; i++) a[i] = -1;
	for (i = 1; i <= n - 1; i++) {
		cin >> j >> k;
		vec[j].push_back(i);
		vec[k].push_back(i);
	}
	for (i = 1; i <= n; i++) {
		if (vec[i].size() >= 3) {
			a[vec[i][0]] = 0;
			a[vec[i][1]] = 1;
			a[vec[i][2]] = 2;
			ct = 3;
			break;
		}
	}
	for (i = 1; i < n; i++) {
		if (a[i] == -1) {
			a[i] = ct;
			ct++;
		}
	}
	for (i = 1; i < n; i++) cout << a[i] << endl;
	return 0;
}
