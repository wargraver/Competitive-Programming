class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& a) {
      int i = 0,n;n=a.size();
	while (i < n) {
		if (a[i] == i + 1) i++;
		else {
			int k = a[i];
			int j = a[k - 1];
			if (j != k) {
				a[i] = j;
				a[k - 1] = k;
			}
			else if (j == k) {
				i++;
			}
		}
	}
        vector<int> vect;
	//for (i = 0; i < n; i++) cout << a[i] << " ";
	//cout << endl;
	for (i = 0; i < n; i++) {
		if (a[i] != i + 1) vect.push_back(i+1);
	}
    return vect;
    }
};
