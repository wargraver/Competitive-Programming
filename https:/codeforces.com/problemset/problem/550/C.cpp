    //https://codeforces.com/problemset/problem/550/C
     
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
    #ifndef ONLINE_JUDGE
    	freopen("C:/Users/Utkarsh Kumar Singh/Desktop/ALL CODE/input.txt", "r", stdin);
    	freopen("C:/Users/Utkarsh Kumar Singh/Desktop/ALL CODE/output.txt", "w", stdout);
    	//freopen("C:/Users/Utkarsh Kumar Singh/Desktop/ALL CODE/err.txt", "w", stderr);
    #endif
    	ll i, j, k, n, m, ct = 0, t, ans = 0, num, flag = 0;
    	string str;
    	cin >> str;
    	//for 3 digit no
    	for (i = 0; i < str.size(); i++) {
    		num = (str[i] - '0');
    		if (num % 8 == 0) {flag = 1; break;}
    		for (j = i + 1; j < str.size(); j++) {
    			num = (str[i] - '0') * 10 + (str[j] - '0');
    			if (num % 8 == 0) {flag = 1; break;}
    			for (k = j + 1; k < str.size(); k++) {
    				num = (str[i] - '0') * 100 + (str[j] - '0') * 10 + (str[k] - '0');
    				if (num % 8 == 0) {flag = 1; break;}
    			}
    			if (flag == 1) break;
    		}
    		if (flag == 1) break;
    	}
    	if (flag == 1) cout << "YES" << endl << num << endl;
    	else cout << "NO";
    	return 0;
    }
