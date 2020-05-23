    //https://codeforces.com/problemset/problem/276/C
    #include<bits/stdc++.h>
    using namespace std;
    typedef long long ll;
    ll inf = (ll)1e18;
    ll mod = 1000000001;
    ll max1 = (ll)1e9;
    int main() {
    #ifndef ONLINE_JUDGE
    	freopen("C:/Users/Utkarsh Kumar Singh/Desktop/ALL CODE/input.txt", "r", stdin);
    	freopen("C:/Users/Utkarsh Kumar Singh/Desktop/ALL CODE/output.txt", "w", stdout);
    	//freopen("C:/Users/Utkarsh Kumar Singh/Desktop/ALL CODE/err.txt", "w", stderr);
    #endif
    	ll i, j, k, n, m, ct = 0, t, ans = 0;
    	cin >> n >> m;
    	ll a[n + 1] = {0}, b[n + 1] = {0};
    	for (i = 1; i <= n; i++) cin >> a[i];
    	for (i = 0; i < m; i++) {
    		ll l, r;
    		cin >> l >> r;
    		b[l - 1]++;
    		b[r]--;
    	}
    	for (i = 1; i <= n; i++) b[i] += b[i - 1];
    	sort(b, b + n + 1);
    	sort(a, a + n + 1);
    	for (i = 1; i <= n; i++) ans += a[i] * b[i];
    	//for (ll x : b) cout << x << " ";
    	cout << ans;
    	return 0;
    }
