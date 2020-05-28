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
ll max1 = 0;
int main() {
#ifndef ONLINE_JUDGE
	freopen("C:/Users/Utkarsh Kumar Singh/Desktop/ALL CODE/input.txt", "r", stdin);
	freopen("C:/Users/Utkarsh Kumar Singh/Desktop/ALL CODE/output.txt", "w", stdout);
	//freopen("C:/Users/Utkarsh Kumar Singh/Desktop/ALL CODE/err.txt", "w", stderr);
#endif
	ll i, j, k, n, m, ct = 0, t, ans = 0, d;
	ios_base::sync_with_stdio(false);
	cin >> n >> d;
	ll a[2 * n + 1] = {0};
	//doubling the array for a circular array
	for (i = 1; i <= n; i++) {
		cin >> a[i];
		a[n + i] = a[i];
	}
	ll sum1[2 * n + 2] = {0}, sum2[2 * n + 2] = {0};
	for (i = 1; i <= 2 * n + 1; i++) {
		sum1[i] = sum1[i - 1] + (a[i] * (a[i] + 1)) / 2;
		sum2[i] = sum2[i - 1] + a[i];
	}
	for (i = 2 * n; i >= n; i--) {
		ll low = 1, high = i; ans = i;
		while (low <= high) {
			ll mid = (low + high) / 2;
			if (sum2[i] - sum2[mid] < d) {
				ans = mid;
				high = mid - 1;
			}
			else {
				low = mid + 1;
			}
		}
		ll temp = sum2[i] - sum2[ans - 1] - d;
		ll sum = sum1[i] - sum1[ans - 1];
		sum -= (temp * (temp + 1)) / 2;
		max1 = max(max1, sum);
	}
	cout << max1 << endl;
	return 0;
}
