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
ll check(ll x, ll y, ll a[]) {
	ll diff = a[y] - a[x];
	if (diff <= a[x]) return 1;
	else return 0;
}
int main() {
#ifndef ONLINE_JUDGE
	freopen("C:/Users/Utkarsh Kumar Singh/Desktop/ALL CODE/input.txt", "r", stdin);
	freopen("C:/Users/Utkarsh Kumar Singh/Desktop/ALL CODE/output.txt", "w", stdout);
	//freopen("C:/Users/Utkarsh Kumar Singh/Desktop/ALL CODE/err.txt", "w", stderr);
#endif
	ll i, j, k, n, m, ct = 0, t, ans = 0;
	ios_base::sync_with_stdio(false);
	scanf("%lld", &n);
	ll a[n];
	for (i = 0; i < n; i++) {
		scanf("%lld", &k);
		a[i] = abs(k);
	}
	sort(a, a + n);
	for (i = 0; i < n; i++) {
		ll x = a[i], ans = i;
		ll low = i + 1, high = n - 1;
		while (low <= high) {
			ll mid = (low + high) / 2;
			if (check(i, mid, a) == 1) {
				ans = mid;
				low = mid + 1;
				//cout << ve[i] << " " << ve[mid] << endl;
			}
			else high = mid - 1;
		}

		ct += (ans - i);
	}
	printf("%lld\n", ct);
	return 0;
}
