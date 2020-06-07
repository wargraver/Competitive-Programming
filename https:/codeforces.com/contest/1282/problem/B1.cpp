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
	ll i, j, k, n, m, ct = 0, t, ans = 0, p;
	ios_base::sync_with_stdio(false);
	cin >> t;
	while (t--) {
		cin >> n >> p >> k;
		ll even = 0, odd = 0;
		ll a[n + 1]; ans = n;
		for (i = 1; i <= n; i++) cin >> a[i];
		sort(a + 1, a + n + 1);
		for (i = 1; i <= n; i++) {
			ll sum = 0;
			if (i % 2 == 0) {
				even += a[i]; sum = even;
			}
			else {odd += a[i]; sum = odd;}
			if (sum > p) {
				ans = i - 1;
				break;
			}
		}
		cout << ans << endl;
	}
	return 0;
}
