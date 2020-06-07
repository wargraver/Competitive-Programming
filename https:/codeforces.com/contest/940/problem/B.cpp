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
	ll i, j, k, n, m, ct = 0, t, ans = 0, a, b;
	cin >> n >> k >> a >> b;
	j = n;
	if (k == 1) cout << (n-1)*a;
	else {
		while (j > 1) {
			if (j % k != 0) {
				if(j<k) ct+=((j-1)%k)*a;
				else ct += (j % k) * a;
				j -= j % k;
				//cout << ct << " " << j << endl;
			}
			else {
				ll k1 = (j - j / k) * a;
				ct += min(b, k1);
				j = j / k;
			//	cout << min(b, k1) << " " << j << endl;
			}
		}
		cout << ct << endl;
	}
	return 0;
}
