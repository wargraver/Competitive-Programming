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
	ll i, j, k, n, m, ct = 0, t;
	string str; vector<ll> vect0, vect1;
	cin >> str; ll flag = 0;
	set<ll> dict0, dict1;
	for (i = 0; i < str.size(); i++) {
		if (str[i] == '0') dict0.in(i + 1);
		else if (str[i] == '1') dict1.in(i + 1);
	}
	//for (auto it = dict0.begin(); it != dict0.end(); it++) cout << *it << " ";
	//for (auto it = dict1.begin(); it != dict1.end(); it++) cout << *it << " ";
	vector<vector<ll>> vect;
	while (flag == 0) {
		ll last = 0;
		vector<ll> temp;
		auto it = dict0.begin(); if (it == dict0.end()) break;
		i = *it; temp.pb(i); dict0.erase(it);
		ll flag2 = 0;
		while (flag2 == 0) {
			if (last == 0) {
				auto kt = dict1.upper_bound(i);
				if (kt == dict1.end()) break;
				i = *kt;
				it = dict0.upper_bound(i);
				if (it == dict0.end()) break;
				temp.pb(*kt); dict1.erase(kt);
				//cout << i << " ";
				last = 1;
			}
			else {
				auto kt = dict0.upper_bound(i);
				if (kt == dict0.end()) break;
				temp.pb(*kt); //cout << i << " ";
				i = *kt; dict0.erase(kt);
				last = 0;
			}
		}
		//	for (i = 0; i < temp.size(); i++) cout << temp[i] << " ";
		//	cout << endl;
		vect.pb(temp);
		temp.clear();
	}
	ct = 0;
	for (i = 0; i < vect.size(); i++) {
		ct += vect[i].size();
	}
	if (ct != str.size()) cout << "-1";
	else {
		cout << vect.size() << endl;
		for (i = 0; i < vect.size(); i++) {
			cout << vect[i].size() << " ";
			for (auto x : vect[i]) cout << x << " ";
			cout << endl;
		}
	}
}
