#include<bits/stdc++.h>
using namespace std;
typedef int ll;
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
int binary_search(vector<int> vect, int k, int m, int find) {
	int higher = vect.size() - 1, lower = 0, ans = -1;
	while (lower <= higher) {
		int middle = (lower + higher) / 2;  
		if (vect[middle] > find) higher = middle - 1;
		else if (vect[middle] <= find) {
			ans = vect[middle];
			lower = middle + 1;
		}
	}
	return ans;
}
vector<int> interesting_index(int n, int m, vecotr<int> a, int q, int query[]) {
	map<int, int> mm;
	vector<int> vect, result;
	int i, j, k, ct = 0;
	for (i = 0; i < n; i++) {
		if (mm.find(a[i] % m) == mm.end()) mm.insert({a[i] % m, i});
		else continue;
	}
	for (auto it = mm.begin(); it != mm.end(); it++) {
		vect.push_back(it->first);
	}
	i = 0;
	while (i < q) {
		k = query[i] % m;
		int temp, find = m - k - 1, value = -1;
		int flag = binary_search(vect, k, m, find);
		if (flag != -1) {
			if (value < (k + flag) % m) {
				temp = flag;
				value = (k + flag) % m;
			}
		}
		auto it = mm.end();
		it--;
		if (value < (k + it->first) % m) {
			temp = it->first;
			value = (k + it->first) % m;
		}
		auto kt2 = mm.find(temp);
		value = kt2->second;
		result.push_back(value + 1);
		i++;
	}
	return result;
}
int main()
{
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	freopen("err.txt", "w", stderr);
#endif
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	ll i, j, k, n, m, ct = 0, Q, N, M;
	cin >> N >> M;
	int A[N];
	for (i = 0; i < N; i++) cin >> A[i];
	cin >> Q;
	int Query[Q];
	for (i = 0; i < Q; i++) cin >> Query[i];
	vector<int> vect = interesting_index(N, M, A, Q, Query);
	for (auto x : vect) cout << x << " ";
	return 0;
}
