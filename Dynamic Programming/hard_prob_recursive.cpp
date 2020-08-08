//https://codeforces.com/problemset/problem/706/C
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
ll max1 = (ll)1e18;
ll a[100005];
string str1;
ll cost(vector<char> vect[], vector<char> rev[], ll curr, ll prev, ll end, ll flag) {
	ll m = lexicographical_compare(vect[prev].begin(), vect[prev].end(), vect[curr].begin(), vect[curr].end());
	ll n = lexicographical_compare(vect[prev].begin(), vect[prev].end(), rev[curr].begin(), rev[curr].end());
	ll j = lexicographical_compare(rev[prev].begin(), rev[prev].end(), vect[curr].begin(), vect[curr].end());
	ll k = lexicographical_compare(rev[prev].begin(), rev[prev].end(), rev[curr].begin(), rev[curr].end());
	if (flag == 1) {m = j; n = k;}
	//cout << m << " " << n << " " << curr << " " << prev << endl;
	if (curr == end) {
		if (m == 1) return 0;
		else if (n == 1) return a[curr];
		else return max1;
	}
	else {
		if (m == 1 && n == 1 ) return min(cost(vect, rev, curr + 1, prev + 1, end, 0), a[curr] + cost(vect, rev , curr + 1, prev + 1, end, 1));
		else if (m == 1) return cost(vect, rev, curr + 1, prev + 1, end, 0);
		else if (n == 1 ) return a[curr] + cost(vect, rev, curr + 1, prev + 1, end, 1);
		else return max1;
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
	cin >> t;
	vector < char> vect[t + 1], rev[t + 1];
	for (i = 1; i <= t; i++) cin >> a[i];
	vect[0].pb('a'); rev[0].pb('a');
	for (i = 1; i <= t; i++) {
		string str;
		cin >> str;
		for (j = 0; j < str.size(); j++) vect[i].pb(str[j]);
		reverse(str.begin(), str.end());
		for (j = 0; j < str.size(); j++) rev[i].pb(str[j]);
	}
	ans = cost(vect, rev, 1, 0, t, 0);
	if (ans >= max1) cout << "-1";
	else cout << ans << endl;
	return 0;
}
