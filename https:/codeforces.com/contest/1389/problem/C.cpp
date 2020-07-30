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
int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	freopen("err.txt", "w", stderr);
#endif
	ll i, j, k, n, m, ct = 0, t, ans = 0;
	cin >> t;
	while (t--) {
		ct = 0; ll kt = 0;
		string str; ans = 0;
		cin >> str;
		ll n = (ll)str.size();
		ll a[10] = {0};
		for (i = 0; i < n; i++) {
			ll diff = str[i] - '0';
			a[diff]++;
		}
		for (i = 0; i <= 9; i++) ans = max(ans, a[i]);
		for (char ch = '0'; ch <= '9'; ch++) {
			for (char ch2 = '0'; ch2 <= '9'; ch2++) {
				i = 0; j = 0; ll st1 = 0; ct = 0;
				while (st1 <= n - 1) {
					ll flag1 = 0, flag2 = 0;
					for (i = st1; i < n; i++) {
						if (str[i] == ch) {flag1 = 1; st1 = i + 1; break;}
					}
					if (flag1 == 1) {
						for (i = st1; i < n; i++) {
							if (str[i] == ch2) {flag2 = 1; st1 = i + 1; break;}
						}
					}
					if (flag1 == 1 && flag2 == 1) ct++;
					else break;
				}
				kt = max(ct, kt);
			}
		}
		cout << min(n - ans, n - 2 * kt) << endl;
	}
	return 0;
}
