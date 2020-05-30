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
/*#ifndef ONLINE_JUDGE
	freopen("C:/Users/Utkarsh Kumar Singh/Desktop/ALL CODE/input.txt", "r", stdin);
	freopen("C:/Users/Utkarsh Kumar Singh/Desktop/ALL CODE/output.txt", "w", stdout);
	//freopen("C:/Users/Utkarsh Kumar Singh/Desktop/ALL CODE/err.txt", "w", stderr);
#endif*/
	ll i, j, k, n, m, ct = 0, t, ans = 0, flag = 1;
	ios_base::sync_with_stdio(false);
	cin >> n >> k;
	ll a[n], b[n];
	ll min1 = 1e9 + 9;
	for (i = 0; i < n; i++) cin >> a[i];
	for (i = 0; i < n; i++) {
		cin >> b[i];
		min1 = min(b[i] / a[i], min1);
	}
	//cout<<min1<<endl;
	ans = min1;
	min1++;
	while (flag !=0) {
		j = min1; ct = 0;
		for (i = 0; i < n; i++) {
			ll z = 0;
			ct += max(z, a[i] * min1 - b[i]);
		}
		if (ct <= k) ans = min1;
		else  flag=0;
		min1++;
	}
	cout<<ans<<endl;
	return 0;
}
