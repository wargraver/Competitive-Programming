//https://codeforces.com/contest/1419/problem/D2
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
//memset(x, 0, sizeof(x))
ll inf = (ll)1e18;
ll mod = 1e9 + 7;
ll max1 = (ll)1e9;
int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	freopen("err.txt", "w", stderr);
#endif
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	ll i, j, k, n, m, ct = 0, t, ans = 0;
	cin >> n;
	ll a[n];
	for (i = 0; i < n; i++) cin >> a[i];
	sort(a, a + n);
	ll b[n] = {0}; j = 0;
	//for (i = 0; i < n; i++) cout << a[i] << " ";
	//cout << endl;
	//memset(b, -1, sizeof(b));
	for (i = 1; i < n ; i += 2) {
		if (i <= n - 1) {
			b[i] = a[j];
			j++;
			k = j;
		}
	}
	//cout << j << endl;
	for (i = 0; i < n; i++) {
		if (b[i] == 0) {
			b[i] = a[j];
			j++;
		}
	}
	//for(i)
	for (i = 1; i <= n - 2; i++) {
		if (b[i - 1] > b[i] && b[i + 1] > b[i]) ct++;
	}
	cout << ct << endl;
	for (i = 0; i < n; i++) cout << b[i] << " ";
	return 0;
}
