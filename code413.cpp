#include<bits/stdc++.h>
using namespace std;
typedef int ll;
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
		string str;
		cin >> n;
		string str2; ll kt = -1;
		cin >> str; ll flag = 0;
		ll l = str.size() - 1; j = str.size() + 1;
		while (l >= 0) {
			if (str[l] == '0' && kt == -1) {kt = 0; j = l;}
			if (str[l] == '1' && kt == 0) {flag = 1; break;}
			l--;
		}
		k = -1; l = str.size();
		for (i = 0; i < l; i++) {
			if (str[i] == '1') {
				k = i;
				break;
			}
		}
		//cout << k << " " << j << endl;
		if (flag == 1) {
			for (i = 0; i < k; i++) {
				str2 += str[i];
			}
			str2 += '0';
			for (i = j + 1; i < str.size(); i++) str2 += str[i];
			cout << str2;
			cout << endl;
		}
		else {cout << str; cout << endl;}
	}
	return 0;
}