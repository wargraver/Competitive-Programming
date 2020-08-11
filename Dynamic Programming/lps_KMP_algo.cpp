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
ll lps[1000006] = {0};
void fill_lps(string str, ll n) {
	ll i = 1, len = 0;
	lps[0] = 0;
	while (i < n) {
		if (str[i] == str[len]) {
			len++; lps[i] = len;
			i++;
		}
		else {
			if (len == 0) { lps[i] = 0; i++; len = 0;}
			else {
				if (i < n) {
					len = lps[len - 1];
					continue;
				}
			}
		}
	}
}
int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	freopen("err.txt", "w", stderr);
#endif
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	ll i, j, k, n, m, ct = 0, t, ans = 0;
	string str;
	cin >> str;
	cout << str << endl;
	fill_lps(str, str.size());
	for (i = 0; i < str.size(); i++) cout << lps[i] << " ";
	return 0;
}
