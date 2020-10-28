typedef int ll;
class Solution {
public:
    int minSumOfLengths(vector<int>& a, int k) {
        ll inf=1e9;
    ll i, j, n, m, ct = 0, t, ans = 0;
        n=a.size();
	ll pref[200000], p1[n+5], p2[n+5];
    memset(pref,0,sizeof(pref));
	for (i = 1; i <= n; i++) pref[i] += (pref[i - 1] + a[i - 1]);
	pref[n + 1] = pref[n];
	ll min_length = inf;
	p1[0] = inf; p1[1] = inf;
	//for (i = 0; i <= n; i++) cout << pref[i] << " ";
	cout << endl;
	for (i = 1; i <= n + 1; i++) {
		ll low = 0, high = i;
		ans = inf;
		if (pref[i] - k >= 0) {
			//cout << pref[i] << " " << pref[i - 1] - k << endl;
			while (low <= high) {
				ans = inf;
				ll mid = (low + high) / 2;
				if (pref[mid] < pref[i] - k) {
					low = mid + 1;
				}
				else if (pref[mid] == pref[i] - k) {
					ans = i  - mid; break;
				}
				else high = mid - 1;
			}
		}
		p1[i] = min(ans, p1[i - 1]);
	}
	for (i = 0; i <= n + 1; i++) cout << p1[i] << " ";
	p2[n + 1] = inf;
	for (i = n; i >= 0; i--) {
		ll low = i, high = n;
		ans = inf;
		while (low <= high) {
			ll mid = (low + high) / 2;
			if (pref[mid] < pref[i] + k) {
				low = mid + 1;
			}
			else if (pref[mid] == pref[i] + k) {
				ans = mid - i;
				break;
			}
			else high = mid - 1;
		}
		p2[i] = min(ans, p2[i + 1]);
	}
	cout << endl;
	for (i = 0; i <= n ; i++) cout << p2[i] << " ";
	ans = inf;
	for (i = 0; i <= n; i++) {
		if (p1[i] != inf && p2[i] != inf) {
			ans = min(p1[i] + p2[i], ans);
		}
	}
	if (ans == inf) cout << "-1";
	else cout << ans;
    if(ans==inf) return -1;
    else return ans;
    }
};
