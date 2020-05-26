#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll inf = (ll)1e18;
ll mod = (ll)1e9 + 7;
ll max1 = (ll)1e9;
int dp[4][10000001];
ll ways(ll i, ll n) {
	if (n == 0 && i == 3) return 1;
	else if (n == 0) return 0;
	else {
		if (dp[i][n] != -1) return dp[i][n];
		else {
			dp[i][n] = 0;
			for (ll j = 0; j <= 3; j++) {
				if (j != i) {
					dp[i][n] = dp[i][n] % mod;
					dp[i][n] += ways(j, n - 1) % mod;
					dp[i][n] = dp[i][n] % mod;
				}
			}
		}
	}
	return dp[i][n] ;
}
int main() {
#ifndef ONLINE_JUDGE
	freopen("C:/Users/Utkarsh Kumar Singh/Desktop/ALL CODE/input.txt", "r", stdin);
	freopen("C:/Users/Utkarsh Kumar Singh/Desktop/ALL CODE/output.txt", "w", stdout);
	//freopen("C:/Users/Utkarsh Kumar Singh/Desktop/ALL CODE/err.txt", "w", stderr);
#endif
	ll i, j, k, n, m, ct = 0, t, ans = 0;
	cin >> n;
	for (i = 0; i < 4; i++) {
		for (j = 0; j <= 10000000 ; j++) dp[i][j] = -1;
	}

	cout << ways(3, n);
	return 0;
}
