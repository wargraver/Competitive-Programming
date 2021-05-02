class Solution {
public:
    int getMinDistance(vector<int>& nums, int target, int start) {
        int i,j,k,n,m;
        n=nums.size();
        int ans=1e9;
        for(i=0;i<n;i++){
            if(nums[i]==target){
                ans = min(ans,abs(i-start));
            }
        }
        return ans;
    }
};
