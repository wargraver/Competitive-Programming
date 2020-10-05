int ways(int a[], int i, int n, int m) {
	if (i >= n) return 0;
	else {
		int st = i, en = min(n - 1, i + 2 * m - 1);
		int sum = 0, max3 = 0;;
		for (int j = st; j <= en; j++) {
			int max2 = 0;
			sum += a[j]; int ans  = sum;
			int taken = j - st + 1;
			int skip = max(m, taken);
			int end = min(n, j + 2 * skip + 1);
			//cout << st << " " << k << " " << skip << endl;
			max2 = max(max2, ways(a, end, n,2 * skip));
			//cout << ways(a, i + k + 1, n, skip) << " " << i + k + 1 << " " << endl;
			ans += max2;
			max3 = max(ans, max3);
		}
		return max3;
	}
}
class Solution {
public:
    int stoneGameII(vector<int>& piles) {
        int a[piles.size()];
        for(int i=0;i<piles.size();i++) a[i]=piles[i];
        return ways(a,0,piles.size(),1);
    }
};
