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
	freopen("C:/Users/Utkarsh Kumar Singh/Desktop/ALL CODE/input.txt", "r", stdin);
	freopen("C:/Users/Utkarsh Kumar Singh/Desktop/ALL CODE/output.txt", "w", stdout);
	freopen("C:/Users/Utkarsh Kumar Singh/Desktop/ALL CODE/err.txt", "w", stderr);
#endif
	ll i, j, k, n, m, ct = 0, t, ans = 0;
	string str;
	cin >> n >> m;
	cin >> str;
	//cout << str;
	ll a[26] = {0};
	i = 0; j = 0; k = 0; ll flag = 0;
	while (i < str.size() && j < n) {
		ct = 0; flag = 0;
		while (j < n && str[j] == str[i]) {
			j++;
			flag = 1;
			ct++;
		}
		t = str[i] - 'a';
		a[t] += ct / m;
		if (flag == 0) {i++; j = i;}
		else i = j;
	}
	ll max1 = 0;
	for (i = 0; i < 26; i++) max1 = max(max1, a[i]);
	cout << max1;
	return 0;
}
