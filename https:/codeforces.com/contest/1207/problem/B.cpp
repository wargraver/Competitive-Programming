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
	cin >> n >> m;
	ll a[n][52], b[n][52];
	for (i = 0; i < n; i++) {
		for (j = 0; j < m; j++) {
			cin >> a[i][j];
			b[i][j] = 0;
		}
	}
	vector<pair<int, int>> vect;
	for (i = 0; i < n - 1; i++) {
		for (j = 0; j < m - 1; j++) {
			if (a[i][j] == 1 && a[i][j + 1] == 1 && a[i + 1][j] == 1 && a[i + 1][j + 1] == 1) {
				vect.push_back(make_pair(i + 1, j + 1));
				b[i][j] = 1; b[i + 1][j] = 1;
				b[i + 1][j + 1] = 1; b[i][j + 1] = 1;
			}
		}
	}
	for (i = 0; i < n; i++) {
		for (j = 0; j < m; j++) {
			if (a[i][j] != b[i][j]) {
				flag = 1; break;
			}
		}
	}
	if (flag == 1) cout << "-1\n";
	else {
		cout << vect.size() << "\n";
		for (i = 0; i < vect.size(); i++) cout << vect[i].first << " " << vect[i].second << "\n";
	}
	return 0;
}
