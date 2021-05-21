class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        //Using two pointers approach,st->start pointer,en->end pointer
        int st=0,en=0,n = nums.size(), ans = 0;
        //outer loop for starting pointer
        while(st<n && en<n){
                while(k>=0 && en<n){
                    if(nums[en]==0) k--;
                    if(k<0) {en++;break;}
                    ans = max(ans,en-st+1);
                   //cout<<en<<" "<<st<<endl;
                    en++;
                }
                if(k<0) {k++;en--;}
                if(nums[st]==0) k++;
                st++;
        }
        return ans;
    }
};
