#include<bits/stdc++.h>
using namespace std;

#define print(a)        for (auto x : a) cout << x << " "; cout << endl
#define print_upto(a,n)        for(int i=0;i<n;i++)    cout<<a[i]<<" "; cout<<endl
#define take(x,n)           for(int i=0;i<n;i++)  cin>>x[i];

#define watch(x) cout << (#x) << " is " << (x) << "\n"
#define watch2(x,y) cout <<(#x)<<" is "<<(x)<<" and "<<(#y)<<" is "<<(y)<<"\n"
#define watch3(x,y,z) cout <<(#x)<<" is "<<(x)<<" and "<<(#y)<<" is "<<(y)<<" and "<<(#z)<<" is "<<(z)<<"\n"

#define ll long long
#define ff first
#define ss second
#define null NULL
#define all(c) (c).begin(),(c).end()
#define nl "\n"

#define ld long double
#define eb emplace_back
#define pb push_back
#define pf push_front
#define mod 1000000007

typedef vector<ll> vl;
typedef vector< vl > vvl;
typedef pair< ll, ll> pll;
typedef map< ll, ll> mll;

ll mod_mul(ll a, ll b) {
	return (a * b) % mod;
}

ll mod_add(ll a, ll b) {
	return (a + b) % mod;
}

int main() {

	// Use ctrl+shift+b ( second option )
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	freopen("error.txt" , "w" , stderr);
#endif

	string s;
	cin >> s;

	ll n = s.length();
	ll tens[n + 3], sum_tens[n + 3], pref[n + 3],
	prefsum[n + 3], suff[n + 3], suffsum[n + 3];


	if (n == 1) {
		cout << "0" << nl;
		return 0;
	} else if (n == 2) {
		cout << (s[0] - '0') + (s[1] - '0') << nl;
		return 0;
	}

	tens[0] = 1, sum_tens[0] = 0;
	for (ll i = 1; i < n; i++) {
		tens[i] = mod_mul(tens[i - 1], 10ll);
		sum_tens[i] = mod_add(sum_tens[i - 1], tens[i]);
	}

	pref[0] = prefsum[0] = s[0] - '0';
	suff[n - 1] = suffsum[n - 1] = s[n - 1] - '0';

	for (ll i = 1; i < n; i++) {
		pref[i] = mod_add(mod_mul(pref[i - 1], 10), s[i] - '0');
		prefsum[i] = mod_add(prefsum[i - 1] , pref[i]);
	}

	ll p = 10;
	for (ll i = n - 2; i >= 0; i--) {
		suff[i] = mod_add(mod_mul(s[i] - '0', p) , suff[i + 1]);
		suffsum[i] = mod_add(suffsum[i + 1] , suff[i]);
		p = mod_mul(p, 10);
	}

	ll ans = 0;
	ans = mod_add(ans, suffsum[1]); //last digit included
	ans = mod_add(ans, prefsum[n - 2]); //first digit included

	for (ll i = 1; i < n - 1; i++) {
		ans = mod_add( ans ,
		               mod_add( mod_mul(pref[i - 1], sum_tens[n - i - 1]) , suffsum[i + 1] )	);
	}

	cout << ans << nl;


	return 0;
}
