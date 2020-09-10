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
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	ll i, j, k, n, m, ct = 0, t, ans = 0;
	cin >> n;
	ll a[n+1]; ll max1 = 1;
	for (i = 2; i <= n; i++) {
		cout << "? " << max1 << " " << i << endl;
		cin >> k;
		cout << "? " << i << " " << max1 << endl;
		cin >> j;
		if (k < j) {
			a[i]=j;
		}
		else {
		   a[max1]=k;
			max1 = i;
		}
	}
	a[max1]=n;
	cout << "! ";
	for (i = 1; i <= n; i++) cout << a[i] << " ";
	cout << endl;

	return 0;
}
