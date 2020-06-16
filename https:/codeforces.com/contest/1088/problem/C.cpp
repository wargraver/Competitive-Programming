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
//ll max1 =(ll)1e9;
int main() {
#ifndef ONLINE_JUDGE
	freopen("C:/Users/Utkarsh Kumar Singh/Desktop/ALL CODE/input.txt", "r", stdin);
	freopen("C:/Users/Utkarsh Kumar Singh/Desktop/ALL CODE/output.txt", "w", stdout);
	freopen("C:/Users/Utkarsh Kumar Singh/Desktop/ALL CODE/err.txt", "w", stderr);
#endif
	ll i, j, k, n, m, ct = 0, t, ans = 0;
	cin >> n;
	ll a[n]; ll max1 = 100005;
	for (i = 0; i < n; i++) {
		cin >> k;
		a[i] = k + max1;
		//cout << a[i] << " ";
	}// cout << endl;
	cout << n + 1 << endl;
	cout << "1 " << n << " " << max1 << endl;
	for (i = 0; i < n; i++) {
		j = i + 1;
		k = a[i]; t = j;
		for (t = j; t <= k; t++) {
			if (k % t == j) break;
		}
		//for (ll l = 0; l <= i; l++) a[l] = a[l] % t;
		cout << "2 " << i + 1 << " " << t  << endl;
	}
	//for (ll y : a) cout << y << " ";
	return 0;
}
