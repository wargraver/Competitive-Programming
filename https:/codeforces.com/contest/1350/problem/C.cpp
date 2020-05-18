    //https://codeforces.com/contest/1350/problem/C
    #include<bits/stdc++.h>
    using namespace std;
    typedef long long ll;
    ll inf = (ll)1e18;
    ll mod = 1000000001;
    ll gcd(ll a, ll b) {
    	if (a % b==0) return b;
    	else return gcd(b, a % b);
    }
    ll max1 = (ll)1e9;
    int main() {
    	ll i, j, k, n, m, ct = 0, t, ans = 0;
    	cin >> n;
    	ll a[n], b[n];
    	for (i = 0; i < n; i++) cin >> a[i];
    	ll x = a[n - 1];
    	for (i = n - 1; i >= 0; i--) {
    		ll c = gcd(a[i], x);
    		x = c;
    		b[i] = c;
    	}
    	ll c[n];
       for(i=0;i<=n-1;i++){
       	if(i==n-1) c[i]=b[n-1];
       	else c[i]=(a[i]*b[i+1])/b[i];
       }
       for(int x:c) cout<<x<<" ";
       x=c[0];
       for(i=1;i<=n-1;i++) x=gcd(c[i],x);
       cout<<x<<endl;
    	return 0;
    }
