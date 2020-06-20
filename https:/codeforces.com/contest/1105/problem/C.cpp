#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define fo(i,n) for(i=0;i<n;i++)
#define Fo(i,k,n) for(i=k;i<=n;i++)
#define pa pair<ll,ll>
#define vec vector<ll>
#define pb push_back
#define in insert
#define mp make_pair
#define F first
#define S second
#define clr(x) memset(x, 0, sizeof(x))
#define init(x, a) memset(x, a, sizeof(x))
ll inf = (ll)1e18;
ll mod = 1e9 + 7;
ll max1 = (ll)1e9;
ll dp[3][200001];
int main() {
/*#ifndef ONLINE_JUDGE
	freopen("C:/Users/Utkarsh Kumar Singh/Desktop/ALL CODE/input.txt", "r", stdin);
	freopen("C:/Users/Utkarsh Kumar Singh/Desktop/ALL CODE/output.txt", "w", stdout);
	freopen("C:/Users/Utkarsh Kumar Singh/Desktop/ALL CODE/err.txt", "w", stderr);
#endif*/
	ll i, j, k, n, m, ct = 0, t, ans = 0, l, r;
	cin >> n >> l >> r;
	ll c[3] = {0};
	l += 2 , r += 3;
	for (i = 0; i < 3; i++) c[i] = (r - i) / 3 - (l - i) / 3;
	/*for (i = 0; i < 3; i++) {
		for (j = 0; j < 100; j++) dp[i][j] = 0;
	}*/
	dp[0][0] = 1;
	for (i = 1; i <= n; i++) {
		dp[0][i] = ((dp[0][i - 1] * c[0]) % mod + (dp[1][i - 1] * c[2]) % mod + (dp[2][i - 1] * c[1]) % mod) % mod;
		dp[1][i] = ((dp[0][i - 1] * c[1]) % mod + (dp[1][i - 1] * c[0]) % mod + (dp[2][i - 1] * c[2]) % mod) % mod;
		dp[2][i] = ((dp[0][i - 1] * c[2]) % mod + (dp[1][i - 1] * c[1]) % mod + (dp[2][i - 1] * c[0]) % mod) % mod;
	}
	cout << dp[0][n] % mod;
	return 0;
}
