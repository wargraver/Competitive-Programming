class Solution {
public:
    int tupleSameProduct(vector<int>& nums) {
        int i,j,k,n,m,ct=0,ans=0;
        n=nums.size();
       map<int,int> dict;
            for(i=0;i<n;i++){
                for(j=i+1;j<n;j++){
                    dict[nums[i]*nums[j]]++;
                }
            }
        for(i=0;i<n;i++){
            for(j=i+1;j<n;j++){
                ct=0;
                ct=dict[nums[i]*nums[j]];
                dict.erase(nums[i]*nums[j]);
                int val=1;
                ct--;
                int pairs=ct*(ct+1)/2;
                ans+=pairs*8;
            }
        }
        return ans;
    }
};
