typedef int ll;
class Solution {
public:
    vector<int> partitionLabels(string str) {
    ll i, j, k, n, m, ct = 0, t, ans = 0;
	n = str.size();
	ll map[26] = {0};
	memset(map, -1, sizeof(map));
	for (i = n - 1; i >= 0; i--) {
		//cout << str[i] - 'a' << endl;
		map[str[i] - 'a'] = max(map[str[i] - 'a'], i);
	}
	vector<ll> vect;
	int max1 = -1e9;
	for (i = 0; i <= n - 1; i++) {
		ct = 1; max1 = -1e9;
		max1 = max(max1, map[str[i] - 'a']);
		while (i < n && max1 != i) {
			i++; ct++;
			max1 = max(max1, map[str[i] - 'a']);
		}
		vect.push_back(ct);
	}
	//for (i = 0; i < vect.size(); i++) cout << vect[i] << " ";
    return vect;
    }
};
