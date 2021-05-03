class Solution {
public:
    int minAbsDifference(vector<int>& nums, int goal) {
        const int n = nums.size();

        int ans = abs(goal);
        vector<int> s1 = {0}, s2 = {0};
        
        for (int i = 0; i < (n / 2); i++) {
            const int v = s1.size();
            for (int t = 0; t < v; t++) {
                s1.push_back(s1[t] + nums[i]);
            }
        }
        
        for (int i = (n / 2); i < n; i++) {
            const int v = s2.size();
            for (int t = 0; t < v; t++) {
                s2.push_back(s2[t] + nums[i]);
            }
        }
        
        set<int> ss2(s2.begin(), s2.end());
        for (int x : s1) {
            const int y = goal - x;
            auto it = ss2.lower_bound(y);
    
            if (it != ss2.end()) {
                ans = min(ans, abs(goal - (x + *it)));

                auto it3 = it;
                it3++;
                if (it3 != ss2.end()) {
                    ans = min(ans, abs(goal - (x + *it3)));
                }
            }
            
            if (it != ss2.begin()) {
                auto it2 = it;
                it2--;

                ans = min(ans, abs(goal - (x + *it2)));
            }
        }
        return ans;
    }
};
