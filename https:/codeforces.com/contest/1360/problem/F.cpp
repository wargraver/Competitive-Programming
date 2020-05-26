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
	ll i, j, k, n, m, ct = 0, t, ans = 0, flag = 0;
	cin >> t;
	while (t--) {
		cin >> n >> m; flag = 0;
		vector<string> vec;
		for (i = 0; i < n; i++) {
			string str;
			cin >> str;
			vec.push_back(str);
		}
		string str = vec[0];
		for (i = 0; i < m; i++) {
			for (j = 0; j < 26; j++) {
				str[i] = 'a'; flag = 0;
				str[i] += j;
				for (k = 1; k < n; k++) {
					ct = 0;
					for (int l = 0; l < m; l++) {
						if (str[l] != vec[k][l]) ct++;
					}
					if (ct >= 2) {flag = 1; break;}
				}
				if (flag == 0) break;
			}
			if (flag == 0) break;
			str[i] = vec[0][i];
		}
		if (flag == 0) cout << str << endl;
		else cout << "-1\n";
	}


	return 0;
}
