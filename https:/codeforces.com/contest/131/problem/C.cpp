//https://codeforces.com/contest/131/problem/C

#include<bits/stdc++.h>
using namespace std;
typedef unsigned long long ll;
ll inf = (ll)1e18;
ll mod = 1000000001;
ll ways(ll n, ll k) 
{ 
    ll C[n + 1][k + 1]; 
    ll i, j; 
    for (i = 0; i <= n; i++) 
    { 
        for (j = 0; j <= min(i, k); j++) 
        { 
            if (j == 0 || j == i) 
                C[i][j] = 1;
            else
                C[i][j] = C[i - 1][j - 1] + 
                          C[i - 1][j]; 
        } 
    } 
  
    return C[n][k]; 
} 
ll max1 = (ll)1e9;
int main() {
	ll i, j, k, n, m, ct = 0, t;
	ll ans = 0;
	cin >> n >> m >> t;
	k = 4;
	while (k <=n && t - k >= 1) {
		if(t-k<=m) ans += ways(n, k) * ways(m, t - k);
		k++;
	}
	cout << ans << endl;
	return 0;
