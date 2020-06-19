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
// max1 =(ll)1e9;
int main() {
#ifndef ONLINE_JUDGE
	freopen("C:/Users/Utkarsh Kumar Singh/Desktop/ALL CODE/input.txt", "r", stdin);
	freopen("C:/Users/Utkarsh Kumar Singh/Desktop/ALL CODE/output.txt", "w", stdout);
	freopen("C:/Users/Utkarsh Kumar Singh/Desktop/ALL CODE/err.txt", "w", stderr);
#endif
	ll i, j, k, n, m, ct = 0, t, ans = 0;
	cin >> n >> k;
	ll a[n], sum1 = 0;
	double max1 = 0.000000;
	for (i = 0; i < n; i++) cin >> a[i];
	for (i = 0; i < n; i++) {
		sum1 = 0;
		for (j = i; j < n; j++) {
			sum1 += a[j];
			if (j - i >= k - 1) {
				double avg = (double)sum1 / (j - i + 1);
				max1 = max(max1, avg);
			}
		}
	}
	cout << setprecision(12) << max1 << endl;
	return 0;
}
