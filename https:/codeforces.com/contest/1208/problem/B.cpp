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
	ll i, j, k, n, m, ct = 0, t, ans, flag = 0;
	ios_base::sync_with_stdio(false);
	cin >> n;
	ll a[n];
	for (i = 0; i < n; i++) cin >> a[i];
	ans = n - 1;
	for (i = 0; i < n; i++) {
		flag = 0;
		map<int, int> dict;
		//dict[a[i]]++;
		for (j = 0; j < i; j++) {
			dict[a[j]]++;
			if (dict[a[j]] >= 2) {flag = 1; break;}
		}
		ll last_min = n;
		for (j = n - 1; j >= i; j--) {
			dict[a[j]]++;
			if (dict[a[j]] == 1) last_min = j;
			else break;
		}
		if (flag == 0) ans = min(ans, last_min - i);
		else continue;
	}
	cout << ans << endl;
	return 0;
}
