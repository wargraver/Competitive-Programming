class Solution {
public:
    void sortColors(vector<int>& a) {
        int i=0,ct2=a.size()-1,ct0=0,j;
        while (i <= ct2 && ct0 < ct2) {
		if (a[i] == 0) {
			a[i] = a[ct0];
			a[ct0] = 0;
			ct0++;
		}
		if (a[i] == 2) {
			a[i] = a[ct2];
			a[ct2] = 2;
			ct2--;
			if (a[i] == 0) {
				a[i] = a[ct0];
				a[ct0] = 0;
				ct0++;
			}
            else i--;
			//for (j = 0; j < n; j++) cout << a[j] << " ";
			//cout << endl;

		} i++;
	}
    }
};
