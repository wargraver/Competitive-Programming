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

//	ios_base::sync_with_stdio(false);
//	cin.tie(NULL);
	ll i, j, k, n, m, ct = 0, t, ans = 0;
	cin >> t;
	while (t--) {
		ll max_sum =100, min_sum = 1;
		cin >> n; ll wt;
		ll a[n]; ans = 0; //cout << n << endl;
		for (i = 0; i < n; i++) cin >> a[i];
		ll b[105]={0};
		for (i = 0; i < n; i++) b[a[i]]++;
		for ( wt = 1; wt <= max_sum; wt++) {
			ct=0;ll c[400]={0};
		for(i=0;i<n;i++){
				ll val=a[i];
				ll diff=wt-val;
			    if(diff>=0 && c[a[i]]==0 && c[diff]==0){
			    	if(a[i]==diff) ct+=min(b[a[i]],b[diff])/2;
			    	else ct+=min(b[a[i]],b[diff]);
			    	c[a[i]]=1;c[diff]=1;
				}
				else continue;
			}
			ans = max(ans, ct);
			}
		cout << ans << endl;
	}
	return 0;
}
