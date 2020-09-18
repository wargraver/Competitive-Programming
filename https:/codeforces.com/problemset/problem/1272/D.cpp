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
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    freopen("err.txt", "w", stderr);
#endif
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll i, j, k, n, m, ct = 0, t, ans = 0;
    cin >> n;
    ll a[n + 1] = {0}, b[n + 1] = {0}, c[n + 1] = {0};
    for (i = 0; i < n; i++) {
        cin >> a[i];
        if (i == 0) b[i] = 1;
        if (i != 0) {
            if (a[i - 1] >= a[i]) b[i] = 1;
            else b[i] = b[i - 1] + 1;
        }
    }
    for (i = n - 1; i >= 0; i--) {
        if (i == n - 1) c[i] = 1;
        if (i != n - 1) {
            if (a[i] >= a[i + 1]) c[i] = 1;
            else c[i] = c[i + 1] + 1;
        }
    }
    /* for (i = 0; i < n; i++) cout << b[i] << " ";
     cout << endl;
     for (i = 0; i < n; i++) cout << c[i] << " ";*/
    for (i = 0; i < n; i++) {
        if (i != 0 && i != n - 1) {
            if (a[i + 1] > a[i - 1]) ans = max(ans, c[i + 1] + b[i - 1]);
            else ans = max(ans, max(c[i + 1], b[i - 1]));
        }
        else if (i == 0) ans = max(ans, c[i + 1]);
        else if (i == n - 1) ans = max(ans, b[i - 1]);
    }
    for (i = 1; i < n; i++) if (a[i - 1] < a[i]) ct++;
    if (ct == n - 1) ans = n;
    cout << ans << endl;
    return 0;
}
