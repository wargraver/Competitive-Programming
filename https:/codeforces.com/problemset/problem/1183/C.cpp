#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll inf = (ll)1e18;
ll mod = 1000000001;
ll gcd(ll a, ll b) {
	if (a % b) return b;
	else return gcd(b, a % b);
}
ll max1 = (ll)1e9;
int main() {
	ll i, j, k, n, m, ct = 0, t, ans = 0, a, b;
	cin >> t;
	while (t--) {
		cin >> k >> n >> a >> b;
		if(k>n*a) cout<<n<<endl;
		else{
			k=n*a-k;
			k++;
			ll x=a-b;
			ll moves=((k+x-1)/x);
			if(moves>n) cout<<"-1\n";
			else cout<<n-moves<<"\n";
		}

	}
	return 0;
}
