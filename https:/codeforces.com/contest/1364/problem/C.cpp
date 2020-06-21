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
//ll max1 = (ll)1e9;
int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	freopen("err.txt", "w", stderr);
#endif
	ll i, j, k, n, m, ct = 0, t, ans = 0;
	cin >> n; ll flag = 0;
	ll a[n], b[n];
	for (i = 0; i < n; i++) b[i] = -1;
	set<ll> dict;
	for (i = 0; i < n; i++) {
		cin >> a[i];
		dict.insert(a[i]);
	}
	i = n - 1;
	while (i >= 0) {
		j = i;
		while (j >= 0 && a[j] == a[i]) {
			j--;
		}
		k = j; k++;
		if (j >= 0) b[k] = a[j];
		/*else if (j < 0) {
			if (a[i] == 0 && dict.find(1) == dict.end()) b[k] = 1;
			else if (a[i] == 0) b[k] = 1000000;
			else if (a[i] == 1) b[k] = 0;
		}*/
		i = j;
	}
	j = 0;
	for (i = 0; i < n; i++) {
		if (b[i] == -1) {
			while (dict.find(j) != dict.end()) {
				j++;
			}
			b[i] = j;
			j++;
		}
	}
	if (flag == 1) cout << "-1\n";
	else {
		set<ll> dict2;
		for (i = 0; i < n; i++) {
			dict2.insert(b[i]);
			if (dict2.find(a[i]) != dict2.end()) {
				cout << "-1\n"; return 0;
				//cout << a[i] << " " << b[i] << endl;
			}
		}
		for (i = 0; i < n; i++) cout << b[i] << " ";
	}
	return 0;
}/*1 1 3 3 5 5 7 7 8 8 9 9 10 13 15 16 17 17*/
