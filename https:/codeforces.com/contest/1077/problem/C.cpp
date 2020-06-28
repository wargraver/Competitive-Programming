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
/*#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	freopen("err.txt", "w", stderr);
#endif*/
	ll i, j, k, n, m, ct = 0, t, ans = 0;
	cin >> n;
	ll a[n], sum1 = 0;
	set<ll> dict2;
	multimap<ll, ll> dict;
	for (i = 0; i < n; i++) {
		cin >> a[i];
		sum1 += a[i];
		dict.insert({a[i], i});
	}
	auto it = dict.end();
	it--;
	while (it != dict.begin()) {
		ll c1 = it->F;
		k = sum1 - c1;
		if (dict.find(sum1 - 2 * c1) != dict.end()) {
			auto kt = dict.find(sum1 - 2 * c1);
			while (kt!=dict.end() &&kt->F==sum1 - 2 * c1)  {
				if (kt!=it && sum1 - kt->F - c1 == c1) {
					dict2.insert(kt->second);
					kt++;
				}
				//cout << kt->first << " " << kt->second << " ";
				else kt++;
				//cout << kt->first << endl;
			}
		}
		it--;
	}
	cout << dict2.size() << endl;
	for (auto it2 = dict2.begin(); it2 != dict2.end(); it2++) cout << *it2 + 1 << " ";
	return 0;
}
