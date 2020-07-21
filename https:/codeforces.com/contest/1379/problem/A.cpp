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
string str;
ll check(ll s, ll e) {
	if (str[s] == 'a' && str[s + 1] == 'b' && str[s + 2] == 'a' && str[s + 3] == 'c' && str[s + 4] == 'a' && str[s + 5] == 'b' && str[s + 6] == 'a') {
		return 1;
	}
	else return 0;
}
ll check2(ll s, ll e) {
	if ((str[s] == 'a' || str[s] == '?') && (str[s + 1] == 'b' || str[s + 1] == '?') && (str[s + 2] == 'a' || str[s + 2] == '?') && (str[s + 3] == 'c' || str[s + 3] == '?') && (str[s + 4] == 'a' || str[s + 4] == '?') && (str[s + 5] == 'b' || str[s + 5] == '?') && (str[s + 6] == 'a' || str[s + 6] == '?')) {
		return 1;
	}
	else return 0;
}
int main() {
	ll i, j, k, n, m, ct = 0, t, ans = 0;
	cin >> t;
	while (t--) {
		str.clear();
		cin >> n; ct = 0;
		cin >> str;
		for (i = 0; i <= n - 7; i++) {
			if (check(i, i + 6) == 1) ct++;
		}
		ll len = 0;
		if (ct >= 2 || n < 7) cout << "NO\n";
		else if (ct == 1) {
			cout << "YES\n";
			for (i = 0; i < n; i++) {
				if (str[i] == '?') cout << "d";
				else cout << str[i];
			}
			cout << "\n";
		}
		else {
			ll flag = 0;
			for (i = 0; i <= n - 7; i++) {
				ll kt = 0;
				if (check2(i, i + 6) == 1 && flag == 0) {
					vector<char> str2;
					for (k = i; k <= i + 6; k++) str2.pb(str[k]);
					for (k = i; k <= i + 6; k++) {
						if (str[k] == '?') {
							if (k == i+0 || k == i+2 || k == i+4 || k == i+6) str[k] = 'a';
							else if (k == i+1 || k == i+5) str[k] = 'b';
							else str[k] = 'c';
						}
					}
					//for(j=0;j<n;j++) cout<<str[j];
					//	cout<<endl;
						for (k = 0; k <= n - 7; k++) if(check(k, k + 6) == 1) kt++;
					//	cout<<kt<<endl;
						if (kt==1) flag = 1;
					//	else flag = 1;
						j = 0;
						if (flag == 0) {
							for (k = i; k <= i + 6; k++) {
								str[k] = str2[j];
								j++;
							}
						}
						str2.clear();
					/*	if(flag==1){
						for (j = i; j <= i + 6; j++) {
							if (str[j] == '?') {
								if (j == 0 || j == 2 || j == 4 || j == 6) str[j] = 'a';
								else if (j == 1 || j == 5) str[j] = 'b';
								else str[j] = 'c';
							}
						}}*/
					if (flag == 1) break;
				}
				if(flag==1) break;
			}
				if (flag == 1) {
					cout << "YES\n";
					for (i = 0; i < n; i++) {
						if (str[i] == '?') str[i] = 'd';
						cout << str[i];
					} cout << "\n";
				}
				else cout << "NO\n";
			}
	}
	return 0;
}
