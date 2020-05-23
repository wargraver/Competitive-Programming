#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll inf = (ll)1e18;
ll mod = 1000000001;
ll gcd(ll a, ll b) {
	if (a % b) return b;
	else return gcd(b, a % b);
}
ll max1 = -1;
int main() {
#ifndef ONLINE_JUDGE
	freopen("C:/Users/Utkarsh Kumar Singh/Desktop/ALL CODE/input.txt", "r", stdin);
	freopen("C:/Users/Utkarsh Kumar Singh/Desktop/ALL CODE/output.txt", "w", stdout);
	//freopen("C:/Users/Utkarsh Kumar Singh/Desktop/ALL CODE/err.txt", "w", stderr);
#endif
	ll i, j, k, n, m, ct = 0, t, ans = 0;
	cin >> n;
	vector<ll> a(200001), b(200001);
	for (i = 0; i < n; i++) {
		cin >> a[i];
		b[a[i]]++;
	} j = 0;
	for (i = 0; i < 200001; i++) {
		if (max1 < b[i]) {
			max1 = b[i];
			j = i;
		}
	}
	for (i = 0; i < n; i++) {
		if (j == a[i]) {
			k = i;
			break;
		}
	}
	cout << n - max1 << endl;
	for (j = k - 1; j >= 0; j--) {
		if (a[j] < a[k]) cout << "1 " << j + 1 << " " << j + 2 << endl;
		else if (a[j] > a[k]) cout << "2 " << j + 1 << " " << j + 2 << endl;
	}
	for (j = k + 1; j < n ; j++) {
		if (a[j] != a[k]) {
			if (a[j] < a[k]) cout << "1 " << j + 1 << " " << j  << endl;
			else cout << "2 " << j + 1 << " " << j << endl;
		}
	}
	return 0;
}
