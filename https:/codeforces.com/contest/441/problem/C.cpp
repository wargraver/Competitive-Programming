//https://codeforces.com/contest/441/problem/C
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
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
	cin >> n >> m >> k;
	vector<ll> vect2;
	ll length = (n * m) / k;
	for (i = 0; i < k; i++) {
		vect2.pb(length);
	}
	vect2[k - 1] += (n * m) % k;
	vector<pair<ll, ll>> vect;
	ll l = 1, row = 0, col = 0, row_end = n - 1, col_end = m - 1;
	while (l <= m * n) {
		for (i = col; i <= col_end; i++) {
			//a[row][i] = l;
			vect.pb(make_pair(row + 1, i + 1));
			l++;
		}
		row++;
		for (i = row; i <= row_end; i++) {
			//a[i][col_end] = l;
			vect.pb(make_pair(i + 1, col_end + 1));
			l++;
		}
		col_end--;
		for (i = col_end; i >= col; i--) {
			//a[row_end][i] = l;
			vect.pb(make_pair(row_end + 1, i + 1));
			l++;
		}
		row_end--;
		for (i = row_end; i >= row; i--) {
			//a[i][col] = l;
			vect.pb(make_pair(i + 1, col + 1));
			l++;
		}
		col++;
	} l = 0;
	for (i = 0; i < k; i++) {
		cout << vect2[i] << " ";
		for (j = l; j < l + vect2[i]; j++) cout << vect[j].F << " " << vect[j].S << " ";
		cout << endl;
		l += vect2[i];
	}
	return 0;
}
