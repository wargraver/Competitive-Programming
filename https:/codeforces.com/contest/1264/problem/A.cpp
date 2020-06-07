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
		cin >> n; ct = 0;
		ll a[n + 1];
		vector<ll> vect;
		for (i = 1; i <= n; i++) cin >> a[i];
		ll mid = n / 2; k = mid + 1;
		for (j = mid; j >= 1; j--) {
			if (a[j] != a[k]) {
				break;
			}
		}
		ct = j; ll kt = 0;
		ll gold = 0, silver = 0, bronze = 0;
		for (i = 1; i <= ct; i++) {
			if (gold == 0 && a[i] == a[1]) {
				kt++;
			}
			else if (gold == 0 && a[i] != a[1]) {
				gold = kt; kt = 0;
			}
			if (silver <= gold && gold != 0) {silver++; j = i;}
			else if (silver > gold && a[j] == a[i]) silver++;
		}
		if (gold < silver && gold < ct - gold - silver) cout << gold << " " << silver << " " << ct - gold - silver << "\n";
		else cout << "0 0 0\n";
	}
	return 0;
}
