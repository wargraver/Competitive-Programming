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
		cin >> n; //cout << n << endl;
		string str1, str2;
		vector<ll> vect1, vect2, vect3;
		cin >> str1;
		cin >> str2;
		for (i = n - 1; i >= 0; i--) {
			if (str1[i] != str2[i]) {
				//cout << n << endl;
				vect3.pb(i + 1); //cout << i + 1 << " " << 1 << " " << i + 1 << endl;
				vect3.pb(1);
				vect3.pb(i + 1);
			}
			else continue;
		}
		cout << vect3.size() << " ";
		for (i = 0; i < (ll)vect3.size(); i++) cout << vect3[i] << " ";
		cout << endl;
	}
	return 0;
}
