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
		cin >> n >> k;
		ll a[n], moves = k;
		for (i = 0; i < n; i++) {
			scanf("%1lld", &a[i]);
		}
		ct = 0; ll kt = 0;
		for (i = 0; i < n; i++) {
			if (a[i] == 1) ct++;
			else if (a[i] == 0 && ct != 0) {
				ll j = min(moves, ct);
				a[i] = 1;
				a[i - j] = 0;
				moves -= j;
				if (moves <= 0) break;
			}
		}
		for (i = 0; i < n; i++) cout << a[i];
		cout << endl;
	}
	return 0;
}
