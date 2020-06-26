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
string str;
ll check( ll ct) {
	for (ll i = 0; i < str.size(); i++) {
		if (str[i] == '-') ct--;
		else ct++;
		if (ct < 0) return 0;
	}
	return 1;
}
int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	freopen("err.txt", "w", stderr);
#endif
	ll i, j, k, n, m, ct = 0, t, ans = 0;
	cin >> t;
	while (t--) {
		//string str;
		cin >> str; ll res = 0;
		ct = 0; ll kt = 0;
		ll low = 0, high = 1e6;
		map<ll, ll> dict;
		for (i = 0; i < str.size(); i++) {
			if (str[i] == '+') kt++;
			else kt--;
			if (kt < 0) {
				j = abs(kt);
				if (dict.find(j) == dict.end()) dict.insert({j, i});
			}

		}
		while (low <= high) {
			ll mid = (low + high) / 2;
			if (check(mid) == 1) {
				ans = mid;
				high = mid - 1;
			}
			else low = mid + 1;
		}
		//for (auto it = dict.begin(); it != dict.end(); it++) cout << it->F << " " << it->S << endl;
		for (i = 0; i <= ans - 1; i++) {
			auto it = dict.find(i + 1);
			//cout << it->F << " " << it->S << endl;
			res += (it->S - 0 + 1);
		}
		res += str.size();
		cout << res << endl;
	}
	return 0;
}
