//https://codeforces.com/problemset/problem/676/C
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
	//  freopen("C:/Users/Utkarsh Kumar Singh/Desktop/ALL CODE/err.txt", "w", stderr);
#endif
	ll i, j, k, n, m, ct = 0, t, ans = 0, flag = 0, l = 0;
	cin >> n >> k;
	string str;
	cin >> str;
	i = 0; j = 0; ct = 0; max1 = 0;
	while (i < str.size()) {
		flag = 0;
		if (i != 0 && str[i - 1] == 'b') ct--;
		while (i < n && j < n && ct <= k) {
			if (str[j] == 'b') ct++;
			flag = 1;
			j++;
		}
		if (ct > k) ct--, j--;
		//if(flag==1) j--;
		max1 = max(max1, (j - i));
		//cout << j - i << endl;
		i++;
	}
	i = 0; j = 0; ct = 0;
	while (i < str.size()) {
		flag = 0;
		if (i != 0 && str[i - 1] == 'a') ct--;
		while (i < n && j < n && ct <= k) {
			if (str[j] == 'a') ct++;
			flag = 1;
			j++;
		}
		if (ct > k) ct--, j--;
		//if(flag==1) j--;
		max1 = max(max1, (j - i));
		//cout << j - i << endl;
		i++;
	}
	cout << max1 << endl;
	return 0;
}
