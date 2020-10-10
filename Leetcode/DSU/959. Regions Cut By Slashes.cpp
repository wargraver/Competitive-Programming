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
ll parent[8000];
ll find(ll i) {
	if (parent[i] == i) return i;
	else return find(parent[i]);
}
void union2(ll i, ll j) {
	ll x = find(i);
	ll y = find(j);
	parent[x] = y;
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
	cin >> n;
	vector<string> vect;
	for (i = 0; i < 8000; i++) parent[i] = i;
	/*for (i = 0; i < n; i++) {
		string str;
		cin >> str;
		vect.pb(str);
	}*/
	vect.pb(" /");
	vect.pb("/ ");
	for (i = 0; i < n; i++) cout << vect[i] << endl;
	ll max_root = 4 * n * n - 1;
	ll root = 0;
	for (i = 0; i < n; i++) {
		for (j = 0; j < vect[i].size(); j++) {
			if (vect[i][j] == '/') {
				union2(root, root + 1);
				union2(root + 2, root + 3);
			}
			else if (vect[i][j] == ' ') {
				union2(root + 1, root);
				union2(root + 2, root);
				union2(root + 3, root);
				cout << parent[root] << " " << parent[root + 1] << " " << parent[root + 2] << " " << parent[root + 3] << endl;
			}
			else {
				union2(root, root + 3);
				union2(root + 1, root + 2);
			}

			if (i < n - 1) union2(root + 2, root + 4 * n);
			if (j < n - 1) union2(root + 3, root + 5);
			root += 4;
		}
	}
	for (i = 0; i <= max_root; i++) {
		if (find(i) == i) ct++;
		//	cout << find(i) << " ";
	}
	cout << ct;
	return 0;
}
