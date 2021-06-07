class Solution {
public:
    int totalHammingDistance(vector<int>& nums) {
        vector<vector<int>> vect;
        int i,j,k,n,m,ct=0,ans=0;
        n = nums.size()-1;
        for(i=0;i<=n;i++){
            vector<int> temp(33,0);
            k = nums[i];
            j=32;
            while(k!=0){
                int m1 = k%2;
                temp[j]=m1;
                k=k/2;
                j--;
            }
            vect.push_back(temp);
        }
        for(i=0;i<=32;i++){
            int ct0=0,ct1=0;
            for(j=0;j<=n;j++){
              if(vect[j][i]==0) ct0++;
                else ct1++;
            }
            ans += ct0*ct1;
        }
        return ans;
    }
};
