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
	freopen("C:/Users/Utkarsh Kumar Singh/Desktop/ALL CODE/input.txt", "r", stdin);
	freopen("C:/Users/Utkarsh Kumar Singh/Desktop/ALL CODE/output.txt", "w", stdout);
	freopen("C:/Users/Utkarsh Kumar Singh/Desktop/ALL CODE/err.txt", "w", stderr);
#endif
	ll i, j, k, n, m, ct = 0, t, ans = 0;
	cin >> t;
	while (t--) {
		string str;
		cin >> str;
		cin >> n;
		vector<pair<ll, ll>> vect;
		for (i = 0; i < n; i++) {
			cin >> k;
			vect.pb(make_pair(k, i));
		}
		vector<ll> vect3;
		map<char, ll> dict;
		map<ll, char> dict2;
		for (i = 0; i < str.size(); i++) dict[str[i]]++;
		i = 0; j = 0; k = 0;
		auto it2 = dict.end();
		it2--;
		while (dict2.size() != n) {
			vect3.clear();
			for (i = 0; i < vect.size(); i++) {
				if (vect[i].F == 0) {
					//dict2.insert({i, it2->F});
					vect3.pb(vect[i].S);
					//vect[i].F = -1;
				}
			}
			ll z = vect3.size();
			while (z > it2->S) it2--;
			for (i = 0; i < vect.size(); i++) {
				if (vect[i].F == 0) {
					dict2.insert({i, it2->F});
					vect[i].F = -1;
				}
			}
			for (i = 0; i < vect3.size(); i++) {
				for (k = 0; k < n; k++) {
					if (vect[k].F > 0) vect[k].F -= abs(vect[k].S - vect3[i]);
				}
			}
			it2--;
		}
		for (i = 0; i < n; i++) cout << dict2[i];
		cout << endl;
	}
	return 0;
}
