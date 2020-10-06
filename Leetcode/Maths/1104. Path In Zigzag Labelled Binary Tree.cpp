vector<int> ways(int n){
    int i, j, k, m, ct = 0, t;
	j = n;
	int level = 0;
	vector<int> terms, vect; int ans = 1; int val = 0;
	while (n > 0) {
		n -= ans;
		val += ans;
		terms.push_back(val);
		cout << terms[level] << " ";
		level++;
		ans = ans * 2;
	}
	cout << endl;
	m = terms.size() - 1; k = j; vect.push_back(k); m--;
	while (m >= 0) {
		int val = terms[m];
		int parent = k / 2;
		parent = terms[m] - (parent - pow(2, m));
		k = parent;
		vect.push_back(parent);
		m--;
	}
	for (i = 0; i < vect.size(); i++) cout << vect[i] << " ";
    reverse(vect.begin(),vect.end());
	return vect;
}
class Solution {
public:
    vector<int> pathInZigZagTree(int label) {
        return ways(label);
    }
};
