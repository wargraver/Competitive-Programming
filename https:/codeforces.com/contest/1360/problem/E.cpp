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
	int i, j, k, n, m, ct = 0, t, ans = 0;
	cin >> t;
	while (t--) {
		cin >> n;
		int a[n][n];
		int flag = 0;
		for (i = 0; i < n; i++) {
			for (j = 0; j < n; j++) {
				scanf("%1d", &a[i][j]);
			}
		}
		for (i = n - 1; i >= 0; i--) {
			for (j = 0; j < n - 1; j++) {
				//cout << a[i][j] << " " << i << j << " ";
				if (i == n - 1) continue;
				if (a[i][j] == 1 && (a[i][j + 1] == 0 && a[i + 1][j] == 0)) {
					//cout << "NO\n";
					flag = 1; break;
				}
			}
			if (flag == 1) break;
		}
		if (flag == 1) cout << "NO\n";
		else cout << "YES\n";
	}
	return 0;
}
