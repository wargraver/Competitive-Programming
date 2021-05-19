class Solution {
public:
    int minMoves2(vector<int>& nums) {
        long long int i,j,k,n=nums.size(),m;long long int ct=1e18;
        long long int ans = 1e18;
        sort(nums.begin(),nums.end());
        long long int left=0,right=0;
        for(i=0;i<n;i++) right+=nums[i];
        for(i=0;i<n;i++){
            right -= nums[i];
            long long int moves = (right-nums[i]*(n-i-1)) + (nums[i]*i-left);
            left += nums[i];
            ct = min(ct,moves);
        }
        return ct;
    }
};
