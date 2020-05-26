#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll inf = (ll)1e18;
ll mod = 1000000001;
ll max1 = (ll)1e9;
bool isprime(int n) {
	ll ct = 0;
	for (int i = 2; i <= sqrt(n); i++) {
		if (n % i == 0) ct++;
	}
	if (ct == 0) return 1;
	else return 0;
}
int main() {
#ifndef ONLINE_JUDGE
	freopen("C:/Users/Utkarsh Kumar Singh/Desktop/ALL CODE/input.txt", "r", stdin);
	freopen("C:/Users/Utkarsh Kumar Singh/Desktop/ALL CODE/output.txt", "w", stdout);
	//freopen("C:/Users/Utkarsh Kumar Singh/Desktop/ALL CODE/err.txt", "w", stderr);
#endif
	ll i, j, k, n, m, ct = 0, t, ans = 0, val, flag = 0;
	cin >> n;
	set<int> dict;
	vector<int> vec;
	for (i = 2; i <= n; i++) if (isprime(i)) vec.push_back(i);
	for (i = 2; i <= n; i++) {
		val = i;
		vector<int> vec2;
		for (j = 0; j < vec.size(); j++) {
			ct = 0; flag = 0;
			while (val != 0 && val % vec[j] == 0) {
				ct++; flag = 1;
				val = val / vec[j];
			}
			if (flag == 1) vec2.push_back(pow(vec[j], ct));
		}
		if (vec2.size() == 1) dict.insert(vec2[0]);
		else if (vec2.size() > 1) {
			/*if (2 * i  <= n) {
				for (k = 0; k < vec2.size(); k++) dict.insert(i);
			}*/
		}
	}
	cout << dict.size() << endl;
	for (int x : dict) cout << x << " ";
	return 0;
}
