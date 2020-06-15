//https://codeforces.com/contest/1366/problem/C
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
using namespace std;
#define fo(i,n) for(i=0;i<n;i++)
#define Fo(i,k,n) for(i=k;i<n;i++)
#define pa pair<int,int>
#define vec vector<int>
#define pb push_back
#define mp make_pair
#define F first
#define S second
#define clr(x) memset(x, 0, sizeof(x))
#define init(x, a) memset(x, a, sizeof(x))
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
	cin >> t;
	while (t--) {
		cin >> n >> m; ct = 0;
		ll a[n][50], b[m + n - 1] = {0}, c[m + n - 1] = {0};
		for (i = 0; i < n; i++) {
			for (j = 0; j < m; j++) {
				cin >> a[i][j];
				if (a[i][j] == 0) b[i + j]++;
				else c[i + j]++;
			}
		}
		ll mid = (n + m - 2) / 2;
		for (i = 0; i <= mid; i++) {
			if (i != mid || (m + n) % 2 != 0) {
				ll x = b[i] + b[m + n - 2 - i];
				ll y = c[i] + c[m + n - 2 - i];
				ct += min(x, y);
			}
		}
		cout << ct << endl;
	}
	return 0;
}
