#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#include <bits/stdc++.h>
using namespace std;
#define fo(i,n) for(i=0;i<n;i++)
#define Fo(i,k,n) for(i=k;i<n;i++)
#define pa pair<int,int>
#define vec vector<int>
#define pb push_back
#define mp make_pair
#define F first
#define S second
#define clr(x) memset(x, 0, sizeof(x))
#define init(x, a) memset(x, a, sizeof(x))
ll inf = (ll)1e18;
ll mod = 1000000001;
ll max1 = (ll)1e9;
int main() {
#ifndef ONLINE_JUDGE
	freopen("C:/Users/Utkarsh Kumar Singh/Desktop/ALL CODE/input.txt", "r", stdin);
	freopen("C:/Users/Utkarsh Kumar Singh/Desktop/ALL CODE/output.txt", "w", stdout);
	//freopen("C:/Users/Utkarsh Kumar Singh/Desktop/ALL CODE/err.txt", "w", stderr);
#endif
	ll i, j, k, n, m, ct = 0, t, ans = 0;
	ios_base::sync_with_stdio(false);
	map<int, int> dict;
	cin >> n;
	for (i = 0; i < n; i++) {
		cin >> k;
		dict[k]++;
	}
	set<int> dict2;
	for (auto it = dict.begin(); it != dict.end(); it++) {
		if (it->first == 1) {
			dict2.insert(1);
			if (it->second >= 2) dict2.insert(2);
		}
		else {
			if (dict2.find(it->first - 1) == dict2.end()) dict2.insert(it->first - 1);
			else if (dict2.find(it->first) == dict2.end()) dict2.insert(it->first);
			else dict2.insert(it->first + 1);
			if (it->second >= 3) {
				dict2.insert(it->first);
				dict2.insert(it->first - 1);
				dict2.insert(it->first + 1);
			}
			else if (it->second == 2) {
				if (dict2.find(it->first - 1) == dict2.end()) dict2.insert(it->first - 1);
				else if (dict2.find(it->first) == dict2.end()) dict2.insert(it->first);
				else dict2.insert(it->first + 1);
			}
		}
	}
	cout << dict2.size() << endl;
	return 0;
}
