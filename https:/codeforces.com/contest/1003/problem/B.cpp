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
	freopen("C:/Users/Utkarsh Kumar Singh/Desktop/ALL CODE/input.txt", "r", stdin);
	freopen("C:/Users/Utkarsh Kumar Singh/Desktop/ALL CODE/output.txt", "w", stdout);
	freopen("C:/Users/Utkarsh Kumar Singh/Desktop/ALL CODE/err.txt", "w", stderr);
#endif
	ll i, j, k, n, m, ct = 0, t, ans = 0, a, b, x;
	cin >> a >> b >> x;
	vector<char> str;
	if (x % 2 == 0) {
		if (a > b) {
			for (int i = 0; i < x / 2; ++i)
				cout << "01";
			cout << string(b - x / 2, '1');
			cout << string(a - x / 2, '0');
		} else {
			for (int i = 0; i < x / 2; ++i)
				cout << "10";
			cout << string(a - x / 2, '0');
			cout << string(b - x / 2, '1');
		}
	} else if (a > b) {
		for (int i = 0; i < x / 2; ++i)
			cout << "01";
		cout << string(a - x / 2, '0');
		cout << string(b - x / 2, '1');
	} else {
		for (int i = 0; i < x / 2; ++i)
			cout << "10";
		cout << string(b - x / 2, '1');
		cout << string(a - x / 2, '0');
	}
	cout << endl;

	return 0;
}
