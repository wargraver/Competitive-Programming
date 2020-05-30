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
ll check(ll mid, ll n) {
	ll ct = n, ct1 = 0;
	while (ct > 0) {
		ct1 += min(ct, mid);
		ct -= min(ct, mid);
		ct -= ct / 10;
	}
	if (2 * ct1 >= n ) return 1;
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
	cin >> n;
	ll low = 1, high = n;
	while (low <= high) {
		ll mid = (low + high) / 2;
		if (check(mid, n) == 1) {
			ans = mid;
			high = mid - 1;
		}
		else low = mid + 1;
	}
	cout << ans << endl;
	return 0;
}
