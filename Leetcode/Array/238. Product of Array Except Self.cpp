class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int val=1,i,j,k,n,m,ct=0;
        n=nums.size()-1;
        vector<int> vect;
        vect.push_back(val);
        for(i=1;i<=n;i++){
            val=val*nums[i-1];
            vect.push_back(val);
        }
        int val2=1;
        for(j=n;j>=0;j--){
            if(j-1>=0){
                vect[j]=vect[j]*val2;
                val2=val2*nums[j];
            }
            else{
                vect[j]=val2;
            }
        }
        return vect;
    }
};
