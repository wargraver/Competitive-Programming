//https://codeforces.com/contest/1368/problem/B
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
    ll i, j, k, n, m, ct = 0, t, ans = 0;
    cin >> n;
    vector<pair<char, ll> > dict;
    string str = "codeforces";
    for (i = 0; i < str.size(); i++) dict.pb(mp(str[i], 1));
    j = 1; i = 0; k = 0;
    while (j < n) {
        j /= dict[i].S;
        dict[i].S++;
        j *= dict[i].S;
        k = i;
        i++;
        if (i == str.size()) i = 0;
    }
    for (i = 0; i < 10; i++) {
        for (j = 0; j < dict[i].S; j++) cout << dict[i].F;
    }
    return 0;
}
