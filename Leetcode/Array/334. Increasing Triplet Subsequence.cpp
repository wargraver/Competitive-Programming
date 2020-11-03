class Solution {
public:
    bool increasingTriplet(vector<int>& nums) {
        int k,n,m,ct=0;
        int low=INT_MAX,mid=INT_MAX;
        if(nums.size()<=2) return false;
        for(int i=0;i<nums.size();i++){
            if(nums[i]>mid) return true;
            else{
                if(nums[i]<low) low=nums[i];
                else if(nums[i]>low && mid>nums[i]) mid=nums[i];
            }
        }
        return false;
    }
};
