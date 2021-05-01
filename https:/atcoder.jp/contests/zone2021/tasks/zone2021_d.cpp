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
	string str;
	cin >> str;
	deque<char> st; ll flag = 0;
	for (i = 0; i < str.size(); i++) {
		if (str[i] == 'R') {
			if (flag == 0) flag = 1;
			else flag = 0;
		}
		else if (st.empty() == true) st.push_back(str[i]);
		else {
			if (flag == 0) {
				if (st.back() == str[i]) st.pop_back();
				else st.push_back(str[i]);
			}
			else {
				if (st.front() == str[i]) st.pop_front();
				else st.push_front(str[i]);
			}
		}
	}
	string str2;
	while (st.empty() == false) {
		str2 += st.back();
		st.pop_back();
	}
	if (flag == 0) reverse(str2.begin(), str2.end());
	cout << str2;
	return 0;
}
