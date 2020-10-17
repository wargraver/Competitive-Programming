int n, b[3], dp[500];
int ways(int i,vector<int> a) {
	if (i >= n || i==-1) return 0;
	else {
		//for 1 day pass
		if (dp[i] == -1) {
			int d1 = i + 1, d2 = -1, d3 = -1;
			int fin1 = a[i] + 6, fin2 = a[i] + 29, fin3 = a[i] + 1;
			for (int k = i + 1; k < n; k++) {
				if (a[k] > fin1) {
					d2 = k;
					break;
				}
			}
			for (int k = i + 1; k < n; k++) {
				if (a[k] > fin2) {
					d3 = k;
					break;
				}
			}
			 return dp[i] = min(ways(d2,a) + b[1], min(ways(d3,a) + b[2], ways(d1,a) + b[0]));
		}
		else return dp[i];
	}
}
class Solution {
public:
    int mincostTickets(vector<int>& days, vector<int>& costs) {
        for(int i=0;i<3;i++) b[i]=costs[i];
        int i;
        n=days.size();
        memset(dp,-1,sizeof(dp));
        return ways(0,days);
        }
};
