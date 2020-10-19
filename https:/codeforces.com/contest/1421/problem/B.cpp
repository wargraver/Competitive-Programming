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
    cin >> t;
    while (t--) {
        cin >> n;
        vector<char> ar[n];
        char ch;
        for (i = 0; i < n; i++) {
            for (j = 0; j < n; j++) {
                cin >> ch;
                ar[i].pb(ch);
            }
        }
        char v1 = ar[0][1];
        char v2 = ar[1][0];
        char v3 = ar[n - 1][n - 2];
        char v4 = ar[n - 2][n - 1];
        if (v1 == v2 && (v3 == v4) && (v1 != v3))
        {
            cout << "0\n";
        }
        else if (v1 != v2 && v3 != v4)
        {
            cout << 2 << endl;
            if (v1 == '1')
                cout << 1 << " " << 2 << endl;
            else
                cout << 2 << " " << 1 << endl;
            if (v3 == '0')
                cout << n << " " << n - 1 << endl;
            else
                cout << n - 1 << " " << n << endl;
        }
        else if (v1 == v2 && (v3 == v4) && (v1 == v3))
        {
            cout << 2 << endl;
            cout << n << " " << n - 1 << endl;
            cout << n - 1 << " " << n << endl;
        }
        else if (v1 == v2)
        {
            cout << "1\n";
            if (v3 == v1)
                cout << n << " " << n - 1 << endl;
            else
                cout << n - 1 << " " << n << endl;
        }
        else if (v3 == v4)
        {
            cout << "1\n";
            if (v1 == v3)
                cout << 1 << " " << 2 << endl;
            else
                cout << 2 << " " << 1 << endl;
        }

    }
    return 0;
}
