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
ll b[100005][2];
ll cost(vector<char> vect[], vector<char> rev[], ll curr, ll end, ll flag) {
	ll m = 1;
	ll n = 1;
	ll j = 1;
	ll k = 1;
	ll prev = curr - 1;
	if (vect[prev] > vect[curr]) m = 0;
	if (vect[prev] > rev[curr]) n = 0;
	if (rev[prev] > vect[curr]) j = 0;
	if (rev[prev] > rev[curr]) k = 0;
	if (flag == 1) {m = j; n = k;}
	//cout << m << " " << n << " " << curr << " " << prev << endl;
	if (curr == end) {
		if (m == 1) return 0;
		else if (n == 1) return a[curr];
		else return max1;
	}
	else if (b[curr][flag] == -1) {
		if (m == 1 && n == 1 ) return b[curr][flag] = min(cost(vect, rev, curr + 1, end, 0), a[curr] + cost(vect, rev , curr + 1, end, 1));
		else if (m == 1) return b[curr][flag] = cost(vect, rev, curr + 1, end, 0);
		else if (n == 1 ) return b[curr][flag] = a[curr] + cost(vect, rev, curr + 1, end, 1);
		else return b[curr][flag] = max1;
	}
	else return b[curr][flag];
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
	memset(b, -1, sizeof(b));
	b[0][0] = 1; b[0][1] = 0;
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
	ans = cost(vect, rev, 1, t, 0);
	if (ans >= max1) cout << "-1";
	else cout << ans << endl;
	return 0;
}
