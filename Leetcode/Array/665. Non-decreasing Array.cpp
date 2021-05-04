class Solution {
public:
    bool checkPossibility(vector<int>& nums) {
        int count = 1;
        int min_value = INT_MIN;
        for(int i = 0; i < nums.size()-1; i++){
            if(nums[i] <= nums[i + 1]){
                min_value = nums[i];
            }else{
                if(nums[i + 1] < min_value){
                    nums[i+1] = nums[i];
                }
                count -= 1;
            }
        }
        if(count < 0){
            return false;
        }else{
            return true;
        }
    }
};
