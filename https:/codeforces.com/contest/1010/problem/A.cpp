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
	ll i, j, k, n, m, ct = 0, t;
	double ans = 0.000;
	ios_base::sync_with_stdio(false);
	cin >> n >> m;
	ll a[n], b[n];
	for (i = 0; i < n; i++) cin >> a[i];
	for (i = 0; i < n; i++) cin >> b[i];
	vector<pair<int, int>> vect;
	for (i = 0; i < n; i++) {
		vect.push_back(make_pair(b[i], a[(i + 1) % n]));
		//cout << b[i] << " " << a[(i + 1) % n] << endl;
	}
	double wt = m;
	for (i = 0; i < n; i++) {
		if (vect[i].first == 1 || vect[i].second == 1) {
			cout << "-1";
			return 0;
		}
		else {
			double x = (double)wt / (vect[i].first - 1);
			ans += x; wt += x;
			double x2 = (double)wt / (vect[i].second - 1);
			ans += x2; wt += x2;
		}
	}
	cout << setprecision(12) << ans << endl;
	return 0;
}
