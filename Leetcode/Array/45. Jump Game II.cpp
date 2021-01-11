class Solution {
public:
    int jump(vector<int>& nums) {
        int i,j,k,n,m,ct=0;
        int curr_reach=0,curr_max=0,jump=0;
        for(i=0;i<nums.size()-1;i++){
            if(i+nums[i]>curr_max){
                curr_max=i+nums[i];
            }
            if(i==curr_reach){
                curr_reach=curr_max;
                jump++;
            }
        }
        return jump;
    }
};
