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
//memset(x, 0, sizeof(x))
ll inf = (ll)1e18;
ll mod = 1e9 + 7;
ll max1 = (ll)1e9;
int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	freopen("err.txt", "w", stderr);
#endif
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	ll i, j, k, n, m, ct = 0, t, ans = 0;
	cin >> t;
	while (t--) {
		string str1, str2;
		cin >> str1 >> str2;
		i = 0; ll flag = 0; j = 0;// cout << str1[0] << " " << str2[0] << endl;
		if (str1[0] != str2[0]) flag = 1;
		while (i < str1.size()) {
			while (str1[i] == str2[j] && j < str2.size()) {
				j++;
				if (i != str1.size() - 1) {
					if (str1[i] == str1[i + 1]) break;
				}
			}
			i++;
			//	cout << i << " " << j << " " << str1[i] << " " << str2[j] << endl;
			if (i < str1.size() && j < str2.size() && str1[i] != str2[j]) flag = 1;
			if (i < str1.size() && j >= str2.size()) flag = 1;
			if (i >= str1.size() && j < str2.size()) flag = 1;
		}
		if (flag == 1) cout << "NO\n";
		else cout << "YES\n";
	}
	return 0;
}
