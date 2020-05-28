#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
using namespace std;
#define fo(i,n) for(i=0;i<n;i++)
#define Fo(i,k,n) for(i=k;i<n;i++)
#define pa pair<int,int>
#define vec vector<int>
#define pb push_back
#define mp make_pair
#define F first
#define S second
#define clr(x) memset(x, 0, sizeof(x))
#define init(x, a) memset(x, a, sizeof(x))
ll inf = (ll)1e18;
ll mod = 1000000001;
ll max1 = (ll)1e9;
int main() {
#ifndef ONLINE_JUDGE
	freopen("C:/Users/Utkarsh Kumar Singh/Desktop/ALL CODE/input.txt", "r", stdin);
	freopen("C:/Users/Utkarsh Kumar Singh/Desktop/ALL CODE/output.txt", "w", stdout);
	//freopen("C:/Users/Utkarsh Kumar Singh/Desktop/ALL CODE/err.txt", "w", stderr);
#endif
	ll i, j, k, n, m, ct = 0, t, ans = 0, flag = 0;
	ios_base::sync_with_stdio(false);
	cin >> n;
	string str;
	cin >> str;
	set<char> dict1;
	map<char, int> dict;
	for (i = 0; i < n; i++) dict1.insert(str[i]);
	k = dict1.size();
	//cout << k << endl;
	ll a[n];
	for (i = 0; i < n; i++) a[i] = mod;
	//for (ll x : a) cout << x << " ";
	j = 0; i = 0;
	while (i < n) {
		if (i - 1 >= 0) dict[str[i - 1]]--;
		if (dict[str[i - 1]] == 0) dict.erase(str[i - 1]);
		while (i < n && j < n && dict.size() != k) {
			dict[str[j]]++;
			j++;
			flag = 1;
		}
		if (dict.size() == k) a[i] = j - i;
		flag = 0;
		i++;
	}
	ll min1 = mod;
	for (ll x : a) min1 = min(min1, x);
	cout << min1 << endl;
	return 0;
}
