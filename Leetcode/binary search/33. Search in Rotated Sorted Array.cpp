class Solution {
public:
    int search(vector<int>& nums, int target) {
         int low=0,high=nums.size()-1;
         int i,j,k,n,m,ct=0;
        while(low<=high){
            int mid = (low+high)/2;
            if(nums[mid]==target) return mid;
            //Target is between low and mid
            else if(nums[mid]>=nums[low] && nums[mid]>target && nums[low]<=target) high=mid-1;
            else if(nums[mid]<nums[low] && (nums[low]<=target || nums[mid]>target)) high=mid-1;
            //Target is between mid and high
            else if(nums[high]>=nums[mid] && nums[high]>=target && nums[mid]<target) low=mid+1;
            else if(nums[high]<nums[mid] && (nums[mid]<target || target<=nums[low])) low=mid+1;
            else return -1;
        }
        return -1;
    }
};
