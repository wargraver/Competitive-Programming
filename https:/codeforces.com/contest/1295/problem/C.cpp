#include<bits/stdc++.h>
using namespace std;
typedef long long  ll;
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
ll inf = (ll)1e9;
ll mod = 1e9 + 7;
ll max1 = (ll)1e9;
ll N = 100005;
ll a[100007][26];
int main() {
	ll i, j, k, n, m, ct = 0, t;
	cin >> t;
	while (t--) {
		string str1, str2;
		cin >> str1;
		cin>> str2;
		
		for (i = 0; i <str1.size()+5; i++) {
			for (j = 0; j < 26; j++) {
				a[i][j] = inf;
			}
		}
		for (i = str1.size() - 1; i >= 0; i--) {
			for (j = 0; j < 26; j++) {
				a[i][j] = a[i + 1][j];
				//minimum index for a[i][str1[i]-'a']=i;
				a[i][str1[i] - 'a'] = i;
			}
		}
		ll ans = 0, pos = 0;
		for (i = 0; i < str2.size(); i++) {
			if (pos == str1.size()) {
				pos = 0; ans++;
			}
			if (a[pos][str2[i] - 'a'] == inf) {
				pos = 0;
				ans++;
			}
			if (a[pos][str2[i] - 'a'] == inf && pos == 0) {
				ans = inf;
				 break;
			}
			pos = a[pos][str2[i] - 'a'] + 1;
		}
		if (ans >= inf) cout << "-1" << endl;
		else cout << ans+1 << endl;
	}
	return 0;
}
